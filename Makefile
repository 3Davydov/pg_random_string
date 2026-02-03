# contrib/random_string/Makefile

MODULES = random_string

OBJS = \
	$(WIN32RES) \
	random_string.o

EXTENSION = random_string
DATA = random_string--1.0.sql
PGFILEDESC = "random_string - functions for generating random strings"

ifdef USE_PGXS
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
else
subdir = contrib/random_string
top_builddir = ../..
include $(top_builddir)/src/Makefile.global
include $(top_srcdir)/contrib/contrib-global.mk
endif
