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

namespace sphere {

    class ScalarField {
    public:
        ScalarField(int level, double cnst=0);
        ~ScalarField();
        ScalarField & operator=(const ScalarField &rhs);
        double & operator[](int index);
        //double operator()(double lng, double lat);
    private:
        int level;
        int size;
        double* data;
    }

}

#endif /* FIELD_H_ */
