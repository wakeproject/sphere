##########################################################################
# This file is part of Sphere project
##########################################################################

CFLAGS=         -W -Wall -std=c99 -pedantic -O2 $(COPT)
LINFLAGS=       -ldl -pthread $(CFLAGS)

# Make sure that the compiler flags come last in the compilation string.
# If not so, this can break some on some Linux distros which use
# "-Wl,--as-needed" turned on by default  in cc command.
# Also, this is turned in many other distros in static linkage builds.
all:
        $(CC) sph.c -o sph $(LINFLAGS)
        $(CC) sph-cli.c -o sph-cli $(LINFLAGS)
        $(CC) sph-down.c -o sph-down $(LINFLAGS)
        $(CC) sph-init.c -o sph-init $(LINFLAGS)
        $(CC) sph-part.c -o sph-part $(LINFLAGS)
        $(CC) sph-start.c -o sph-start $(LINFLAGS)
        $(CC) sph-stop.c -o sph-stop $(LINFLAGS)
        $(CC) sph-up.c -o sph-up $(LINFLAGS)

clean:
        rm -rf *.o sph sph-cli sph-down sph-init sph-part sph-start sph-stop sph-up
