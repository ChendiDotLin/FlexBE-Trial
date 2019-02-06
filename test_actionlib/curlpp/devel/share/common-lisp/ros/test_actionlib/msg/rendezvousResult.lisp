; Auto-generated. Do not edit!


(cl:in-package test_actionlib-msg)


;//! \htmlinclude rendezvousResult.msg.html

(cl:defclass <rendezvousResult> (roslisp-msg-protocol:ros-message)
  ((completed
    :reader completed
    :initarg :completed
    :type cl:boolean
    :initform cl:nil)
   (num_rb
    :reader num_rb
    :initarg :num_rb
    :type cl:integer
    :initform 0)
   (avg_real_dist
    :reader avg_real_dist
    :initarg :avg_real_dist
    :type cl:integer
    :initform 0)
   (stamp
    :reader stamp
    :initarg :stamp
    :type cl:real
    :initform 0)
   (centroid
    :reader centroid
    :initarg :centroid
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point)))
)

(cl:defclass rendezvousResult (<rendezvousResult>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <rendezvousResult>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'rendezvousResult)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name test_actionlib-msg:<rendezvousResult> is deprecated: use test_actionlib-msg:rendezvousResult instead.")))

(cl:ensure-generic-function 'completed-val :lambda-list '(m))
(cl:defmethod completed-val ((m <rendezvousResult>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test_actionlib-msg:completed-val is deprecated.  Use test_actionlib-msg:completed instead.")
  (completed m))

(cl:ensure-generic-function 'num_rb-val :lambda-list '(m))
(cl:defmethod num_rb-val ((m <rendezvousResult>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test_actionlib-msg:num_rb-val is deprecated.  Use test_actionlib-msg:num_rb instead.")
  (num_rb m))

(cl:ensure-generic-function 'avg_real_dist-val :lambda-list '(m))
(cl:defmethod avg_real_dist-val ((m <rendezvousResult>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test_actionlib-msg:avg_real_dist-val is deprecated.  Use test_actionlib-msg:avg_real_dist instead.")
  (avg_real_dist m))

(cl:ensure-generic-function 'stamp-val :lambda-list '(m))
(cl:defmethod stamp-val ((m <rendezvousResult>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test_actionlib-msg:stamp-val is deprecated.  Use test_actionlib-msg:stamp instead.")
  (stamp m))

(cl:ensure-generic-function 'centroid-val :lambda-list '(m))
(cl:defmethod centroid-val ((m <rendezvousResult>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test_actionlib-msg:centroid-val is deprecated.  Use test_actionlib-msg:centroid instead.")
  (centroid m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <rendezvousResult>) ostream)
  "Serializes a message object of type '<rendezvousResult>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'completed) 1 0)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'num_rb)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'avg_real_dist)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__sec (cl:floor (cl:slot-value msg 'stamp)))
        (__nsec (cl:round (cl:* 1e9 (cl:- (cl:slot-value msg 'stamp) (cl:floor (cl:slot-value msg 'stamp)))))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 0) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __nsec) ostream))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'centroid) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <rendezvousResult>) istream)
  "Deserializes a message object of type '<rendezvousResult>"
    (cl:setf (cl:slot-value msg 'completed) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'num_rb) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'avg_real_dist) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((__sec 0) (__nsec 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 0) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __nsec) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'stamp) (cl:+ (cl:coerce __sec 'cl:double-float) (cl:/ __nsec 1e9))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'centroid) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<rendezvousResult>)))
  "Returns string type for a message object of type '<rendezvousResult>"
  "test_actionlib/rendezvousResult")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'rendezvousResult)))
  "Returns string type for a message object of type 'rendezvousResult"
  "test_actionlib/rendezvousResult")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<rendezvousResult>)))
  "Returns md5sum for a message object of type '<rendezvousResult>"
  "aa2c5772ffd5ab3fec357158cc8913e3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'rendezvousResult)))
  "Returns md5sum for a message object of type 'rendezvousResult"
  "aa2c5772ffd5ab3fec357158cc8913e3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<rendezvousResult>)))
  "Returns full string definition for message of type '<rendezvousResult>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%# Result~%bool completed~%int32 num_rb~%int32 avg_real_dist~%time stamp~%geometry_msgs/Point centroid~%# The bool will tell the client whether the behavior was completed or not while the avg real dist will give the user a metric to see how well the behavior was executed. ~%#Also how many robots are in the swarm as this server will try to be independent of the number of robots spawned. ~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'rendezvousResult)))
  "Returns full string definition for message of type 'rendezvousResult"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%# Result~%bool completed~%int32 num_rb~%int32 avg_real_dist~%time stamp~%geometry_msgs/Point centroid~%# The bool will tell the client whether the behavior was completed or not while the avg real dist will give the user a metric to see how well the behavior was executed. ~%#Also how many robots are in the swarm as this server will try to be independent of the number of robots spawned. ~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <rendezvousResult>))
  (cl:+ 0
     1
     4
     4
     8
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'centroid))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <rendezvousResult>))
  "Converts a ROS message object to a list"
  (cl:list 'rendezvousResult
    (cl:cons ':completed (completed msg))
    (cl:cons ':num_rb (num_rb msg))
    (cl:cons ':avg_real_dist (avg_real_dist msg))
    (cl:cons ':stamp (stamp msg))
    (cl:cons ':centroid (centroid msg))
))
