CC = gcc
FFLAGS = -O3 -Wall
LFFLAG =
OBJECTS = main.o \
Option.o \
DisplayOptions.o \
Push.o \
Pop.o \
Peek.o \
DisplayStack.o \
GetStackSize.o \
DeleteStack.o \
Temp.o \
AddLayer.o \
BodyTemp.o \

.PHONY : clean help

main.exe: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o main.exe

%.o: %.c
	$(CC) $(FFLAGS) -c $<

clean:
	rm -f $(OBJECTS) main.exe