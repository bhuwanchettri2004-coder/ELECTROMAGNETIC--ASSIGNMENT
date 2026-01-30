#include <iostream>
#include "gauss.hpp"

int main()
{
    double Q = 1e-6;     // charge in coulomb
    double r = 0.5;      // radius in meter

    std::cout << "Enclosed Charge: " << Q << " C\n";
    std::cout << "Electric Flux: " << electricFlux(Q) << " N·m^2/C\n";
    std::cout << "Electric Field (Sphere): "
              << electricFieldSphere(Q, r)
              << " N/C\n";

    return 0;
}