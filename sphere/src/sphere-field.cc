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

#include <stdio.h>

#include "sphere-field.h"
#include "sphere-index.h"
#include "sphere-geoind.h"

namespace sphere {

    template <typename T>
    Field<T>::Field(int level, const T cnst) {
        this->level = level;
        this->size = all(level);
        this->data = new T[this->size];

        for (int i = 0; i < this->size; i++) {
            this->data[i] = cnst;
        }
    };

    template <typename T>
    Field<T>::Field(const Field<T>::Field<T>& orignal) {
        this->level = orignal.level;
        this->size = orignal.size;
        this->data = new T[this->size];

        for (int i = 0; i < this->size; i++) {
            this->data[i] = orignal.data[i];
        }
    };

    template <typename T>
    Field<T>::~Field() {
        delete [] this->data;
        this->data = NULL;
    };

    template <typename T>
    Field<T>& Field<T>::operator=(const Field<T> &rhs) {
        if (this == &rhs)
            return *this;

        if (this->data != NULL)
            delete [] this->data;

        this->level = rhs.level;
        this->size = rhs.size;
        this->data = new T[this->size];

        for (int i = 0; i < this->size; i++) {
            this->data[i] = rhs.data[i];
        }

        return *this;
    };

    template <typename T>
    const typename Field<T>::proxy Field<T>::operator[](int index) const {
        int size = this->size;
        index = index % size;
        if (index < 0) index = index + size;
        return proxy(this->data[index]);
    };

    template <typename T>
    typename Field<T>::proxy Field<T>::operator[](int index) {
        int size = this->size;
        index = index % size;
        if (index < 0) index = index + size;
        return proxy(this->data[index]);
    };

    template <typename T>
    Field<T>& Field<T>::operator+=(const Field<T> &rhs) {
        if(this->level != rhs.level)
            throw "granularity of the two fields is mismatched!";

        for(int i = 0, len = all(this->level); i < len; i++) {
            this->data[i] += rhs.data[i];
        }

        return (*this);
    };

    template <typename T>
    Field<T>& Field<T>::operator-=(const Field<T> &rhs) {
        if(this->level != rhs.level)
            throw "granularity of the two fields is mismatched!";

        for(int i = 0, len = all(this->level); i < len; i++) {
            this->data[i] -= rhs.data[i];
        }

        return (*this);
    };

    template <typename T>
    Field<T>& Field<T>::operator*=(const double &cnst) {
        for(int i = 0, len = all(this->level); i < len; i++) {
            this->data[i] *= cnst;
        }

        return (*this);
    };

    template <typename T>
    Field<T>& Field<T>::operator/=(const double &cnst) {
        if(cnst == 0)
            throw "divided by zero!";

        for(int i = 0, len = all(this->level); i < len; i++) {
            this->data[i] /= cnst;
        }

        return (*this);
    };

    /*
    template <typename T>
    T Field<T>::operator()(double lng, double lat) {
    };
    */

    ScalarField::ScalarField(int level, const double cnst) : Field<double> (level, cnst) {
    }

    ScalarField::ScalarField(const Field<double>& orignal) : Field<double> (orignal) {
    }

    ScalarField::~ScalarField() {
    }

    const Field<double>::proxy ScalarField::operator[](int index) const {
        return (*((Field<double>*) this))[index];
    }

    Field<double>::proxy ScalarField::operator[](int index) {
        return (*((Field<double>*) this))[index];
    }

    ScalarField& ScalarField::operator+=(const ScalarField &rhs) {
        (*((Field<double>*) this)) += rhs;
        return (*this);
    }

    ScalarField& ScalarField::operator-=(const ScalarField &rhs) {
        (*((Field<double>*) this)) -= rhs;
        return (*this);
    }

    VectorField::VectorField(int level, const Vector cnst) : Field<Vector> (level, cnst) {
    }

    VectorField::VectorField(const Field<Vector>& orignal) : Field<Vector> (orignal) {
    }

    VectorField::~VectorField() {
    }

    const Field<Vector>::proxy VectorField::operator[](int index) const {
        return (*((Field<Vector>*) this))[index];
    }

    Field<Vector>::proxy VectorField::operator[](int index) {
        return (*((Field<Vector>*) this))[index];
    }

    VectorField& VectorField::operator+=(const VectorField &rhs) {
        (*((Field<Vector>*) this)) += rhs;
        return (*this);
    }

    VectorField& VectorField::operator-=(const VectorField &rhs) {
        (*((Field<Vector>*) this)) -= rhs;
        return (*this);
    }

}

