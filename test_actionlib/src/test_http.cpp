#include <sstream>
#include <iostream>
#include <stdlib.h>

#include <ros/ros.h>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>

int main(int argc, char** argv)
{
	curlpp::Cleanup myCleanup;

	// Just trying to get data then print it to terminal 
	//std::cout << curlpp::options::Url("http://localhost:1234/Vehicle/Position/XYZ/ALL");

	// Try to put the output from the http request into a string and then parse that to print it more legibly
	// Most of this stuff was taken/based off of stuff I found at these places:
	// https://gist.github.com/connormanning/41efa6075515019e499c
	// https://github.com/jpbarrette/curlpp/blob/master/examples/
	// https://stackoverflow.com/questions/41958236/posting-and-receiving-json-payload-with-curlpp
	std::ostringstream test;
	test << curlpp::options::Url("http://localhost:1234/Vehicle/Position/XYZ/ALL");
	// Setup the json parsing stuffs
	Json::Value testVal;
	Json::Reader testReader;
	// If the json data was parsed it will print it out nicely to terminal otherwise it will try to show the raw data
	if(testReader.parse(test.str(),  testVal)){
		std::cout << "Test parse was successful" << std::endl;
		std::cout << "\nJSON data recieved" << std::endl;
		std::cout << testVal.toStyledString() << std::endl;
		// Now to get to each bit of data individually
		std::cout << "Print just info for robot 1\n" << std::endl;
		std::cout << testVal[1] << std:: endl;
		std::cout << "Print rb1 x position\n" << std::endl;
		std::cout << testVal[1]["x"] << std::endl;
		Json::Value rb1Val = testVal[1];
		std::cout << "Print just 'x' info for robot 1\n" << std::endl;
		std::cout << rb1Val["x"] << std::endl;
	}
	else{
		std::cout << "Test failed somethings funky" << std::endl;
		std::cout << "\nThe data recieved is " << test.str() << std::endl;
	}

	/*
	 * Move just one rb 
	// Now try to move rb2 somewhere else we don't care just somewhere else
	int x = testVal[1]["x"].asInt()+10;
	int y = testVal[1]["y"].asInt()+20;	 
	int z = testVal[1]["z"].asInt()+10;	 
	Json::Value movargs;
	movargs["speed"] = 10;
	movargs["distThresh"] = 1;
	Json::Value goal;
	goal["id"] = 2;
	goal["MovArgs"] = movargs;
	goal["x"] = x;
	goal["y"] = y;
	goal["z"] = z;
	std::cout << "Test of JSON msg going out to move rb 2\n" << std::endl;
	std::cout << goal.toStyledString() << std::endl;
	// Now to send it out
	curlpp::Easy meh;
	std::list<std::string> header; // tbh I have no idea why they do this in the example code...
	// The writer is used to convert the JSON data into a string that we can send to the server
	Json::FastWriter fw;
	// I originally tried to put the fw.write() inside the PostFields directly but that didn't work so doing it like this
	std::string test_out = fw.write(goal);
	// Show the version being sent to the server
	std::cout << test_out  << std::endl;
	// Filling out the output msg
	header.push_back("Content-Type: application/json");
	meh.setOpt(new curlpp::options::Url("http://localhost:1234/Vehicle/Position/XYZ/Single"));
	meh.setOpt(new curlpp::options::HttpHeader(header));
	meh.setOpt(new curlpp::options::PostFields(test_out));
	meh.setOpt(new curlpp::options::PostFieldSize(test_out.length()));
	// Setup the response stream 
	std::ostringstream resp;
	meh.setOpt(new curlpp::options::WriteStream(&resp));
	// Pray to the C++ god(s) that this works
	meh.perform();

	// Format response so it looks nice in terminal
	Json::Value res;
	if(testReader.parse(resp.str(),  res)){
		std::cout << "Response to trying to move rb2" << std::endl;
		std::cout << res.toStyledString() << std::endl;
	}
	else{
		std::cout << "Response failed somethings funky" << std::endl;
		std::cout << "\nThe data recieved is " << resp.str() << std::endl;
	}
	*/

	// Try to move multiple rb at the same time
	// First get the number of robots in the simulator.
	std::ostringstream in_rb;
	in_rb << curlpp::options::Url("http://localhost:1234/Vehicle/Position/Length"); 
	Json::Value rbVal;
	int num_rb;
	//std::cout << in_rb.str() << std::endl;
	if(testReader.parse(in_rb.str(),  rbVal)){
		num_rb = rbVal["length"].asInt();
	}
	//std::cout << num_rb << std::endl;

	// Now try to sorta not really randomly set each new position based on their current and what their index is
	srand (time(NULL));
	Json::Value positions;
	for(int n = 0; n < num_rb; n++)
	{

		positions[n]["id"] = n;
		int randx = rand() % 11 + (-10);
		positions[n]["x"] = testVal[n]["x"].asInt()+randx;
		int randy = rand() % 11 + (-10);
		positions[n]["y"] = testVal[n]["y"].asInt()+randy;
		int randz = rand() % 11 + (-10);
		positions[n]["z"] = testVal[n]["z"].asInt()+randz;
	}
	Json::Value margs;
	margs["speed"] = 1;
	margs["distThresh"] = 1;
	Json::Value output;
	output["positions"] = positions;
	output["MovArgs"] = margs;
	// Print out the JSON to make sure that it looks like what it should be 
	//std::cout << output.toStyledString() << std::endl;

	// Create the http msg to send out
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
	if(testReader.parse(resp.str(),  response)){
		std::cout << "Response to trying to move rb2" << std::endl;
		std::cout << response.toStyledString() << std::endl;
	}
	else{
		std::cout << "Response failed somethings funky" << std::endl;
		std::cout << "\nThe data recieved is " << resp.str() << std::endl;
	}

	return 0;
}
