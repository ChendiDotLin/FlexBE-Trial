#!/usr/bin/env python2
from flexbe_core import EventState, Logger
from flexbe_core.proxy import ProxyActionClient

# example import of required action
# the goal status thing is a required thing so don't forget to add it 
from actionlib_msgs.msg import GoalStatus
from test_actionlib.msg import rendezvousAction, rendezvousGoal

class TestRendezvousState(EventState):
    '''
    This is a test actionlib state used for the rendezvous behavior  

    -- goal_distance    double    The distance 

    ># start                      Determin if the state should start from the beginning r if it needs to wait.

    <= continue                   If a result is recieved from the actionlib server
    <= failed                     Not really used at this point
    '''

    def __init__(self, goal_distance):
        # Declaring outcomes, input keys by calling the super constructor with the corresponding arguments.
        super(TestRendezvousState, self).__init__(outcomes = ['continue','failed'])

        # Pass the topic the actionlib server is listening on
        self._topic = 'test_rendezvous'
        self._client = ProxyActionClient({self._topic: rendezvousAction})

        self._error = False

    def execute(self, userdata):
        # Check if the client failed to send the goal.
        if self._error:
            return 'failed'

        # Check if the action has been completed
        if self._client.has_result(self._topic):
            result = self._client.get_result(self._topic)

            Logger.loginfo('Rendezvous has talked')

            return 'continue'

         # If the action has not yet finished, no outcome will ne returned and will stay active.

    def on_enter(self, userdata):
        # When entering this state, we send the actoionlin server the goal once and then sit back and hope for the best

        # Create the goal msg.
        goal = rendezvousGoal()
        goal.goal_dist = 1

        # Send the goal msg
        self._error = False
        try:
            self._client.send_goal(self._topic, goal)
        except Exception as e:
            Logger.logwarn('Failed to send the goal msg to server:\n%s' % str(e))

    def on_exit(self, userdata):
        # Make sure that the action is not running when leabing this state.
        # A situation where the action would still be active is for example when the operator manually triggers an outcome.

        if not self._client.has_result(self._topic):
            self._client.cancel(self._topic)
            Loger.loginfo('Cancelled active action goal.')

