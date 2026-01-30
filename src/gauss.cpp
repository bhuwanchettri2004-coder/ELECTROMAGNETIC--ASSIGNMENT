#include "gauss.hpp"
#include <cmath>

// Φ = Q / ε0
double electricFlux(double enclosedCharge)
{
    return enclosedCharge / EPSILON_0;
}

// E = Q / (4π ε0 r²)
double electricFieldSphere(double enclosedCharge, double radius)
{
    return enclosedCharge / (4.0 * M_PI * EPSILON_0 * radius * radius);
}