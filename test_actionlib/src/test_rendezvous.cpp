// Stuff for ros and actionlib stuffs
#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
// Include the action msg being used for this server
#include <test_actionlib/rendezvousAction.h>

// The stuff for the curlpp stuff to deal with the getting and sending http msgs
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <sstream>
#include <iostream>

// Stuff used to parse and create JSON msgs to use with the http stuffs
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>

// Stuff for calculations like sqrt and pow
#include <cmath>

class TestRendezvous
{
	protected:
		// Setting up some stuff that will be needed by the callback and constructor 
		ros::NodeHandle nh;
		actionlib::SimpleActionServer<test_actionlib::rendezvousAction> rv;
		std::string action_name;
		test_actionlib::rendezvousFeedback feedback;
		test_actionlib::rendezvousResult result;

	public:
		// This constructor creates the topic name and starts the server
		TestRendezvous(std::string name) :
			rv(nh, name, boost::bind(&TestRendezvous::rendezvous_cb, this, _1), false), action_name(name)
		{
			// Once the constuctor is called in the main loop it will start the server, which will wait for the goal cb to be triggered. 
			rv.start();
		}

		// The destructor
		~TestRendezvous(void)
		{
		}

		// The call back that will run the rendezvous code
		void rendezvous_cb(const test_actionlib::rendezvousGoalConstPtr &goal)
		{

			// Get the goal msg. 
			double goal_distance = goal->goal_dist;
			// Get current time so we can get the time elapsed
			ros::Time start_time = ros::Time::now();
			// Let the user know that the server callback has started
			ROS_INFO("%s: Recieved a goal msg will do something for a while now...", action_name.c_str());

			// First lets get information about the swarm.
			// Lets get the number of robots in the swarm
			// Setup the json parsing stuffs
			Json::Value rbPos;
			Json::Reader Reader;
			std::ostringstream in_rb;
			in_rb << curlpp::options::Url("http://localhost:1234/Vehicle/Position/Length"); 
			Json::Value rbVal;
			int num_rb;
			if(Reader.parse(in_rb.str(),  rbVal)){
				std::cout << "Parsing number of robots succeeded!!" << std::endl;
				num_rb = rbVal["length"].asInt();
				std::cout << num_rb << std::endl;
			}else{
				std::cout << "Parsing number of robots failed!!" << std::endl;
				std::cout << in_rb.str() << std::endl;
			}

			// This is the simplified rendezvous code to be used with the NG simulator.
			// Get the center of the current rb swarm 
			std::ostringstream in_pos;
			in_pos << curlpp::options::Url("http://localhost:1234/Vehicle/Position/XYZ/ALL");
			// If the json data was parsed it will print it out nicely to terminal otherwise it will try to show the raw data
			if(Reader.parse(in_pos.str(),  rbPos)){
				std::cout << "Parsing robot position was succeeded!!" << std::endl;
				std::cout << "\nJSON data recieved" << std::endl;
				std::cout << rbPos.toStyledString() << std::endl;
			}else{
				std::cout << "Failed something's funky..." << std::endl;
				std::cout << "\nThe data recieved is " << in_pos.str() << std::endl;
			}

			// Calculate the center of the swarm
			double totX = 0, totY = 0, totZ = 0;
			for(int a = 0; a < num_rb; a++)
			{
				totX += rbPos[a]["x"].asDouble();
				totY += rbPos[a]["y"].asDouble();
				totZ += rbPos[a]["z"].asDouble();
			}
			double cenX = 0, cenY = 0, cenZ = 0;
			cenX = totX / num_rb;
			cenY = totY / num_rb;
			cenZ = totZ / num_rb;

			// Creating the JSON object 
			Json::Value positions;
			for(int n = 0; n < num_rb; n++)
			{
				positions[n]["id"] = n;
				positions[n]["x"] = cenX; 
				positions[n]["y"] = cenY;
				positions[n]["z"] = cenZ;
			}
			Json::Value margs;
			margs["speed"] = 10;
			margs["distThresh"] = (int)goal_distance;
			Json::Value output;
			output["positions"] = positions;
			output["MovArgs"] = margs;
			// Print out the JSON to make sure that it looks like what it should be 
			//std::cout << output.toStyledString() << std::endl;
			curlpp::Easy multi;
			std::list<std::string> header;
			Json::FastWriter fw;
			std::string multi_out = fw.write(output);
			std::cout << multi_out << std::endl;
			header.push_back("Content-Type: application/json");
			multi.setOpt(new curlpp::options::Url("http://localhost:1234/Vehicle/Position/XYZ/Multi"));
			multi.setOpt(new curlpp::options::HttpHeader(header));
			multi.setOpt(new curlpp::options::PostFields(multi_out));
			multi.setOpt(new curlpp::options::PostFieldSize(multi_out.length()));
			// Setup the response stream to check what the server replies with
			std::ostringstream resp;
			multi.setOpt(new curlpp::options::WriteStream(&resp));
			std::cout << output.toStyledString() << std::endl;
			// Oh lord of JSON, curl, c++, and unity please let this work
			multi.perform();
		
			// Output the response to terminal
			Json::Value response;
			if(Reader.parse(resp.str(),  response)){
				std::cout << "Response to trying to move rb2" << std::endl;
				std::cout << response.toStyledString() << std::endl;
			}
			else{
				std::cout << "Response failed somethings funky" << std::endl;
				std::cout << "\nThe data recieved is " << resp.str() << std::endl;
			}

			ros::Duration elapsed_time = ros::Time::now() - start_time;
			ros::Time eTime(elapsed_time.toSec());
			result.completed = true;
			result.num_rb = num_rb;
			result.stamp = eTime;
			result.point.x = cenX;
			result.point.y = cenY;
			result.point.z = cenZ;

			rv.setSucceeded(result);




			//	the code below was a failed attempt at trying to directly impliment the rendezvous code as it was originally. 
			//	However given the limitations of the NG simulator we have decided to stop this until they impliment ros2 in the hopes that we can use ros msgs to control the rbs in the future.
			//
			//
			//
			//
			//
		//	bool minDistReached = false;
		//	while(!minDistReached)
		//	{
		//	

		//		// Now lets the the current positional data of all the robots
		//		std::ostringstream in_pos;
		//		in_pos << curlpp::options::Url("http://localhost:1234/Vehicle/Position/XYZ/ALL");
		//		// Setup the json parsing stuffs
		//		Json::Value rbPos;
		//		Json::Reader Reader;
		//		// If the json data was parsed it will print it out nicely to terminal otherwise it will try to show the raw data
		//		if(Reader.parse(in_pos.str(),  rbPos)){
		//			std::cout << "Parsing robot position was succeeded!!" << std::endl;
		//		}else{
		//			std::cout << "Failed something's funky..." << std::endl;
		//			std::cout << "\nThe data recieved is " << in_pos.str() << std::endl;
		//		}

		//		// Time for some calculations to find the output velocity for each rb. We will not worry about barrier certificates as the simulator has the distTresh parameter that keeps the rbs from bumping into each other.
		//		double connectivity_radius = 20;				// This value sets the radius of interest, so if a rb is outside of it we don't care about it and will leave it alone.
		//		double cur_avg_distances[num_rb] = {0};
		//		int n_rb = 0; 						// The number or rb in the conectivity radius
		//		Json::Value rbVel;						// The JSON object that will hold all the resulting rb velocities	
		//		
		//		// Cycle through the whole set of rbs and compare its position to every other rb.
		//		for(int curr_index = 0; cur_index < num_rb; curr_index++),
		//		{
		//			// These are values used too hold values we wand like distance and velocity. Initilized to 0 cuz we don't want our rb to jet off somewherer all the sudden at first. Unless you want to lose money, time, and your job...then be my guest. 
		//			double d[3] = {0}, _v[3] = {0}, v[3] = {0}, norm_dist = 0, tot_dist = 0;	
		//			for(int rb_id = 0; rb_id < num_rb ; rb_id++)
		//			{
		//				d[0] = rbPos[rb_id]["x"].asDouble() - rbPos[curr_index]["x"].asDouble();
		//				d[1] = rbPos[rb_id]["y"].asDouble() - rbPos[curr_index]["y"].asDouble();
		//				d[2] = rbPos[rb_id]["z"].asDouble() - rbPos[curr_index]["z"].asDouble();
		//				norm_dist = sqrt(pow(d[0],2) + pow(d[1],2) + pow(d[2],2));

		//				// Check if care about this distance
		//				if(norm_dist < connectivity_radius)
		//				{
		//					_v[0] = d[0];
		//					_v[1] = d[1];
		//					_v[2] = d[2];
		//					tot_dist += norm_dist;
		//					n_rb += 1; 
		//				}else{
		//					_v[0] = 0;
		//					_v[1] = 0;
		//					_v[2] = 0;
		//				}
		//				v[0] += _v[0];
		//				v[1] += _v[1];
		//				v[2] += _v[2];
		//			}
		//			v[0] = v[0] / n_rb;
		//			v[1] = v[1] / n_rb;
		//			v[2] = v[2] / n_rb;
		//			cur_avg_distances[curr_index] = tot_dist / (n_rb + 1);
		//			
		//			// Put the resulting rb vel into a JSON object
		//			rbVel[curr_index]["id"] = curr_index;
		//			rbVel[curr_index]["x"] = v[0];
		//			rbVel[curr_index]["y"] = v[1];
		//			rbVel[curr_index]["z"] = v[2];
		//		}

		//		// Get current avg distance
		//		double total_dist = 0, cur_avg_distance = 0;
		//		for(int a = 0; a < n_rb; a++)
		//		{
		//			total_dist += cur_avg_distances[a];
		//		}
		//		cur_avg_distance = total_dist / n_rb;

		//		// Now lets send this sucker!
		//		// Convert the JSON object into a string to send
		//		Json::FastWriter fw;
		//		std::string rbVelOut = fw.write(rbVel);
		//		// Create the http msg to send out
		//		curllpp::Easy velOut;
		//		std::list<std::string> header;
		//		header.push_back("Content-Type: application/json");
		//		velOut.setOpt(new curlpp::options::Url("http://localhost:1234/Vehicle/Position/AddVelocity")
		//		velOut.setOpt(new curlpp::options::HttpHeader(header));
		//		velOut.setOpt(new curlpp::options::PostFields(rbVelOut));
		//		velOut.setOpt(new curlpp::options::PosrFieldSize(rbVelOut.length()));			
		//		std::ostringstream in_resp;
		//		velOut.setOpt(new curlpp::options::WriteStream(&in_resp));
		//		// Oh lord of everything code please bless this message
		//		velOut.perform();

		//		// Now parse the response
		//		Json::Value response;
		//		
		//		if(testReader.parse(in_resp.str(),  response)){
		//			std::cout << "Response to rendezvous" << std::endl;
		//			std::cout << response.toStyledString() << std::endl;
		//		}
		//		else{
		//			std::cout << "Response failed somethings funky" << std::endl;
		//			std::cout << "\nThe data recieved is " << in_resp.str() << std::endl;
		//		}

		//		// Send out the feedback
		//		feedback.avg_real_dist = cur_avg_distance;
		//		feedback.num_rb = num_rb;
		//		feedback.stamp = ros::Time::now() - s_time; 


		//	}
		}


};


int main(int argc, char** argv)
{
	// Initialize ros and start the server
	ros::init(argc, argv, "test_rendezvous");
	TestRendezvous testrendezvous("test_rendezvous");
	ros::spin();

	return 0;
	
}
