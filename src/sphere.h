#ifndef __SPHERE_H
#define __SPHERE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Error codes */
#define SPHERE_OK                0
#define SPHERE_ERR               -1

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

/*-----------------------------------------------------------------------------
 * Geometry structure of the HEALPix system
 *----------------------------------------------------------------------------*/

typedef struct node {

} node;

typedef struct ring {

} ring;

typedef struct grid {
};

/*-----------------------------------------------------------------------------
 * Data types
 *----------------------------------------------------------------------------*/

/* A sphere object, that is a type able to hold a string / list / set */



#endif
