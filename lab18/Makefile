CC 		= gcc
FFLAGS = -Wall -std=c99 -Xpreprocessor -fopenmp
LFLAGS = -lomp
OBJECTS	= main.o \
		  matrix.o \

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