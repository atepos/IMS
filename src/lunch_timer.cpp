
#include <iostream>
#include "lunch_timer.hpp"

using namespace std;

LunchTimer::LunchTimer(Facility *is_lunch_time) : is_lunch_time(is_lunch_time){};

void LunchTimer::Behavior()
{
    Seize(*is_lunch_time);
    Wait(LUNCH_TIME);
    Release(*is_lunch_time);
}