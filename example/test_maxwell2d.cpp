#include <iostream>
#include <vector>
#include "maxwell.hpp"

int main() {
    int Nx = 20, Ny = 20;
    double dx = 0.01, dy = 0.01, dt = 1e-5;

    // Pulse currents
    std::vector<std::vector<double>> Jx(Nx, std::vector<double>(Ny,0.0));
    std::vector<std::vector<double>> Jy(Nx, std::vector<double>(Ny,0.0));
    Jx[Nx/2][Ny/2] = 1e3;  // pulse at center

    // Initialize fields
    auto f = em::initFields2D(Nx, Ny);

    // Time steps
    for(int t=0; t<50; t++)
        em::updateFields2D(f, dx, dy, dt, Jx, Jy);

    std::cout << "Maxwell 2D Example\n";
    std::cout << "E_x at center: " << f.Ex[Nx/2][Ny/2] << "\n";
    std::cout << "E_y at center: " << f.Ey[Nx/2][Ny/2] << "\n";
    std::cout << "H_z at center: " << f.Hz[Nx/2][Ny/2] << "\n";

    return 0;
}