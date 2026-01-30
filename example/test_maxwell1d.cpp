
   #include <iostream>
#include "maxwell.hpp"

int main() {
    int Nx = 50;
    double dx = 0.01, dt = 1e-5;

    // Pulse current at center
    std::vector<double> J(Nx, 0.0);
    J[Nx/2] = 1e3;

    // Initialize fields
    auto f = em::initFields1D(Nx);

    // Time steps
    for(int t=0; t<100; t++)
        em::updateFields1D(f, dx, dt, J);

    std::cout << "Maxwell 1D Example\n";
    std::cout << "E at center: " << f.Ex[Nx/2] << "\n";
    std::cout << "H at center: " << f.Hy[Nx/2] << "\n";

    return 0;
}