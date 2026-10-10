#pragma once
#include "types.hpp"
#include "request.hpp"
#include <vector>


struct ElevatorState{
    int currentFloor = 0; //floor that this elevator last passed
    TimeMs nextEventMs = INF_TIME;
    Direction direction = Direction::NONE;
    ElevatorPhase phase = ElevatorPhase::IDLE;
    
    std::vector<Request> passengersInside;
    std::vector<Request> passengersWaiting;

    
};
