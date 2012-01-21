/*
 * sphere.h
 *
 * The declarations for HEALPix implementation
 *
 * Wahlque Sphere Project
 *
 * MIT License
 *
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include <string>

namespace sphere {

/* Kind */
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

class Vector {
public:
    double x;
    double y;
    double z;
};

class Coord {
public:
    double longitude;
    double latitude;
};

class Sphere;
class Field;
class ZField;
class TField;
class TZField;

Kind kind(Sphere* sphere, std::string key);

void cnst(Sphere* sphere, std::string key, double value);
void zcnst(Sphere* sphere, double height, std::string key, double value);
void tcnst(Sphere* sphere, double time, std::string key, double value);
void tzcnst(Sphere* sphere, double time, double height, std::string key, double value);

double get(Sphere* sphere, Coord coord, std::string key);
void set(Sphere* sphere, Coord coord, std::string key, double value);
double zget(Sphere* sphere, Coord coord, double height, std::string key);
void zset(Sphere* sphere, Coord coord, double height, std::string key, double value);
double tget(Sphere* sphere, Coord coord, double time, std::string key);
void tset(Sphere* sphere, Coord coord, double time, std::string key, double value);
double tzget(Sphere* sphere, Coord coord, double time, double height, std::string key);
void tzset(Sphere* sphere, Coord coord, double time, double height, std::string key, double value);

void zslc(Sphere* sphere, double height, std::string target, std::string source);
void tslc(Sphere* sphere, double time, std::string target, std::string source);
void tzslc(Sphere* sphere, double time, double height, std::string target, std::string source);

void add(Sphere* sphere, std::string target, std::string sources...);
void addt(Sphere* sphere, std::string target, std::string sources...);
void exp(Sphere* sphere, std::string target, std::string source, double ratio);
void expt(Sphere* sphere, std::string target, double ratio);
void zadd(Sphere* sphere, double height, std::string target, std::string sources...);
void zaddt(Sphere* sphere, double height, std::string target, std::string sources...);
void zexp(Sphere* sphere, double height, std::string target, std::string source, double ratio);
void zexpt(Sphere* sphere, double height, std::string target, double ratio);
void tadd(Sphere* sphere, double time, std::string target, std::string sources...);
void taddt(Sphere* sphere, double time, std::string target, std::string sources...);
void texp(Sphere* sphere, double time, std::string target, std::string source, double ratio);
void texpt(Sphere* sphere, double time, std::string target, double ratio);
void tzadd(Sphere* sphere, double time, double height, std::string target, std::string sources...);
void tzaddt(Sphere* sphere, double time, double height, std::string target, std::string sources...);
void tzexp(Sphere* sphere, double time, double height, std::string target, std::string source, double ratio);
void tzexpt(Sphere* sphere, double time, double height, std::string target, double ratio);

void grad(Sphere* sphere, std::string target, std::string source);
void div(Sphere* sphere, std::string target, std::string source);
void rot(Sphere* sphere, std::string target, std::string source);
void zgrad(Sphere* sphere, double height, std::string target, std::string source);
void zdiv(Sphere* sphere, double height, std::string target, std::string source);
void zrot(Sphere* sphere, double height, std::string target, std::string source);
void tgrad(Sphere* sphere, double time, std::string target, std::string source);
void tdiv(Sphere* sphere, double time, std::string target, std::string source);
void trot(Sphere* sphere, double time, std::string target, std::string source);
void tzgrad(Sphere* sphere, double time, double height, std::string target, std::string source);
void tzdiv(Sphere* sphere, double time, double height, std::string target, std::string source);
void tzrot(Sphere* sphere, double time, double height, std::string target, std::string source);

double max(Sphere* sphere, std::string key);
double min(Sphere* sphere, std::string key);
double sum(Sphere* sphere, std::string key);
double avg(Sphere* sphere, std::string key);

}

#endif /* SPHERE_H_ */
