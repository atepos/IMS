#ifndef WORKDAY_HPP
#define WORKDAY_HPP

#include <simlib.h>

class WorkDay : public Process
{
public:
    WorkDay(unsigned long workers, int average_orders_count, double order_deviation, int CNC_count, int milling_machine_count);

    /**
     * Desctructs work shift process.
     */
    ~WorkDay() override;

    /**
     * Work shift process behavoir.
     */
    void Behavior() override;

private:
    Store *workers;

    Store *CNC;
    Store *milling_machine;
    Facility *is_lunch_time;

    /**
     * Number of food to be distributed.
     */
    int *orders;

    /**
     * Car loading duration statistics.
     */
    Stat *product_loading_time_stats;

    /**
     * Car ride duration statistics.
     */
    Stat *product_machining_time_stats;

    /**
     * Car ride distance statistics.
     */
    Stat *product_milling_preparation_stats;

    /**
     * Car ride fuel consumption statistics.
     */
    Stat *product_milling_time_stats;

    Stat *product_finalizing_time_stats;

    /**
     * Prints start of shift information.
     */
    void print_start_of_the_work_day();

    /**
     * Prints end of shift information.
     */
    void print_end_of_the_work_day();
};

#endif // WORKDAY_HPP