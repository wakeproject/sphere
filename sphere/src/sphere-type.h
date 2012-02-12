/*
 * sphere-type.h
 *
 * The declarations for HEALPix implementation
 *
 * Wahlque Sphere Project
 *
 * MIT License
 *
 */

#ifndef TYPE_H_
#define TYPE_H_

namespace sphere {

    enum Kind {
        S,   // scalar field on surface
        ZS,  // scalar field on surface varying with z-axis
        TS,  // scalar field on surface varying with time
        TZS, // scalar field on surface varying with z-axis and time
        V,   // vector field on surface
        ZV,  // vector field on surface varying with z-axis
        TV,  // vector field on surface varying with time
        TZV  // vector field on surface varying with z-axis and time
    };

    class Vector {
    public:
        double x;
        double y;
        double z;
        Vector(double x=0, double y=0, double z=0);
        static Vector* ZERO;
        Vector& operator+=(const Vector &rhs);
        Vector& operator-=(const Vector &rhs);
        Vector& operator*=(const double &cnst);
        Vector& operator/=(const double &cnst);
    };

    class Coord {
    public:
        double longitude;
        double latitude;
    };

}

#endif /* TYPE_H_ */
