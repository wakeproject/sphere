##########################################################################
# This file is part of Sphere project
##########################################################################

INCL    = -I$(INCL_DIR)
DEFS    = -D_DEBUG_ -W -Wall -std=c++11 -pedantic -O2 $(COPT)
CFLAGS  = -g $(INCL) $(DEFS)
LFLAGS  = -L./ -ldl -pthread $(CFLAGS)

BIN =  sph sph-cli sph-help sph-init sph-part sph-start sph-stop

all: $(BIN)

$(BIN):
		$(CC) $(CFLAGS) $@.c $(LFLAGS) -o $@

clean:
		rm -rf *.o ${BIN}

install: all
		mkdir -p $(INSTALL_BIN)
		$(INSTALL) sph-cli $(INSTALL_BIN)
		$(INSTALL) sph-help $(INSTALL_BIN)
		$(INSTALL) sph-init $(INSTALL_BIN)
		$(INSTALL) sph-part $(INSTALL_BIN)
		$(INSTALL) sph-start $(INSTALL_BIN)
		$(INSTALL) sph-stop $(INSTALL_BIN)
		$(INSTALL) sph $(INSTALL_BIN)

