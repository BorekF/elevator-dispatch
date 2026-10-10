#pragma once
#include <limits>
using TimeMs = int;

enum class ElevatorPhase{
    IDLE,
    MOVING,
    DOORS
}; 

enum class Direction{
    UP,
    DOWN,
    NONE
};

constexpr TimeMs INF_TIME = std::numeric_limits<TimeMs>::max();
