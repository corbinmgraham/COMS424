CC 		= gcc
FFLAGS 	= -O3 -Wall -Werror
LFFLAG 	=
OBJECTS	= main.o \
		  matrix.o \
		  trimatrix.o \
		  Hessenberg.o \
		  QRA.o \
		  FindZero.o \
		  GetShift.o \
		  QRdecomp.o \

.PHONY: help

all: main.exe

main.exe: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o main.exe

%.o: %.c
	$(CC) $(FFLAGS) -c $<

clean:
	rm -f $(OBJECTS) main.exe

help:
	@echo "make -- Builds targets"
	@echo "clean -- Removes targets"