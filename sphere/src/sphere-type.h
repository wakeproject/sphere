/*
 * sphere-type.h
 *
 * The declarations for HEALPix implementation
 *
 * Wahlque Sphere Project
 *
 * MIT License
 *
 */

#ifndef TYPE_H_
#define TYPE_H_

#include <cstddef>

namespace sphere {

    enum Kind {
        S,   // scalar field on surface
        ZS,  // scalar field on surface varying with z-axis
        TS,  // scalar field on surface varying with time
        TZS, // scalar field on surface varying with z-axis and time
        V,   // vector field on surface
        ZV,  // vector field on surface varying with z-axis
        TV,  // vector field on surface varying with time
        TZV  // vector field on surface varying with z-axis and time
    };

    class Coord {
    public:
        double longitude;
        double latitude;
    };

    class Vector {
    public:
        double x;
        double y;
        double z;
        Vector(double x=0, double y=0, double z=0);
        static Vector* ZERO;
        Vector& operator+=(const Vector &rhs);
        Vector& operator-=(const Vector &rhs);
        Vector& operator*=(const double &cnst);
        Vector& operator/=(const double &cnst);
    };

    template <typename T> class Z {
    public:
        Z(int level=32, const T cnst=T());
        Z(const Z<T>& orignal);
        ~Z();

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

        virtual Z<T>& operator=(const Z<T> &rhs);

        virtual Z<T>& operator+=(const Z<T> &rhs);

        virtual Z<T>& operator-=(const Z<T> &rhs);

        virtual Z<T>& operator*=(const double &cnst);

        virtual Z<T>& operator/=(const double &cnst);

        int level;
        T* data;
    };

    template <typename K> class T {
    public:
        T(int level=8, const K cnst=K());
        T(const T<K>& orignal);
        ~T();

        struct proxy {
            K& element;

            proxy(K& el) : element(el) {}

            operator const K& () const {
                return element; // For use on RHS of assignment
            };

            proxy& operator=(const K &rhs) {
                element = rhs; // For use on LHS of assignment
            };
        };

        const proxy operator[](int index) const;

        proxy operator[](int index);

        virtual T<K>& operator=(const T<K> &rhs);

        virtual T<K>& operator+=(const T<K> &rhs);

        virtual T<K>& operator-=(const T<K> &rhs);

        virtual T<K>& operator*=(const double &cnst);

        virtual T<K>& operator/=(const double &cnst);

        int level;
        K* data;
    };

    class ScalarZ : public Z<double> {
    public:
        ScalarZ(int level=32, const double cnst=0);
        ScalarZ(const Z<double> & orignal);
        ~ScalarZ();
        const Z<double>::proxy operator[](int index) const;
        Z<double>::proxy operator[](int index);
        ScalarZ& operator+=(const ScalarZ &rhs);
        ScalarZ& operator-=(const ScalarZ &rhs);
    };

    class ScalarT : public T<double> {
    public:
        ScalarT(int level=8, const double cnst=0);
        ScalarT(const T<double> & orignal);
        ~ScalarT();
        const T<double>::proxy operator[](int index) const;
        T<double>::proxy operator[](int index);
        ScalarT& operator+=(const ScalarT &rhs);
        ScalarT& operator-=(const ScalarT &rhs);
    };

    class ScalarTZ : public T<ScalarZ> {
    public:
        ScalarTZ(int level=8, const ScalarZ cnst=ScalarZ());
        ScalarTZ(const T<ScalarZ> & orignal);
        ~ScalarTZ();
        const T<ScalarZ>::proxy operator[](int index) const;
        T<ScalarZ>::proxy operator[](int index);
        ScalarTZ& operator+=(const ScalarTZ &rhs);
        ScalarTZ& operator-=(const ScalarTZ &rhs);
    };

    class VectorZ : public Z<Vector> {
    public:
        VectorZ(int level=32, const Vector cnst=Vector(0, 0, 0));
        VectorZ(const Z<Vector>& orignal);
        ~VectorZ();
        const Z<Vector>::proxy operator[](int index) const;
        Z<Vector>::proxy operator[](int index);
        VectorZ& operator+=(const VectorZ &rhs);
        VectorZ& operator-=(const VectorZ &rhs);
   };

    class VectorT : public T<Vector> {
    public:
        VectorT(int level=8, const Vector cnst=Vector(0, 0, 0));
        VectorT(const T<Vector>& orignal);
        ~VectorT();
        const T<Vector>::proxy operator[](int index) const;
        T<Vector>::proxy operator[](int index);
        VectorT& operator+=(const VectorT &rhs);
        VectorT& operator-=(const VectorT &rhs);
   };

    class VectorTZ : public T<VectorZ> {
    public:
        VectorTZ(int level=8, const VectorZ cnst=VectorZ());
        VectorTZ(const T<VectorZ> & orignal);
        ~VectorTZ();
        const T<VectorZ>::proxy operator[](int index) const;
        T<VectorZ>::proxy operator[](int index);
        VectorTZ& operator+=(const VectorTZ &rhs);
        VectorTZ& operator-=(const VectorTZ &rhs);
    };

}

#endif /* TYPE_H_ */
