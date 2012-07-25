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

#include "sphere-type.h"

namespace sphere {

    Vector::Vector(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    };

    Vector* Vector::ZERO = new Vector();

    Vector& Vector::operator+=(const Vector &rhs) {
        this->x = this->x + rhs.x;
        this->y = this->y + rhs.y;
        this->z = this->z + rhs.z;

        return (*this);
    }

    Vector& Vector::operator-=(const Vector &rhs) {
        this->x = this->x - rhs.x;
        this->y = this->y - rhs.y;
        this->z = this->z - rhs.z;

        return (*this);
    }

    Vector& Vector::operator*=(const double &cnst) {
        this->x = this->x * cnst;
        this->y = this->y * cnst;
        this->z = this->z * cnst;

        return (*this);
    }

    Vector& Vector::operator/=(const double &cnst) {
        this->x = this->x / cnst;
        this->y = this->y / cnst;
        this->z = this->z / cnst;

        return (*this);
    }

    template <typename T>
    Z<T>::Z(int level, const T cnst) {
        this->level = level;
        this->data = new T[this->level];

        for (int i = 0; i < this->level; i++) {
            this->data[i] = cnst;
        }
    };

    template <typename T>
    Z<T>::Z(const Z<T>::Z<T>& orignal) {
        this->level = orignal.level;
        this->data = new T[this->level];

        for (int i = 0; i < this->level; i++) {
            this->data[i] = orignal.data[i];
        }
    };

    template <typename T>
    Z<T>::~Z() {
        delete [] this->data;
        this->data = NULL;
    };

    template <typename T>
    Z<T>& Z<T>::operator=(const Z<T> &rhs) {
        if (this == &rhs)
            return *this;

        if (this->data != NULL)
            delete [] this->data;

        this->level = rhs.level;
        this->data = new T[this->level];

        for (int i = 0; i < this->level; i++) {
            this->data[i] = rhs.data[i];
        }

        return *this;
    };

    template <typename T>
    const typename Z<T>::proxy Z<T>::operator[](int index) const {
        int size = this->level;
        index = index % size;
        if (index < 0) index = index + size;
        return proxy(this->data[index]);
    };

    template <typename T>
    typename Z<T>::proxy Z<T>::operator[](int index) {
        int size = this->level;
        index = index % size;
        if (index < 0) index = index + size;
        return proxy(this->data[index]);
    };

    template <typename T>
    Z<T>& Z<T>::operator+=(const Z<T> &rhs) {
        if(this->level != rhs.level)
            throw "granularity of the two fields is mismatched!";

        for(int i = 0, len = this->level; i < len; i++) {
            this->data[i] += rhs.data[i];
        }

        return (*this);
    };

    template <typename T>
    Z<T>& Z<T>::operator-=(const Z<T> &rhs) {
        if(this->level != rhs.level)
            throw "granularity of the two fields is mismatched!";

        for(int i = 0, len = this->level; i < len; i++) {
            this->data[i] -= rhs.data[i];
        }

        return (*this);
    };

    template <typename T>
    Z<T>& Z<T>::operator*=(const double &cnst) {
        for(int i = 0, len = this->level; i < len; i++) {
            this->data[i] *= cnst;
        }

        return (*this);
    };

    template <typename T>
    Z<T>& Z<T>::operator/=(const double &cnst) {
        if(cnst == 0)
            throw "divided by zero!";

        for(int i = 0, len = this->level; i < len; i++) {
            this->data[i] /= cnst;
        }

        return (*this);
    };

    template <typename K>
    T<K>::T(int level, const K cnst) {
        this->level = level;
        this->data = new K[this->level];

        for (int i = 0; i < this->level; i++) {
            this->data[i] = cnst;
        }
    };

    template <typename K>
    T<K>::T(const T<K>::T<K>& orignal) {
        this->level = orignal.level;
        this->data = new K[this->level];

        for (int i = 0; i < this->level; i++) {
            this->data[i] = orignal.data[i];
        }
    };

    template <typename K>
    T<K>::~T() {
        delete [] this->data;
        this->data = NULL;
    };

    template <typename K>
    T<K>& T<K>::operator=(const T<K> &rhs) {
        if (this == &rhs)
            return *this;

        if (this->data != NULL)
            delete [] this->data;

        this->level = rhs.level;
        this->data = new K[this->level];

        for (int i = 0; i < this->level; i++) {
            this->data[i] = rhs.data[i];
        }

        return *this;
    };

    template <typename K>
    const typename T<K>::proxy T<K>::operator[](int index) const {
        int size = this->level;
        index = index % size;
        if (index < 0) index = index + size;
        return proxy(this->data[index]);
    };

    template <typename K>
    typename T<K>::proxy T<K>::operator[](int index) {
        int size = this->level;
        index = index % size;
        if (index < 0) index = index + size;
        return proxy(this->data[index]);
    };

    template <typename K>
    T<K>& T<K>::operator+=(const T<K> &rhs) {
        if(this->level != rhs.level)
            throw "granularity of the two fields is mismatched!";

        for(int i = 0, len = this->level; i < len; i++) {
            this->data[i] += rhs.data[i];
        }

        return (*this);
    };

    template <typename K>
    T<K>& T<K>::operator-=(const T<K> &rhs) {
        if(this->level != rhs.level)
            throw "granularity of the two fields is mismatched!";

        for(int i = 0, len = this->level; i < len; i++) {
            this->data[i] -= rhs.data[i];
        }

        return (*this);
    };

