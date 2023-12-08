#include <simlib.h>
#include "uniform_distribution.hpp"

double UniformDistribution::Generate(double average, double deviation)
{
    double deviationValue = deviation / 100.0 * average;
    return Uniform(average - deviationValue, average + deviationValue);
}