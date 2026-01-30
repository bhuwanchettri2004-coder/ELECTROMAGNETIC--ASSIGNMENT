#include <iostream>
#include "coulomb.hpp"

int main() {
    double q1 = 1e-6;   // 1 microCoulomb
    double q2 = 2e-6;   // 2 microCoulomb
    double r  = 0.05;   // 5 cm

    double F = em::coulombForce(q1, q2, r);

    std::cout << "Coulomb Force = " << F << " N" << std::endl;

    return 0;
}