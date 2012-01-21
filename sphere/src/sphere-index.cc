/*
 * sphere.c
 *
 * The implemntations for HEALPix index system
 *
 * Wahlque Sphere Project
 *
 * MIT License
 *
 */

#include <math.h>
#include "sphere-index.h"

namespace sphere {

    int power(int level) {
        switch (level) {
        case 0: return P0;
        case 1: return P1;
        case 2: return P2;
        case 3: return P3;
        case 4: return P4;
        case 5: return P5;
        case 6: return P6;
        case 7: return P7;
        case 8: return P8;
        case 9: return P9;
        case 10: return P10;
        case 11: return P11;
        case 12: return P12;
        case 13: return P13;
        default: return -1;
        };
    }

    int all(int level) {
        switch (level) {
        case 0: return N0;
        case 1: return N1;
        case 2: return N2;
        case 3: return N3;
        case 4: return N4;
        case 5: return N5;
        case 6: return N6;
        case 7: return N7;
        case 8: return N8;
        case 9: return N9;
        case 10: return N10;
        case 11: return N11;
        case 12: return N12;
        case 13: return N13;
        default: return -1;
        };
    }

    int ring_by_rind(int level, int index) {
        int ring = -1,
            size = power(level),
            ncap = 2 * size * (size - 1),
            nblt = ncap + 4 * size * size,
            equt = nblt + 4 * size,
            sblt = 12 * size * size - ncap,
            scap = 12 * size * size;

        if (index < 0) {
            return ring;
        } else if (index < ncap) {
            float half = (index + 1.0) / 2.0;
            ring = 1 + floor(sqrt(half - sqrt(floor(half))));
            return ring;
        } else if (index < nblt) {
            index = index - ncap;
            ring = size + floor(index / 4.0 / size);
            return ring;
        } else if (index < equt) {
            index = index - ncap;
            ring = size + floor(index / 4.0 / size);
            return ring;
        } else if (scap < index) {
            return ring;
        } else if (sblt < index) {
            index = scap - index - 1;
            float half = (index + 1.0) / 2.0;
            ring = 4 * size - 1 - floor(sqrt(half - sqrt(floor(half))));
            return ring;
        } else if (equt <= index) {
            index = index - equt;
            ring = 2 * size + 1 + floor(index / 4.0 / size);
            return ring;
        }

        return ring;
    }

    int pxir_by_rind(int level, int index) {
        int pxir = -1,
            size = power(level),
            ncap = 2 * size * (size - 1),
            scap = 12 * size * size,
            ring = ring_by_rind(level, index);

        if (ring < 0) {
            return pxir;
        } else if (ring <= size) {
            pxir = index + 1 - 2 * ring * (ring - 1);
            return pxir;
        } else if (ring <= 3 * size) {
            index = index - ncap;
            pxir = 1 + index % (4 * size);
            return pxir;
        } else if (ring < 4 * size) {
            int dual = 4 * size - ring;
            pxir = 4 * dual - (scap - index - 1 - 2 * dual * (dual - 1));
            return pxir;
        }

        return pxir;
    }

}
