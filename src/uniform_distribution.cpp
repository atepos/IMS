/**
 * VUT FIT IMS SHO project - Model vyroby v oblasti strojírenství
 *
 * @file Product process header implementation
 * @author Petr Kaška <xkaska01@stud.fit.vutbr.cz>
 * @author Martin Hemza <xhemza05@stud.fit.vutbr.cz>
 */

#include <simlib.h>
#include "uniform_distribution.hpp"

double UniformDistribution::Generate(double average, double deviation)
{
    double deviationValue = deviation / 100.0 * average;
    return Uniform(average - deviationValue, average + deviationValue);
}