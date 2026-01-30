#include <iostream>
#include <vector>
#include "maxwell.hpp"

int main() {
    int Nx=10, Ny=10, Nz=10;
    double dx=0.01, dy=0.01, dz=0.01, dt=1e-5;

    // Pulse currents
    std::vector<std::vector<std::vector<double>>> Jx(Nx, std::vector<std::vector<double>>(Ny, std::vector<double>(Nz,0.0)));
    std::vector<std::vector<std::vector<double>>> Jy(Nx, std::vector<std::vector<double>>(Ny, std::vector<double>(Nz,0.0)));
    std::vector<std::vector<std::vector<double>>> Jz(Nx, std::vector<std::vector<double>>(Ny, std::vector<double>(Nz,0.0)));

    Jx[Nx/2][Ny/2][Nz/2] = 1e3;  // pulse at center

    // Initialize fields
    auto f = em::initFields3D(Nx, Ny, Nz);

    // Time steps
    for(int t=0;t<20;t++)
        em::updateFields3D(f, dx, dy, dz, dt, Jx, Jy, Jz);

    std::cout << "Maxwell 3D Example\n";
    std::cout << "E_x at center: " << f.Ex[Nx/2][Ny/2][Nz/2] << "\n";
    std::cout << "E_y at center: " << f.Ey[Nx/2][Ny/2][Nz/2] << "\n";
    std::cout << "E_z at center: " << f.Ez[Nx/2][Ny/2][Nz/2] << "\n";
    std::cout << "H_x at center: " << f.Hx[Nx/2][Ny/2][Nz/2] << "\n";
    std::cout << "H_y at center: " << f.Hy[Nx/2][Ny/2][Nz/2] << "\n";
    std::cout << "H_z at center: " << f.Hz[Nx/2][Ny/2][Nz/2] << "\n";

    return 0;
}