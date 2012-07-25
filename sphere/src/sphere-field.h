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

#include "sphere-type.h"

namespace sphere {

    template <typename T> class Field {
    public:
        Field(int level, const T cnst);
        Field(const Field<T>& orignal);
        ~Field();

        struct proxy {
            T& element;

            proxy(T& el) : element(el) {}

            operator const T& () const {
                return element; // For use on RHS of assignment
            };

            proxy& operator=(const T &rhs) {
                element = rhs; // For use on LHS of assignment
            };
        };

        const proxy operator[](int index) const;

        proxy operator[](int index);

        virtual Field<T>& operator=(const Field<T> &rhs);

        virtual Field<T>& operator+=(const Field<T> &rhs);

        virtual Field<T>& operator-=(const Field<T> &rhs);

        virtual Field<T>& operator*=(const double &cnst);

        virtual Field<T>& operator/=(const double &cnst);

        //T operator()(double lng, double lat);

        int level;
        int size;
        T* data;
    };

    class ScalarField : public Field<double> {
    public:
        ScalarField(int level, const double cnst);
        ScalarField(const Field<double>& orignal);
        ~ScalarField();
        const Field<double>::proxy operator[](int index) const;
        Field<double>::proxy operator[](int index);
        ScalarField& operator+=(const ScalarField &rhs);
        ScalarField& operator-=(const ScalarField &rhs);
    };

    class VectorField : public Field<Vector> {
    public:
        VectorField(int level, const Vector cnst);
        VectorField(const Field<Vector>& orignal);
        ~VectorField();
        const Field<Vector>::proxy operator[](int index) const;
        Field<Vector>::proxy operator[](int index);
        VectorField& operator+=(const VectorField &rhs);
        VectorField& operator-=(const VectorField &rhs);
   };

    class ScalarZField : public Field<ScalarZ> {
    public:
        ScalarZField(int level, const ScalarZ cnst);
        ScalarZField(const Field<ScalarZ>& orignal);
        ~ScalarZField();
        const Field<ScalarZ>::proxy operator[](int index) const;
        Field<ScalarZ>::proxy operator[](int index);
        ScalarZField& operator+=(const ScalarZField &rhs);
        ScalarZField& operator-=(const ScalarZField &rhs);
    };

    class VectorZField : public Field<VectorZ> {
    public:
        VectorZField(int level, const VectorZ cnst);
        VectorZField(const Field<VectorZ>& orignal);
        ~VectorZField();
        const Field<VectorZ>::proxy operator[](int index) const;
        Field<VectorZ>::proxy operator[](int index);
        VectorZField& operator+=(const VectorZField &rhs);
        VectorZField& operator-=(const VectorZField &rhs);
   };
}

#endif /* FIELD_H_ */
