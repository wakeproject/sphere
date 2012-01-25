/*
 * sphere-geoind.h
 *
 * The declarations for HEALPix geo-index system
 *
 * Wahlque Sphere Project
 *
 * MIT License
 *
 */

#ifndef GEOIND_H_
#define GEOIND_H_

namespace sphere {

    double z_by_ring(int level, int ring);
    double phi_by_pxir(int level, int ring, int pxir);

}


#endif /* GEOIND_H_ */
