# Top level makefile, the real target is at src/Makefile

default: src test

src:
		cd src && $(MAKE) all

test:
		cd test && $(MAKE) all

