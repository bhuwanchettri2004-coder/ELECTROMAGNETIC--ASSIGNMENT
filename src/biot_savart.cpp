#include "biot_savart.hpp"
#include <cmath>

namespace em {

// Biot–Savart law (1D simplified along x-axis)
double magneticField(double x_point, const std::vector<CurrentElement>& elements)
{
    double B = 0.0;
    for (auto& e : elements) {
        double r = x_point - e.x;
        if (r != 0) {
            B += (MU0 / (4.0 * M_PI)) * e.I * e.dl / (r * r);
        }
    }
    return B;
}

}