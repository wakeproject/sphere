/*
 * sphere-field.h
 *
 * The declarations for fields
 *
 * Wahlque Sphere Project
 *
 * MIT License
 *
 */

#ifndef FIELD_H_
#define FIELD_H_

#include <cstddef>
#include "sphere-type.h"

namespace sphere {

    class ScalarField {
    public:
        ScalarField(int level, double cnst=0);
        ~ScalarField();
        ScalarField & operator=(const ScalarField &rhs);

        struct proxy {
            double& element;

            proxy(double& el) : element(el) {}

            operator const double& () const {
                return element; // For use on RHS of assignment
            }

            proxy& operator=(const double& rhs) {
                element = rhs; // For use on LHS of assignment
            }
        };

        const proxy operator[](int index) const;

        proxy operator[](int index);

        //double operator()(double lng, double lat);

        ScalarField& operator+=(const ScalarField &rhs);

        ScalarField& operator-=(const ScalarField &rhs);

        ScalarField& operator*=(const double &cnst);

        ScalarField& operator/=(const double &cnst);
    private:
        int level;
        int size;
        double* data;
    };

    class VectorField {
    public:
        VectorField(int level, Vector* cnst=Vector::ZERO);
        ~VectorField();
        VectorField & operator=(const VectorField &rhs);

        struct proxy {
            Vector& element;

            proxy(Vector& el) : element(el) {}

            operator const Vector& () const {
                return element; // For use on RHS of assignment
            }

            proxy& operator=(const Vector& rhs) {
                element = rhs; // For use on LHS of assignment
            }
        };

        const proxy operator[](int index) const;

        proxy operator[](int index);

        //Vector operator()(double lng, double lat);

        VectorField& operator+=(const VectorField &rhs);

        VectorField& operator-=(const VectorField &rhs);

        VectorField& operator*=(const double &cnst);

        VectorField& operator/=(const double &cnst);
    private:
        int level;
        int size;
        Vector* data;
    };

}

#endif /* FIELD_H_ */
