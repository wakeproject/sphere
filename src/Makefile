##########################################################################
# This file is part of Sphere project
##########################################################################

CFLAGS=         -W -Wall -std=c99 -pedantic $(TIME) -O2 $(COPT)
LINFLAGS=       -ldl -pthread $(CFLAGS)
TARGETS=        sph sph-cli sph-init sph-part sph-start sph-stop

all:
		$(CC) sph.c -o sph $(LINFLAGS)
		$(CC) sph-cli.c -o sph-cli $(LINFLAGS)
		$(CC) sph-init.c -o sph-init $(LINFLAGS)
		$(CC) sph-part.c -o sph-part $(LINFLAGS)
		$(CC) sph-start.c -o sph-start $(LINFLAGS)
		$(CC) sph-stop.c -o sph-stop $(LINFLAGS)

clean:
		rm -rf *.o $(TARGETS)

install: all
		mkdir -p $(INSTALL_BIN)
		$(INSTALL) sph $(INSTALL_BIN)
		$(INSTALL) sph-cli $(INSTALL_BIN)
		$(INSTALL) sph-init $(INSTALL_BIN)
		$(INSTALL) sph-part $(INSTALL_BIN)
		$(INSTALL) sph-start $(INSTALL_BIN)
		$(INSTALL) sph-stop $(INSTALL_BIN)

