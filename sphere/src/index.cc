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

#include "index.h"

namespace sphere {

    int scale(int level) {
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
        else: return -1;
        };
    }

}
