#!/usr/bin/env python
# -*- coding: utf-8 -*-
###########################################################
#               WARNING: Generated code!                  #
#              **************************                 #
# Manual changes may get lost if file is generated again. #
# Only code inside the [MANUAL] tags will be kept.        #
###########################################################

from flexbe_core import Behavior, Autonomy, OperatableStateMachine, ConcurrencyContainer, PriorityContainer, Logger
from test_flexbe_states.test_action_rendezvous import TestRendezvousState
# Additional imports can be added inside the following tags
# [MANUAL_IMPORT]

# [/MANUAL_IMPORT]


'''
Created on Wed Feb 06 2019
@author: Keitaro Nishimura
'''
class TestRendezvousSM(Behavior):
	'''
	testing how to integrate flexbe, actionlib, and the NG simulator all together. It's like a happy disfunctional family :)
	'''


	def __init__(self):
		super(TestRendezvousSM, self).__init__()
		self.name = 'Test Rendezvous'

		# parameters of this behavior
		self.add_parameter('goal_distance', 1)

		# references to used behaviors

		# Additional initialization code can be added inside the following tags
		# [MANUAL_INIT]
		
		# [/MANUAL_INIT]

		# Behavior comments:



	def create(self):
		# x:30 y:365, x:347 y:355
		_state_machine = OperatableStateMachine(outcomes=['finished', 'failed'])

		# Additional creation code can be added inside the following tags
		# [MANUAL_CREATE]
		
		# [/MANUAL_CREATE]


		with _state_machine:
			# x:108 y:151
			OperatableStateMachine.add('test',
										TestRendezvousState(goal_distance=self.goal_distance),
										transitions={'continue': 'finished', 'failed': 'failed'},
										autonomy={'continue': Autonomy.Off, 'failed': Autonomy.Off})


		return _state_machine


	# Private functions can be added inside the following tags
	# [MANUAL_FUNC]
	
	# [/MANUAL_FUNC]