    template <typename K>
    T<K>& T<K>::operator*=(const double &cnst) {
        for(int i = 0, len = this->level; i < len; i++) {
            this->data[i] *= cnst;
        }

        return (*this);
    };

    template <typename K>
    T<K>& T<K>::operator/=(const double &cnst) {
        if(cnst == 0)
            throw "divided by zero!";

        for(int i = 0, len = this->level; i < len; i++) {
            this->data[i] /= cnst;
        }

        return (*this);
    };

    ScalarZ::ScalarZ(int level, const double cnst) : Z<double> (level, cnst) {
    }

    ScalarZ::ScalarZ(const Z<double>& orignal) : Z<double> (orignal) {
    }

    ScalarZ::~ScalarZ() {
    }

    const Z<double>::proxy ScalarZ::operator[](int index) const {
        return (*((Z<double>*) this))[index];
    }

    Z<double>::proxy ScalarZ::operator[](int index) {
        return (*((Z<double>*) this))[index];
    }

    ScalarZ& ScalarZ::operator+=(const ScalarZ &rhs) {
        (*((Z<double>*) this)) += rhs;
        return (*this);
    }

    ScalarZ& ScalarZ::operator-=(const ScalarZ &rhs) {
        (*((Z<double>*) this)) -= rhs;
        return (*this);
    }

    VectorZ::VectorZ(int level, const Vector cnst) : Z<Vector> (level, cnst) {
    }

    VectorZ::VectorZ(const Z<Vector>& orignal) : Z<Vector> (orignal) {
    }

    VectorZ::~VectorZ() {
    }

    const Z<Vector>::proxy VectorZ::operator[](int index) const {
        return (*((Z<Vector>*) this))[index];
    }

    Z<Vector>::proxy VectorZ::operator[](int index) {
        return (*((Z<Vector>*) this))[index];
    }

    VectorZ& VectorZ::operator+=(const VectorZ &rhs) {
        (*((Z<Vector>*) this)) += rhs;
        return (*this);
    }

    VectorZ& VectorZ::operator-=(const VectorZ &rhs) {
        (*((Z<Vector>*) this)) -= rhs;
        return (*this);
    }

    ScalarT::ScalarT(int level, const double cnst) : T<double> (level, cnst) {
    }

    ScalarT::ScalarT(const T<double>& orignal) : T<double> (orignal) {
    }

    ScalarT::~ScalarT() {
    }

    const T<double>::proxy ScalarT::operator[](int index) const {
        return (*((T<double>*) this))[index];
    }

    T<double>::proxy ScalarT::operator[](int index) {
        return (*((T<double>*) this))[index];
    }

    ScalarT& ScalarT::operator+=(const ScalarT &rhs) {
        (*((T<double>*) this)) += rhs;
        return (*this);
    }

    ScalarT& ScalarT::operator-=(const ScalarT &rhs) {
        (*((T<double>*) this)) -= rhs;
        return (*this);
    }

    VectorT::VectorT(int level, const Vector cnst) : T<Vector> (level, cnst) {
    }

    VectorT::VectorT(const T<Vector>& orignal) : T<Vector> (orignal) {
    }

    VectorT::~VectorT() {
    }

    const T<Vector>::proxy VectorT::operator[](int index) const {
        return (*((T<Vector>*) this))[index];
    }

    T<Vector>::proxy VectorT::operator[](int index) {
        return (*((T<Vector>*) this))[index];
    }

    VectorT& VectorT::operator+=(const VectorT &rhs) {
        (*((T<Vector>*) this)) += rhs;
        return (*this);
    }

    VectorT& VectorT::operator-=(const VectorT &rhs) {
        (*((T<Vector>*) this)) -= rhs;
        return (*this);
    }

    ScalarTZ::ScalarTZ(int level, const ScalarZ cnst) : T<ScalarZ> (level, cnst) {
    }

    ScalarTZ::ScalarTZ(const T<ScalarZ>& orignal) : T<ScalarZ> (orignal) {
    }

    ScalarTZ::~ScalarTZ() {
    }

    const T<ScalarZ>::proxy ScalarTZ::operator[](int index) const {
        return (*((T<ScalarZ>*) this))[index];
    }

    T<ScalarZ>::proxy ScalarTZ::operator[](int index) {
        return (*((T<ScalarZ>*) this))[index];
    }

    ScalarTZ& ScalarTZ::operator+=(const ScalarTZ &rhs) {
        (*((T<ScalarZ>*) this)) += rhs;
        return (*this);
    }

    ScalarTZ& ScalarTZ::operator-=(const ScalarTZ &rhs) {
        (*((T<ScalarZ>*) this)) -= rhs;
        return (*this);
    }

    VectorTZ::VectorTZ(int level, const VectorZ cnst) : T<VectorZ> (level, cnst) {
    }

    VectorTZ::VectorTZ(const T<VectorZ>& orignal) : T<VectorZ> (orignal) {
    }

    VectorTZ::~VectorTZ() {
    }

    const T<VectorZ>::proxy VectorTZ::operator[](int index) const {
        return (*((T<VectorZ>*) this))[index];
    }

    T<VectorZ>::proxy VectorTZ::operator[](int index) {
        return (*((T<VectorZ>*) this))[index];
    }

    VectorTZ& VectorTZ::operator+=(const VectorTZ &rhs) {
        (*((T<VectorZ>*) this)) += rhs;
        return (*this);
    }

    VectorTZ& VectorTZ::operator-=(const VectorTZ &rhs) {
        (*((T<VectorZ>*) this)) -= rhs;
        return (*this);
    }
}

