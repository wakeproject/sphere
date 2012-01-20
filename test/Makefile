# Top level makefile, the real target is at src/Makefile

INCL    = -I/home/mingli/dev/wahlque/sphere/cxxtest -I$(INCL_DIR)
DEFS    = -D_DEBUG_ -W -Wall -pedantic -O2 $(COPT)
CFLAGS  = -g $(INCL) $(DEFS)
LFLAGS  = -L./ -ldl -pthread $(CFLAGS)

TEST    = test_index

all: $(TEST)

$(TEST):
		../cxxtest/bin/cxxtestgen --error-printer -o $@.cc $@.h
		$(CC) $(CFLAGS) $@.cc $(LFLAGS) -o $@
		$@



