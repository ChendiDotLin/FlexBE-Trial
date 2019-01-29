#!/usr/bin/env python
# -*- coding: utf-8 -*-
###########################################################
#               WARNING: Generated code!                  #
#              **************************                 #
# Manual changes may get lost if file is generated again. #
# Only code inside the [MANUAL] tags will be kept.        #
###########################################################

from flexbe_core import Behavior, Autonomy, OperatableStateMachine, ConcurrencyContainer, PriorityContainer, Logger
from test_flexbe_states.test_action_state import TestActionState
# Additional imports can be added inside the following tags
# [MANUAL_IMPORT]

# [/MANUAL_IMPORT]


'''
Created on Mon Jan 28 2019
@author: keitaro nishimura
'''
class testactionSM(Behavior):
	'''
	testing how to make an action state communcate with an actionlib server
	'''


	def __init__(self):
		super(testactionSM, self).__init__()
		self.name = 'test action'

		# parameters of this behavior

		# references to used behaviors

		# Additional initialization code can be added inside the following tags
		# [MANUAL_INIT]
		
		# [/MANUAL_INIT]

		# Behavior comments:



	def create(self):
		# x:30 y:365, x:298 y:362
		_state_machine = OperatableStateMachine(outcomes=['finished', 'failed'])

		# Additional creation code can be added inside the following tags
		# [MANUAL_CREATE]
		
		# [/MANUAL_CREATE]


		with _state_machine:
			# x:148 y:132
			OperatableStateMachine.add('test',
										TestActionState(),
										transitions={'communicated_with_server': 'finished', 'no_communication_with_server': 'failed'},
										autonomy={'communicated_with_server': Autonomy.Off, 'no_communication_with_server': Autonomy.Off})


		return _state_machine


	# Private functions can be added inside the following tags
	# [MANUAL_FUNC]
	
	# [/MANUAL_FUNC]
