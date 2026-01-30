#ifndef MAXWELL_HPP
#define MAXWELL_HPP

#include <vector>
#include <cmath>

namespace em {

// Constants
const double MU0 = 4.0 * M_PI * 1e-7;
const double EPS0 = 8.854187817e-12;

///////////////////////////////////////
// 1D Maxwell Fields
///////////////////////////////////////
struct Fields1D {
    std::vector<double> Ex;
    std::vector<double> Hy;
};

Fields1D initFields1D(int Nx);
void updateFields1D(Fields1D &f, double dx, double dt, const std::vector<double> &J);

///////////////////////////////////////
// 2D Maxwell Fields (TE Mode)
///////////////////////////////////////
struct Fields2D {
    std::vector<std::vector<double>> Ex;
    std::vector<std::vector<double>> Ey;
    std::vector<std::vector<double>> Hz;
};

Fields2D initFields2D(int Nx, int Ny);
void updateFields2D(Fields2D &f, double dx, double dy, double dt, 
                    const std::vector<std::vector<double>> &Jx,
                    const std::vector<std::vector<double>> &Jy);

///////////////////////////////////////
// 3D Maxwell Fields
///////////////////////////////////////
struct Fields3D {
    std::vector<std::vector<std::vector<double>>> Ex;
    std::vector<std::vector<std::vector<double>>> Ey;
    std::vector<std::vector<std::vector<double>>> Ez;
    std::vector<std::vector<std::vector<double>>> Hx;
    std::vector<std::vector<std::vector<double>>> Hy;
    std::vector<std::vector<std::vector<double>>> Hz;
};

Fields3D initFields3D(int Nx, int Ny, int Nz);
void updateFields3D(Fields3D &f, double dx, double dy, double dz, double dt,
                    const std::vector<std::vector<std::vector<double>>> &Jx,
                    const std::vector<std::vector<std::vector<double>>> &Jy,
                    const std::vector<std::vector<std::vector<double>>> &Jz);

}

#endif