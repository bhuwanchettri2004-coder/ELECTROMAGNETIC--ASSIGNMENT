#include <iostream>
#include <vector>
#include "biot_savart.hpp"

int main() {
    std::vector<em::CurrentElement> wire = {
        {0.0, 1.0, 0.01},
        {0.05, 2.0, 0.01},
        {0.10, 1.5, 0.01}
    };

    double point = 0.02;  // point at which B is calculated
    double B = em::magneticField(point, wire);

    std::cout << "Magnetic Field at x = " << point << " m: " << B << " T\n";
    return 0;
}