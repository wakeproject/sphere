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

    class ScalarZField {
    public:
        ScalarZField(int level, double cnst=0);
        ~ScalarZField();
        ScalarZField & operator=(const ScalarZField &rhs);

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

        ScalarZField& operator+=(const ScalarZField &rhs);

        ScalarZField& operator-=(const ScalarZField &rhs);

        ScalarZField& operator*=(const double &cnst);

        ScalarZField& operator/=(const double &cnst);
    private:
        int level;
        int size;
        double* data;
    };

    class VectorZField {
    public:
        VectorZField(int level, Vector* cnst=Vector::ZERO);
        ~VectorZField();
        VectorZField & operator=(const VectorZField &rhs);

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

        VectorZField& operator+=(const VectorZField &rhs);

        VectorZField& operator-=(const VectorZField &rhs);

        VectorZField& operator*=(const double &cnst);

        VectorZField& operator/=(const double &cnst);
    private:
        int level;
        int size;
        Vector* data;
    };

}

#endif /* FIELD_H_ */
