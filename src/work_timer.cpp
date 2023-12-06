/**
 * VUT FIT IMS project - Freshbox food distribution.
 *
 * @file Work shift timer event implementation.
 * @author Dominik Harmim <xharmi00@stud.fit.vutbr.cz>
 * @author Vojtech Hertl <xhertl04@stud.fit.vutbr.cz>
 */

#include <iostream>
#include "work_timer.hpp"

using namespace std;

WorkTimer::WorkTimer(WorkDay *workDay) : workDay(workDay)
{
    Activate(Time + WORK_SHIFT_DURATION);
}

void WorkTimer::Behavior()
{

    print_end_of_the_work();

    delete workDay;
}

void WorkTimer::print_end_of_the_work()
{
    cout << "End of work shift because timer elapsed.\n\n";
}