; Auto-generated. Do not edit!


(cl:in-package test_actionlib-msg)


;//! \htmlinclude testGoal.msg.html

(cl:defclass <testGoal> (roslisp-msg-protocol:ros-message)
  ((test_goal
    :reader test_goal
    :initarg :test_goal
    :type cl:string
    :initform ""))
)

(cl:defclass testGoal (<testGoal>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <testGoal>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'testGoal)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name test_actionlib-msg:<testGoal> is deprecated: use test_actionlib-msg:testGoal instead.")))

(cl:ensure-generic-function 'test_goal-val :lambda-list '(m))
(cl:defmethod test_goal-val ((m <testGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test_actionlib-msg:test_goal-val is deprecated.  Use test_actionlib-msg:test_goal instead.")
  (test_goal m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <testGoal>) ostream)
  "Serializes a message object of type '<testGoal>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'test_goal))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'test_goal))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <testGoal>) istream)
  "Deserializes a message object of type '<testGoal>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'test_goal) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'test_goal) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<testGoal>)))
  "Returns string type for a message object of type '<testGoal>"
  "test_actionlib/testGoal")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'testGoal)))
  "Returns string type for a message object of type 'testGoal"
  "test_actionlib/testGoal")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<testGoal>)))
  "Returns md5sum for a message object of type '<testGoal>"
  "431931990308709b45979518bdc055cd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'testGoal)))
  "Returns md5sum for a message object of type 'testGoal"
  "431931990308709b45979518bdc055cd")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<testGoal>)))
  "Returns full string definition for message of type '<testGoal>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#goal ~%string test_goal~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'testGoal)))
  "Returns full string definition for message of type 'testGoal"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#goal ~%string test_goal~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <testGoal>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'test_goal))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <testGoal>))
  "Converts a ROS message object to a list"
  (cl:list 'testGoal
    (cl:cons ':test_goal (test_goal msg))
))
