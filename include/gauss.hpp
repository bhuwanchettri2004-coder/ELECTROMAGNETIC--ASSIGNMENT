#ifndef GAUSS_HPP
#define GAUSS_HPP

// Permittivity of free space
const double EPSILON_0 = 8.854187817e-12;

// Electric flux through closed surface
double electricFlux(double enclosedCharge);

// Electric field due to spherical symmetry
double electricFieldSphere(double enclosedCharge, double radius);

#endif