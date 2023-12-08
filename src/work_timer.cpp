/**
 * VUT FIT IMS SHO project - Model vyroby v oblasti strojírenství
 *
 * @file Work timer event implementation
 * @author Petr Kaška <xkaska01@stud.fit.vutbr.cz>
 * @author Martin Hemza <xhemza05@stud.fit.vutbr.cz>
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