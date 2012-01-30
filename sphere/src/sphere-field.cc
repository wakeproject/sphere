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

#include "sphere-field.h"
#include "sphere-index.h"
#include "sphere-geoind.h"

namespace sphere {

    ScalarField::ScalarField(int level, double cnst) {
        this->level = level;
        this->size = all(level);
        this->data = new double[size];

        for (int i = 0; i < size; i++) {
            this->data[i] = cnst;
        }
    }

    ScalarField::~ScalarField() {
        delete [] this->data;
        this->data = NULL;
    }

    ScalarField & ScalarField::operator=(const ScalarField &rhs) {
        if (this == &rhs)
            return *this;

        if (this->data != NULL)
            delete [] this->data;

        this->level = rhs.level;
        this->size = rhs.size;
        this->data = new double[this->size];
        for (int i = 0; i < size; i++) {
            this->data[i] = rhs.data[i];
        }

        return *this;
    }

    const ScalarField::proxy ScalarField::operator[](int index) const {
        int size = this->size;
        index = index % size;
        if (index < 0) index = index + size;
        return proxy(this->data[index]);
    }

    ScalarField::proxy ScalarField::operator[](int index) {
        int size = this->size;
        index = index % size;
        if (index < 0) index = index + size;
        return proxy(this->data[index]);
    }

    /*
    double ScalarField::operator()(double lng, double lat) {
    }
    */

}

