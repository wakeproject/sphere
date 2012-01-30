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
    private:
        int level;
        int size;
        double* data;
    };

}

#endif /* FIELD_H_ */
