#include "maxwell.hpp"

namespace em {

///////////////////////////////////////
// 1D Functions
///////////////////////////////////////
Fields1D initFields1D(int Nx) {
    Fields1D f;
    f.Ex = std::vector<double>(Nx, 0.0);
    f.Hy = std::vector<double>(Nx, 0.0);
    return f;
}

void updateFields1D(Fields1D &f, double dx, double dt, const std::vector<double> &J) {
    int Nx = f.Ex.size();
    for(int i=1; i<Nx; ++i)
        f.Hy[i] += (dt/(MU0*dx)) * (f.Ex[i] - f.Ex[i-1]);
    for(int i=0; i<Nx-1; ++i)
        f.Ex[i] += (dt/(EPS0*dx)) * (f.Hy[i+1] - f.Hy[i]) - dt*J[i]/EPS0;
}

///////////////////////////////////////
// 2D Functions (TE Mode)
///////////////////////////////////////
Fields2D initFields2D(int Nx, int Ny) {
    Fields2D f;
    f.Ex.resize(Nx, std::vector<double>(Ny,0.0));
    f.Ey.resize(Nx, std::vector<double>(Ny,0.0));
    f.Hz.resize(Nx, std::vector<double>(Ny,0.0));
    return f;
}

void updateFields2D(Fields2D &f, double dx, double dy, double dt,
                    const std::vector<std::vector<double>> &Jx,
                    const std::vector<std::vector<double>> &Jy) {
    int Nx = f.Ex.size();
    int Ny = f.Ex[0].size();
    for(int i=0;i<Nx-1;i++)
        for(int j=0;j<Ny-1;j++)
            f.Hz[i][j] += dt/MU0 * ((f.Ex[i][j+1]-f.Ex[i][j])/dy - (f.Ey[i+1][j]-f.Ey[i][j])/dx);
    for(int i=1;i<Nx;i++)
        for(int j=1;j<Ny;j++) {
            f.Ex[i][j] += dt/EPS0 * ((f.Hz[i][j]-f.Hz[i][j-1])/dy - Jx[i][j]);
            f.Ey[i][j] += dt/EPS0 * (-(f.Hz[i][j]-f.Hz[i-1][j])/dx - Jy[i][j]);
        }
}

///////////////////////////////////////
// 3D Functions
///////////////////////////////////////
Fields3D initFields3D(int Nx, int Ny, int Nz) {
    Fields3D f;
    f.Ex.resize(Nx,std::vector<std::vector<double>>(Ny,std::vector<double>(Nz,0.0)));
    f.Ey.resize(Nx,std::vector<std::vector<double>>(Ny,std::vector<double>(Nz,0.0)));
    f.Ez.resize(Nx,std::vector<std::vector<double>>(Ny,std::vector<double>(Nz,0.0)));
    f.Hx.resize(Nx,std::vector<std::vector<double>>(Ny,std::vector<double>(Nz,0.0)));
    f.Hy.resize(Nx,std::vector<std::vector<double>>(Ny,std::vector<double>(Nz,0.0)));
    f.Hz.resize(Nx,std::vector<std::vector<double>>(Ny,std::vector<double>(Nz,0.0)));
    return f;
}

void updateFields3D(Fields3D &f, double dx, double dy, double dz, double dt,
                    const std::vector<std::vector<std::vector<double>>> &Jx,
                    const std::vector<std::vector<std::vector<double>>> &Jy,
                    const std::vector<std::vector<std::vector<double>>> &Jz) {

    int Nx = f.Ex.size();
    int Ny = f.Ex[0].size();
    int Nz = f.Ex[0][0].size();

    for(int i=1;i<Nx;i++)
        for(int j=1;j<Ny;j++)
            for(int k=1;k<Nz;k++) {
                // H field update (FDTD curl)
                f.Hx[i][j][k] -= dt/MU0*((f.Ey[i][j][k]-f.Ey[i][j][k-1])/dz - (f.Ez[i][j][k]-f.Ez[i][j-1][k])/dy);
                f.Hy[i][j][k] -= dt/MU0*((f.Ez[i][j][k]-f.Ez[i-1][j][k])/dx - (f.Ex[i][j][k]-f.Ex[i][j][k-1])/dz);
                f.Hz[i][j][k] -= dt/MU0*((f.Ex[i][j][k]-f.Ex[i][j-1][k])/dy - (f.Ey[i][j][k]-f.Ey[i-1][j][k])/dx);

                // E field update
                f.Ex[i][j][k] += dt/EPS0*( ((f.Hz[i][j][k]-f.Hz[i][j-1][k])/dy) - ((f.Hy[i][j][k]-f.Hy[i][j][k-1])/dz) - Jx[i][j][k] );
                f.Ey[i][j][k] += dt/EPS0*( ((f.Hx[i][j][k]-f.Hx[i][j][k-1])/dz) - ((f.Hz[i][j][k]-f.Hz[i-1][j][k])/dx) - Jy[i][j][k] );
                f.Ez[i][j][k] += dt/EPS0*( ((f.Hy[i][j][k]-f.Hy[i-1][j][k])/dx) - ((f.Hx[i][j][k]-f.Hx[i][j-1][k])/dy) - Jz[i][j][k] );
            }
}

}