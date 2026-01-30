#ifndef COULOMB_HPP
#define COULOMB_HPP

namespace em {

    // Vacuum permittivity (ε₀)
    const double EPSILON_0 = 8.854187817e-12;

    // Coulomb constant k = 1 / (4π ε₀)
    const double K = 1.0 / (4.0 * 3.141592653589793 * EPSILON_0);

    // Coulomb force function
    // q1, q2 → charges (C)
    // r → distance (m)
    double coulombForce(double q1, double q2, double r);

}

#endif