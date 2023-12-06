#include <cstdlib>
#include <simlib.h>
#include <getopt.h>
#include <iostream>

#include "work.hpp"

#define SIMULATION_START_TIME 0.0
#define SIMULATION_END_TIME 24.0 * 60.0

#define DEFAULT_NUMBER_OF_WORKERS 10
#define DEFAULT_NUMBER_OF_CNC 7
#define DEFAULT_DEVIATION_OF_MILLING_MACHINES 3

#define DEFAULT_COUNT_OF_INCOMING_ORDER 500
#define DEFAULT_DEVIATION_OF_ORDERS 4.7

using namespace std;

void help()
{
    cout << "Possible Input arguments:" << endl;
    cout << "--workers to specify the number of workers in job" << endl;
    cout << "--orders to specify the number of orders that day" << endl;
}

int main()
{
    unsigned long workers = DEFAULT_NUMBER_OF_WORKERS;
    double orders = DEFAULT_COUNT_OF_INCOMING_ORDER;

    // help();

    cout << "------------------------------------------------------------" << endl;
    cout << "START OF SIMULATION" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Running experiment with " << workers << " number of cars." << endl;
    cout << "Running experiment with " << orders << " average number of food." << endl;
    cout << "------------------------------------------------------------" << endl;

    for (int i = 1; i <= 1; i++)
    {

        cout << "----- RUNNING TRY NUMBER " << i << endl;
        Init(SIMULATION_START_TIME, SIMULATION_END_TIME);

        (new WorkDay(workers,
                     orders,
                     DEFAULT_DEVIATION_OF_ORDERS,
                     DEFAULT_NUMBER_OF_CNC,
                     DEFAULT_DEVIATION_OF_MILLING_MACHINES))
            ->Activate();
        Run();
        SIMLIB_statistics.Output();

        cout << "----- END OF TRY NUMBER " << i << endl
             << endl;
    }
    return EXIT_SUCCESS;
}