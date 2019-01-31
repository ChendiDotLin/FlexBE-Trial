#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <test_actionlib/testAction.h>

class TestAction
{
	protected:
		ros::NodeHandle nh;
		actionlib::SimpleActionServer<test_actionlib::testAction> ta;
		std::string action_name;
		test_actionlib::testFeedback feedback;
		test_actionlib::testResult result;

	public:
		TestAction(std::string name) : 
			//this sets the topic it's listening on to the name of the input string
			ta(nh, name, boost::bind(&TestAction::test_cb, this, _1), false),
			action_name(name)
		{
			ta.start();
		}

		~TestAction(void)
		{
		}

		void test_cb(const test_actionlib::testGoalConstPtr &goal)
		{
			//show that the goal was recieved
			ROS_INFO("%s: Recieved a goal msg will do something for a while now...", action_name.c_str());

			//start the action
			//blah blah blah
			//
			//we just want to check that flexbe can talk with the server
			//

			//feedback to show that this works 
			feedback.test_feedback = 100;
			ta.publishFeedback(feedback);

			//send out the result of the test actionlib server
			result.test_result = "test 124";
			ROS_INFO("%s: Succeeded awesome!",action_name.c_str());
			ta.setSucceeded(result);
		}
};

int main(int argc, char** argv)
{
	ros::init(argc, argv, "test_action");

	TestAction testaction("test_action");
	ros::spin();

	return 0;
}



