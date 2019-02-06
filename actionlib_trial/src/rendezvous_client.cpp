#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <actionlib_trial/RendezvousAction.h>

using namespace actionlib_trial;
typedef actionlib::SimpleActionClient<RendezvousAction> Client;

// goal completed
void doneCb(const actionlib::SimpleClientGoalStates& state,
			const RendezvousResult& result){
	ROS_INFO("Done");
	ros::shutdown();
}

void activeCb()
{
  ROS_INFO("Goal just went active");
}

// Called every time feedback is received for the goal
void feedbackCb(const RendezvousFeedbackConstPtr& feedback)
{
  ROS_INFO("Got Feedback of length %lu", feedback->sequence.size());
}

int main (int argc, char **argv)
{
  ros::init(argc, argv, "test_rendezvous_callback");

  // Create the action client
  Client ac("rendezvous", true);

  ROS_INFO("Waiting for action server to start.");
  ac.waitForServer();
  ROS_INFO("Action server started, sending goal.");

  // Send Goal
  RendezvousGoal goal;
  goal.dist = 2;
  ac.sendGoal(goal, &doneCb, &activeCb, &feedbackCb);

  ros::spin();
  return 0;
}