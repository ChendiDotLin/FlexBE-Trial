// Auto-generated. Do not edit!

// (in-package test_actionlib.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------

class rendezvousResult {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.completed = null;
      this.num_rb = null;
      this.avg_real_dist = null;
      this.stamp = null;
      this.centroid = null;
    }
    else {
      if (initObj.hasOwnProperty('completed')) {
        this.completed = initObj.completed
      }
      else {
        this.completed = false;
      }
      if (initObj.hasOwnProperty('num_rb')) {
        this.num_rb = initObj.num_rb
      }
      else {
        this.num_rb = 0;
      }
      if (initObj.hasOwnProperty('avg_real_dist')) {
        this.avg_real_dist = initObj.avg_real_dist
      }
      else {
        this.avg_real_dist = 0;
      }
      if (initObj.hasOwnProperty('stamp')) {
        this.stamp = initObj.stamp
      }
      else {
        this.stamp = {secs: 0, nsecs: 0};
      }
      if (initObj.hasOwnProperty('centroid')) {
        this.centroid = initObj.centroid
      }
      else {
        this.centroid = new geometry_msgs.msg.Point();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type rendezvousResult
    // Serialize message field [completed]
    bufferOffset = _serializer.bool(obj.completed, buffer, bufferOffset);
    // Serialize message field [num_rb]
    bufferOffset = _serializer.int32(obj.num_rb, buffer, bufferOffset);
    // Serialize message field [avg_real_dist]
    bufferOffset = _serializer.int32(obj.avg_real_dist, buffer, bufferOffset);
    // Serialize message field [stamp]
    bufferOffset = _serializer.time(obj.stamp, buffer, bufferOffset);
    // Serialize message field [centroid]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.centroid, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type rendezvousResult
    let len;
    let data = new rendezvousResult(null);
    // Deserialize message field [completed]
    data.completed = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [num_rb]
    data.num_rb = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [avg_real_dist]
    data.avg_real_dist = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [stamp]
    data.stamp = _deserializer.time(buffer, bufferOffset);
    // Deserialize message field [centroid]
    data.centroid = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 41;
  }

  static datatype() {
    // Returns string type for a message object
    return 'test_actionlib/rendezvousResult';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'aa2c5772ffd5ab3fec357158cc8913e3';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
    # Result
    bool completed
    int32 num_rb
    int32 avg_real_dist
    time stamp
    geometry_msgs/Point centroid
    # The bool will tell the client whether the behavior was completed or not while the avg real dist will give the user a metric to see how well the behavior was executed. 
    #Also how many robots are in the swarm as this server will try to be independent of the number of robots spawned. 
    
    ================================================================================
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new rendezvousResult(null);
    if (msg.completed !== undefined) {
      resolved.completed = msg.completed;
    }
    else {
      resolved.completed = false
    }

    if (msg.num_rb !== undefined) {
      resolved.num_rb = msg.num_rb;
    }
    else {
      resolved.num_rb = 0
    }

    if (msg.avg_real_dist !== undefined) {
      resolved.avg_real_dist = msg.avg_real_dist;
    }
    else {
      resolved.avg_real_dist = 0
    }

    if (msg.stamp !== undefined) {
      resolved.stamp = msg.stamp;
    }
    else {
      resolved.stamp = {secs: 0, nsecs: 0}
    }

    if (msg.centroid !== undefined) {
      resolved.centroid = geometry_msgs.msg.Point.Resolve(msg.centroid)
    }
    else {
      resolved.centroid = new geometry_msgs.msg.Point()
    }

    return resolved;
    }
};

module.exports = rendezvousResult;
