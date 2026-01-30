#ifndef BIOT_SAVART_HPP
#define BIOT_SAVART_HPP

#include <vector>

namespace em {

const double MU0 = 4.0 * 3.141592653589793e-7;

// Structure to represent a current element
struct CurrentElement {
    double x;  // position along x-axis
    double I;  // current in Amperes
    double dl; // length of element in meters
};

// Calculate magnetic field B at position x_point due to list of current elements
double magneticField(double x_point, const std::vector<CurrentElement>& elements);

}

#endif