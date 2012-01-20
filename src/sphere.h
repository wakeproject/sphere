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

/* Base paramenters for cell of tessellation */
#define NTHETA                   3
#define NPHI                     4

/* Numbers of power 2 */
#define P0                       1
#define P1                       2
#define P3                       4
#define P4                       8
#define P5                       16
#define P6                       32
#define P7                       64
#define P8                       128
#define P9                       256
#define P10                      1024
#define P11                      2048
#define P12                      4096
#define P13                      8192

/* Scale numbers */
#define N0                       12
#define N1                       48
#define N2                       192
#define N3                       768
#define N4                       3072
#define N5                       12288
#define N6                       49152
#define N7                       196608
#define N8                       786432
#define N9                       3145728
#define N10                      12582912
#define N11                      50331648
#define N12                      201326592
#define N13                      805306368

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

int* gen_by_rind(int level);
int* gen_by_nind(int level, int parts...);
int* gen_by_pind(int level);
int** all_by_rind(int level);
int** all_by_nind(int level, int parts...);
int** all_by_pind(int level);

int* ring_by_nind(int level, int* index);
int* ring_by_pind(int level, int* index);
int* nind_by_rind(int level, int* index);
int* nind_by_pind(int level, int* index);
int* pind_by_rind(int level, int* index);
int* pind_by_nind(int level, int* index);

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
