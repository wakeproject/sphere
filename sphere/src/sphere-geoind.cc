/*
 * sphere-geoind.cc
 *
 * The implementation for HEALPix geo-index system
 *
 * Wahlque Sphere Project
 *
 * MIT License
 *
 */

#define _USE_MATH_DEFINES
#include <math.h>
#include "sphere-index.h"
#include "sphere-geoind.h"

namespace sphere {

    double z_by_ring(int level, int ring) {
        int size = power(level);

        if (ring <= size) {
            return 1.0 - ((double)(ring * ring)) / size / size / 3;
        } else if (ring <= 3 * size) {
            return 4.0 / 3.0 - 2.0 * ring / size / 3;
        } else if (ring < 4 * size) {
            int dual = 4 * size - ring;
            return 1.0 - ((double)(dual * dual)) / size / size / 3;
        }

        return 0.0 / 0.0;
    }

    double phi_by_pxir(int level, int ring, int pxir) {
        int size = power(level);

        if (ring <= size) {
            return ((double)M_PI) / 2 / ring * (pxir - 1.0 / 2);
        } else if (ring <= 3 * size) {
            int s = (ring - size + 1) % 2;
            return  ((double)M_PI) / 2 / size * (pxir - s / 2.0);
        } else if (ring < 4 * size) {
            int dual = 4 * size - ring;
            return ((double)M_PI) / 2 / dual * (pxir - 1.0 / 2);
        }

        return 0.0 / 0.0;
    }

}

