/*
 * DynamixelState.h
 *
 *  Created on: 2015. 12. 8.
 *      Author: zerom
 */

#ifndef ROBOTIS_FRAMEWORK_ROBOTIS_CONTROLLER_INCLUDE_DEVICE_DYNAMIXELSTATE_H_
#define ROBOTIS_FRAMEWORK_ROBOTIS_CONTROLLER_INCLUDE_DEVICE_DYNAMIXELSTATE_H_

#include <stdint.h>
#include <robotis_framework_common/RobotisDef.h>

#define INDIRECT_DATA_1     "indirect_data_1"
#define INDIRECT_ADDRESS_1  "indirect_address_1"

namespace ROBOTIS
{

class TimeStamp {
public:
    long sec;
    long nsec;
    TimeStamp(long sec, long nsec) : sec(sec), nsec(nsec) { }
};

class DynamixelState
{
public:
    TimeStamp   update_time_stamp;

    double      present_position;
    double      present_velocity;
    double      present_current;
    double      goal_position;
    double      goal_velocity;
    double      goal_current;

    std::map<std::string, UINT32_T> bulk_read_table;

    double      position_offset;

    DynamixelState()
        : update_time_stamp(0, 0),
          present_position(0.0),
          present_velocity(0.0),
          present_current(0.0),
          goal_position(0.0),
          goal_velocity(0.0),
          goal_current(0.0),
          position_offset(0.0)
    {
        bulk_read_table.clear();
    }
};

}


#endif /* ROBOTIS_FRAMEWORK_ROBOTIS_CONTROLLER_INCLUDE_DEVICE_DYNAMIXELSTATE_H_ */
