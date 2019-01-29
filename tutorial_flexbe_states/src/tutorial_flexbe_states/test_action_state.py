#!/usr/bin/env python
from flexbe_core import EventState, Logger
from flexbe_core.proxy import ProxyActionClient

# example import of required action
# the goal status thing is a required thing so don't forget to add it 
from actionlib_msgs.msg import GoalStatus
from test_actionlib.msg import testAction, testGoal


class TestActionState(EventState):
	'''
        This is a test actionlib state to see how to actually make our own actionlib states that call an actionlib server using the state as a client. I will try to keep documentation but no promises. 
        This state takes doesn't take any input and just goes to finish once it recieves the goal from the server.

	<= communicated_with_server              Was able to connect and communicate with the actionlib server.

        <= no_communication_with_server          Was not able to connect and communicate with the actionlib server. 

	'''

	def __init__(self):
		# See example_state.py for basic explanations.
		super(TestActionState, self).__init__(outcomes = ['communicated_with_server', 'no_communication_with_server'])

		# Create the action client when building the behavior.
		# This will cause the behavior to wait for the client before starting execution
		# and will trigger a timeout error if it is not available.
		# Using the proxy client provides asynchronous access to the result and status
		# and makes sure only one client is used, no matter how often this state is used in a behavior.
		self._topic = 'test_action'
		self._client = ProxyActionClient({self._topic: testAction}) # pass required clients as dict (topic: type)

		# It may happen that the action client fails to send the action goal.
		self._error = False


	def execute(self, userdata):
		# Check if the client failed to send the goal.
		if self._error:
			return 'no_communication_with_server'

		# Check if the action has been finished
		if self._client.has_result(self._topic):
                        result = self._client.get_result(self._topic)    

                        Logger.loginfo('the result is %s' % result)

                        return 'communicated_with_server'

		# If the action has not yet finished, no outcome will be returned and the state stays active.
		

	def on_enter(self, userdata):
		# When entering this state, we send the action goal once to let the robot start its work.

		# Create the goal.
		goal = testGoal()
		goal.test_goal = "test test"

		# Send the goal.
		self._error = False # make sure to reset the error state since a previous state execution might have failed
		try:
			self._client.send_goal(self._topic, goal)
		except Exception as e:
			# Since a state failure not necessarily causes a behavior failure, it is recommended to only print warnings, not errors.
			# Using a linebreak before appending the error log enables the operator to collapse details in the GUI.
			Logger.logwarn('Failed to send the test_goal command:\n%s' % str(e))
			self._error = True


	def on_exit(self, userdata):
		# Make sure that the action is not running when leaving this state.
		# A situation where the action would still be active is for example when the operator manually triggers an outcome.

		if not self._client.has_result(self._topic):
			self._client.cancel(self._topic)
			Logger.loginfo('Cancelled active action goal.')
		
