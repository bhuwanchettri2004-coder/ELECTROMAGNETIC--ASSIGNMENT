#include "coulomb.hpp"
#include <stdexcept>

namespace em {

    double coulombForce(double q1, double q2, double r) {
        if (r == 0.0) {
            throw std::runtime_error("Distance r cannot be zero.");
        }
        return K * q1 * q2 / (r * r);
    }

}