#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <test_actionlib/testAction.h>

using namespace test_actionlib;
typedef actionlib::SimpleActionClient<testAction> Client;

void doneCb(const test_actionlib::SimpleClientGoalStates& state,
			const testActionResult& result){
	ROS_INFO("Done");
	ros::shutdown();
}

void activeCb()
{
  ROS_INFO("Goal just went active");
}

// Called every time feedback is received for the goal
void feedbackCb(const testActionFeedbackConstPtr& feedback)
{
  ROS_INFO("Got Feedback of length %lu", feedback->sequence.size());
}

int main (int argc, char **argv)
{
  ros::init(argc, argv, "test_action_callback");

  // Create the action client
  Client ac("testAction", true);

  ROS_INFO("Waiting for action server to start.");
  ac.waitForServer();
  ROS_INFO("Action server started, sending goal.");

  // Send Goal
  testGoalConstPtr goal;
  goal.result = "okok";
  ac.sendGoal(goal, &doneCb, &activeCb, &feedbackCb);

  ros::spin();
  return 0;
}
