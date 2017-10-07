CFLAGS=-Wall -Werror -g
LDFLAGS=-fPIC
INCDIR=include
INCLUDES=-I$(INCDIR)

INSTPATH=/usr/local

# TODO: add general description here.
OBJS=hex.o vbrnd.o cutils.o vbstring.o

.PHONY: clean test


all: libcutils.so


libcutils.so: $(OBJS)
	gcc $(CFLAGS) -shared -o $@ $(OBJS)
	cp $@ test/
	@echo $@ build successfully

test: libcutils.so
	@cd test; make all LIBOBJ="../$<" INCDIR1=-I../include; cd ..;
			
install: libcutils.so
	@echo "installing libarary $<"
	cp $< $(INSTPATH)/lib/
	cp $(INCDIR)/*.h $(INSTPATH)/include/
	echo "$(INSTPATH)/lib">/etc/ld.so.conf.d/cutils.conf
	ldconfig $(INSTPATH)/lib
	
uninstall:
	@echo "uninstalling libary libcutils.so"
	rm $(INSTPATH)/include/hex.h
	rm $(INSTPATH)/include/vbrnd.h
	rm $(INSTPATH)/include/cutils.h
	rm $(INSTPATH)/include/vbstring.h
	rm $(INSTPATH)/lib/libcutils.so
	ldconfig $(INSTPATH)/lib
	$(RM) /etc/ld.so.conf.d/cutils.conf
	
clean:
	$(RM) *.o
	$(RM) *.so
	@cd test; make clean


# module used for the cutils library
hex.o: hex.c $(INCDIR)/hex.h
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -c -o $@ hex.c

vbrnd.o: vbrnd.c $(INCDIR)/vbrnd.h
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -c -o $@ vbrnd.c

cutils.o: cutils.c $(INCDIR)/cutils.h
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -c -o $@ cutils.c

vbstring.o: vbstring.c $(INCDIR)/vbstring.h
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -c -o $@ vbstring.c
