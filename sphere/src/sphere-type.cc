/*
 * sphere-field.cc
 *
 * The implementations for fields
 *
 * Wahlque Sphere Project
 *
 * MIT License
 *
 */

#include "sphere-type.h"

namespace sphere {

    Vector::Vector(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    };

    Vector* Vector::ZERO = new Vector();

    Vector& Vector::operator+=(const Vector &rhs) {
        this->x = this->x + rhs.x;
        this->y = this->y + rhs.y;
        this->z = this->z + rhs.z;

        return (*this);
    }

    Vector& Vector::operator-=(const Vector &rhs) {
        this->x = this->x - rhs.x;
        this->y = this->y - rhs.y;
        this->z = this->z - rhs.z;

        return (*this);
    }

    Vector& Vector::operator*=(const double &cnst) {
        this->x = this->x * cnst;
        this->y = this->y * cnst;
        this->z = this->z * cnst;

        return (*this);
    }

    Vector& Vector::operator/=(const double &cnst) {
        this->x = this->x / cnst;
        this->y = this->y / cnst;
        this->z = this->z / cnst;

        return (*this);
    }
}

