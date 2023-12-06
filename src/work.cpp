
#include <iostream>

#include "work_timer.hpp"
#include "work.hpp"
#include "uniform_distribution.hpp"
#include "product.hpp"

using namespace std;

WorkDay::WorkDay(unsigned long workers, int average_orders_count, double order_deviation, int CNC_count, int milling_machine_count)
{
    this->workers = new Store("Workers-Store", workers);
    this->CNC = new Store("CNC-store", CNC_count);
    this->milling_machine = new Store("Milling_machine-Store", milling_machine_count);
    this->is_lunch_time = new Facility("Lunch_time-Facility");

    orders = new int(static_cast<int>(
        AverageUniformDistribution::Generate(average_orders_count, order_deviation)));

    product_loading_time_stats = new Stat("Preparing material for CNC");
    product_machining_time_stats = new Stat("CNC Machining");
    product_milling_preparation_stats = new Stat("Preparing for milling");
    product_milling_time_stats = new Stat("Milling");
    product_finalizing_time_stats = new Stat("Final adjustment");

    print_start_of_the_work_day();
}

WorkDay::~WorkDay()
{
    print_end_of_the_work_day();
    delete orders;
    delete product_loading_time_stats;
    delete product_machining_time_stats;
    delete product_milling_preparation_stats;
    delete product_milling_time_stats;
    delete product_finalizing_time_stats;
}

void WorkDay::Behavior()
{
    auto *timer = new WorkTimer(this);

    while (*orders > 0)
    {

        Seize(*is_lunch_time);
        Release(*is_lunch_time);

        Enter(*workers, 1);

        printf("%f\n", Time);
        (*orders)--;

        (new Product(workers,
                     CNC,
                     milling_machine,
                     is_lunch_time,
                     product_loading_time_stats,
                     product_machining_time_stats,
                     product_milling_preparation_stats,
                     product_milling_time_stats,
                     product_finalizing_time_stats))
            ->Activate();
    }

    delete timer;
}

void WorkDay::print_start_of_the_work_day()
{

    cout << "////////////////////////////////////////////////////////////" << endl;
    cout << "Work shift started." << endl;
    cout << "\tStart time: " << Time << endl;
    cout << "\tNumber of workers: " << workers->Capacity() << endl;
    cout << "\tNumber of orders: " << *orders << endl;
}

void WorkDay::print_end_of_the_work_day()
{
    cout << "End of work shift." << endl;
    cout << "\tEnd time: " << Time << endl;
    cout << "\tNumber of orders left: " << *orders << endl;

    milling_machine->Output();
    CNC->Output();
    workers->Output();
    product_loading_time_stats->Output();
    product_machining_time_stats->Output();
    product_milling_preparation_stats->Output();
    product_milling_time_stats->Output();
    product_finalizing_time_stats->Output();
    is_lunch_time->Output();
}