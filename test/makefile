CC=gcc
CFLAGS=-Wall -Werror -g
INCLUDES=include

# TODO: add general description here.
OBJBASE=$(INCLUDES)/modtest.h $(INCLUDES)/modules.h

# TODO: add description about INCDIR1
INCDIR=-I$(INCLUDES) $(INCDIR1)


# Test framework modules
OBJS0=runtest.o utils.o modtest.o

# List of modulles which interact with the test library
OBJS1=hextest.o vbrndtest.o cutilstest.o vbstringtest.o



.PHONY: clean


all: runtest
	@echo runtest compiled successfully


runtest: $(OBJS0) $(OBJS1)
	$(CC) $(CFLAGS) -L./ -Wl,-rpath=./ -lcutils -o $@ $(OBJS0) $(OBJS1)

clean:
	$(RM) runtest
	$(RM) *.o
	$(RM) *.so

.c.o:
	$(CC) $(CFLAGS) $(INCDIR) -c -o $@ $<


# Test framework
runtest.o: runtest.c $(INCLUDES)/utils.h $(OBJBASE)

utils.o: utils.c $(INCLUDES)/utils.h

modtest.o: modtest.c $(INCLUDES)/modtest.h $(INCLUDES)/utils.h


# Test modules:
hextest.o: hextest.c $(OBJBASE)

vbrndtest.o: vbrndtest.c $(OBJBASE)

cutilstest.o: cutilstest.c $(OBJBASE)

vbstringtest.o: vbstringtest.c $(OBJBASE)

