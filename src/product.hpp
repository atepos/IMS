#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include "simlib.h"

class Product : public Process
{
public:
    void Behavior() override;

    Product(Store *workers,
            Store *CNC,
            Store *milling_machine,
            Facility *is_lunch_time,
            Stat *product_loading_stats,
            Stat *product_machining_time_stats,
            Stat *product_milling_preparation_stats,
            Stat *product_milling_time_stats,
            Stat *product_finalizing_time_stats);

private:
    const double PRODUCT_LOADING_TIME_AVG = 31.0;
    const double PRODUCT_LOADING_TIME_DEVIATION = 16.1;

    const double PRODUCT_MACHINING_TIME_AVG = 40.0;
    const double PRODUCT_MACHINING_TIME_DEVIATION = 5.4;

    const double PRODUCT_PREPARING_FOR_MILLING_TIME_AVG = 12.0;
    const double PRODUCT_PREPARING_FOR_MILLING_TIME_DEVIATION = 21.4;

    const double PRODUCT_MILLING_TIME_AVG = 8.0;
    const double PRODUCT_MILLING_TIME_DEVIATION = 3.4;

    const double PRODUCT_FINALIZING_CORRECT_TIME_AVG = 4.0;
    const double PRODUCT_FINALIZING_CORRECT_TIME_DEVIATION = 3.4;

    const double PRODUCT_FINALIZING_BAD_TIME_AVG = 10.0;
    const double PRODUCT_FINALIZING_BAD_TIME_DEVIATION = 30.4;

    Store *workers;
    Store *CNC;
    Store *milling_machine;
    Facility *is_lunch_time;

    Stat *product_loading_stats;
    Stat *product_machining_time_stats;
    Stat *product_milling_preparation_stats;
    Stat *product_milling_time_stats;
    Stat *product_finalizing_time_stats;
};

#endif // PRODUCT_HPP