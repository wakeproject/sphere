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

    ScalarZField::ScalarZField(int level, const ScalarZ cnst) : Field<ScalarZ> (level, cnst) {
    }

    ScalarZField::ScalarZField(const Field<ScalarZ>& orignal) : Field<ScalarZ> (orignal) {
    }

    ScalarZField::~ScalarZField() {
    }

    const Field<ScalarZ>::proxy ScalarZField::operator[](int index) const {
        return (*((Field<ScalarZ>*) this))[index];
    }

    Field<ScalarZ>::proxy ScalarZField::operator[](int index) {
        return (*((Field<ScalarZ>*) this))[index];
    }

    ScalarZField& ScalarZField::operator+=(const ScalarZField &rhs) {
        (*((Field<ScalarZ>*) this)) += rhs;
        return (*this);
    }

    ScalarZField& ScalarZField::operator-=(const ScalarZField &rhs) {
        (*((Field<ScalarZ>*) this)) -= rhs;
        return (*this);
    }

    VectorZField::VectorZField(int level, const VectorZ cnst) : Field<VectorZ> (level, cnst) {
    }

    VectorZField::VectorZField(const Field<VectorZ>& orignal) : Field<VectorZ> (orignal) {
    }

    VectorZField::~VectorZField() {
    }

    const Field<VectorZ>::proxy VectorZField::operator[](int index) const {
        return (*((Field<VectorZ>*) this))[index];
    }

    Field<VectorZ>::proxy VectorZField::operator[](int index) {
        return (*((Field<VectorZ>*) this))[index];
    }

    VectorZField& VectorZField::operator+=(const VectorZField &rhs) {
        (*((Field<VectorZ>*) this)) += rhs;
        return (*this);
    }

    VectorZField& VectorZField::operator-=(const VectorZField &rhs) {
        (*((Field<VectorZ>*) this)) -= rhs;
        return (*this);
    }

    ScalarTField::ScalarTField(int level, const ScalarT cnst) : Field<ScalarT> (level, cnst) {
    }

    ScalarTField::ScalarTField(const Field<ScalarT>& orignal) : Field<ScalarT> (orignal) {
    }

    ScalarTField::~ScalarTField() {
    }

    const Field<ScalarT>::proxy ScalarTField::operator[](int index) const {
        return (*((Field<ScalarT>*) this))[index];
    }

    Field<ScalarT>::proxy ScalarTField::operator[](int index) {
        return (*((Field<ScalarT>*) this))[index];
    }

    ScalarTField& ScalarTField::operator+=(const ScalarTField &rhs) {
        (*((Field<ScalarT>*) this)) += rhs;
        return (*this);
    }

    ScalarTField& ScalarTField::operator-=(const ScalarTField &rhs) {
        (*((Field<ScalarT>*) this)) -= rhs;
        return (*this);
    }

    VectorTField::VectorTField(int level, const VectorT cnst) : Field<VectorT> (level, cnst) {
    }

    VectorTField::VectorTField(const Field<VectorT>& orignal) : Field<VectorT> (orignal) {
    }

    VectorTField::~VectorTField() {
    }

    const Field<VectorT>::proxy VectorTField::operator[](int index) const {
        return (*((Field<VectorT>*) this))[index];
    }

    Field<VectorT>::proxy VectorTField::operator[](int index) {
        return (*((Field<VectorT>*) this))[index];
    }

    VectorTField& VectorTField::operator+=(const VectorTField &rhs) {
        (*((Field<VectorT>*) this)) += rhs;
        return (*this);
    }

    VectorTField& VectorTField::operator-=(const VectorTField &rhs) {
        (*((Field<VectorT>*) this)) -= rhs;
        return (*this);
    }

    ScalarTZField::ScalarTZField(int level, const ScalarTZ cnst) : Field<ScalarTZ> (level, cnst) {
    }

    ScalarTZField::ScalarTZField(const Field<ScalarTZ>& orignal) : Field<ScalarTZ> (orignal) {
    }

    ScalarTZField::~ScalarTZField() {
    }

    const Field<ScalarTZ>::proxy ScalarTZField::operator[](int index) const {
        return (*((Field<ScalarTZ>*) this))[index];
    }

    Field<ScalarTZ>::proxy ScalarTZField::operator[](int index) {
        return (*((Field<ScalarTZ>*) this))[index];
    }

    ScalarTZField& ScalarTZField::operator+=(const ScalarTZField &rhs) {
        (*((Field<ScalarTZ>*) this)) += rhs;
        return (*this);
    }

    ScalarTZField& ScalarTZField::operator-=(const ScalarTZField &rhs) {
        (*((Field<ScalarTZ>*) this)) -= rhs;
        return (*this);
    }

    VectorTZField::VectorTZField(int level, const VectorTZ cnst) : Field<VectorTZ> (level, cnst) {
    }

    VectorTZField::VectorTZField(const Field<VectorTZ>& orignal) : Field<VectorTZ> (orignal) {
    }

    VectorTZField::~VectorTZField() {
    }

    const Field<VectorTZ>::proxy VectorTZField::operator[](int index) const {
        return (*((Field<VectorTZ>*) this))[index];
    }

    Field<VectorTZ>::proxy VectorTZField::operator[](int index) {
        return (*((Field<VectorTZ>*) this))[index];
    }

    VectorTZField& VectorTZField::operator+=(const VectorTZField &rhs) {
        (*((Field<VectorTZ>*) this)) += rhs;
        return (*this);
    }

    VectorTZField& VectorTZField::operator-=(const VectorTZField &rhs) {
        (*((Field<VectorTZ>*) this)) -= rhs;
        return (*this);
    }

}

