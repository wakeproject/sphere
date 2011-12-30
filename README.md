Sphere: A redis-like datastore for timed spherical dataset

## Commandline Commands

 * sph cli
 * sph init
 * sph start
 * sph stop
 * sph part

## Client Commands

### Basic

 * all
 * coord INDEX
 * type KEY
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

