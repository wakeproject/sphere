/*
 * sphere.h
 *
 * The declarations for HEALPix index system
 *
 * Wahlque Sphere Project
 *
 * MIT License
 *
 */

#ifndef INDEX_H_
#define INDEX_H_

/* Base paramenters for cell of tessellation */
#define NTHETA                   3
#define NPHI                     4

/* Numbers of power 2 */
#define P0                       1
#define P1                       2
#define P2                       4
#define P3                       8
#define P4                       16
#define P5                       32
#define P6                       64
#define P7                       128
#define P8                       256
#define P9                       512
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

int all(int level);

int ring_by_rind(int level, int index);
int pxir_by_rind(int level, int index);

int rind_by_nind(int level, int index);
int nind_by_rind(int level, int index);

int nind_by_path(int level, int* path);
int* path_by_nind(int level, int index);

}

#endif /* INDEX_H_ */
