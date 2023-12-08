#ifndef UNIFORMDISTRIBUTION_HPP
#define UNIFORMDISTRIBUTION_HPP

/**
 * @class UniformDistribution
 * @brief Represents a static class for generating random numbers from a uniform distribution.
 *
 * This class provides a static method for generating random numbers following a uniform distribution.
 */
class UniformDistribution
{
public:
    /**
     * @brief Generates a random number from a uniform distribution.
     * @param average The average value of the distribution.
     * @param deviation The deviation of the distribution.
     * @return A random number following a uniform distribution.
     */
    static double Generate(double average, double deviation);
};

#endif // UNIFORMDISTRIBUTION_HPP
