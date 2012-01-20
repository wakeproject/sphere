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

int scale(int level);

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

}

#endif /* INDEX_H_ */
