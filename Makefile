# Top level makefile

default: all

.DEFAULT:
	cd test && $(MAKE) $@

install:
	cd test && $(MAKE) $@

.PHONY: install
