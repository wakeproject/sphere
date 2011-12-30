Sphere: A redis-like datastore for timed spherical dataset

## Commands

 * sph init
 * sph up
 * sph downd
 * sph start
 * sph stop
 * sph part

## CLI Commands

### Basic

 * all
 * coord INDEX
 * get COORD KEY
 * set COORD KEY VALUE

### Time ordered data

 * tget TIME COORD KEY
 * tset TIME COORD KEY VALUE

### Field operator

 * grad KEY1 KEY2
 * tgrad TIME KEY1 KEY2

 * rot KEY1 KEY2
 * trot TIME KEY1 KEY2

 * div KEY1 KEY2
 * tdiv TIME KEY1 KEY2

### Hidden commands

 * _rget INDEX KEY
 * _rset INDEX KEY VALUE
 * _nget INDEX KEY
 * _nget INDEX KEY VALUE
 * _rind COORD
 * _nind COORD
 * _rcoord INDEX
 * _ncoord INDEX


