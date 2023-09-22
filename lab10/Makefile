CC = gcc
CFLAGS = -Wall -Werror
TARGETS = main.o rectangle.o quad_area.o quad_perimeter.o

all: program

program: $(TARGETS)
	$(CC) $(CFLAGS) $(TARGETS) -o main.program

%.o: %.c
	$(CC) $(CFLAGS) -c $^

run: all
	./main.program

clean:
	rm *.program *.o