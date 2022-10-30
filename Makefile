IDIR =includes
CC=g++
CFLAGS=-I$(IDIR)

ODIR=obj

_DEPS = insertion_sort.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = tester.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tester: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
