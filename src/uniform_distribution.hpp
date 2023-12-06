#ifndef UNIFORMDISTRIBUTION_HPP
#define UNIFORMDISTRIBUTION_HPP

class AverageUniformDistribution
{
public:
    /**
     * Generates pseudorandom numbers according to uniform distribution,
     * low limit and high limit is created from average value and
     * deviation from this value.
     *
     * @param average Average value.
     * @param deviation Deviation from average value in percentage.
     * @return Generated value.
     */
    static double Generate(double average, double deviation);
};

#endif // UNIFORMDISTRIBUTION_HPP