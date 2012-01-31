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

    const ScalarField ScalarField::operator+(const ScalarField &other) const {
        if(this->level != other.level)
            throw "granularity of the two fields is mismatched!";

        ScalarField* field = new ScalarField(this->level);
        for(int i = 0, len = all(this->level); i < len; i++) {
            (*field)[i] = (*this)[i] + other[i];
        }

        return (*field);
    }

    const ScalarField ScalarField::operator-(const ScalarField &other) const {
        if(this->level != other.level)
            throw "granularity of the two fields is mismatched!";

        ScalarField* field = new ScalarField(this->level);
        for(int i = 0, len = all(this->level); i < len; i++) {
            (*field)[i] = (*this)[i] - other[i];
        }

        return (*field);
    }

    const ScalarField ScalarField::operator*(const double cnst) const {
        ScalarField* field = new ScalarField(this->level);
        for(int i = 0, len = all(this->level); i < len; i++) {
            (*field)[i] = (*this)[i] * cnst;
        }

        return (*field);
    }

    const ScalarField ScalarField::operator/(const double cnst) const {
        if(cnst == 0)
            throw "divided by zero!";

        ScalarField* field = new ScalarField(this->level);
        for(int i = 0, len = all(this->level); i < len; i++) {
            (*field)[i] = (*this)[i] / cnst;
        }

        return (*field);
    }

    ScalarField& ScalarField::operator+=(const ScalarField &rhs) {
        if(this->level != rhs.level)
            throw "granularity of the two fields is mismatched!";

        for(int i = 0, len = all(this->level); i < len; i++) {
            (*this)[i] = (*this)[i] + rhs[i];
        }

        return (*this);
    }

    ScalarField& ScalarField::operator-=(const ScalarField &rhs) {
        if(this->level != rhs.level)
            throw "granularity of the two fields is mismatched!";

        for(int i = 0, len = all(this->level); i < len; i++) {
            (*this)[i] = (*this)[i] - rhs[i];
        }

        return (*this);
    }

    ScalarField& ScalarField::operator*=(const double &cnst) {
        for(int i = 0, len = all(this->level); i < len; i++) {
            (*this)[i] = (*this)[i] * cnst;
        }

        return (*this);
    }

    ScalarField& ScalarField::operator/=(const double &cnst) {
        if(cnst == 0)
            throw "divided by zero!";

        for(int i = 0, len = all(this->level); i < len; i++) {
            (*this)[i] = (*this)[i] / cnst;
        }

        return (*this);
    }

}

