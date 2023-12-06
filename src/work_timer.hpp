
#ifndef WORK_TIMER_HPP
#define WORK_TIMER_HPP

#include <simlib.h>
#include "work.hpp"

class WorkTimer : public Event
{
public:
    /**
     * Constructs work shift timer event.
     *
     * @param workShift Work shift process which will be killed
     *                  after work shift duration.
     */
    explicit WorkTimer(WorkDay *workDay);

    /**
     * Work shift timer event behavior.
     */
    void Behavior() override;

private:
    /**
     * Work shift duration in minutes (6 h).
     */
    const double WORK_SHIFT_DURATION = 9.0 * 60.0;

    /**
     * Work shift process which will be killed
     * after work shift duration.
     */

    bool IsMorning = true;

    WorkDay *workDay;

    /**
     * Prints end of shift information.
     */
    void print_end_of_the_work();
    void print_start_of_the_lunch();
};

#endif // WORK_TIMER_HPP