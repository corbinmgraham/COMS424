COMPILER = gcc
CFLAGS = -Wall -Wextra

TARGETS = chebyshev

run: all
	./$(TARGETS).program

all: $(TARGETS)

$(TARGETS):
	$(COMPILER) $(CFLAGS) $(TARGETS).c -o $(TARGETS).program

clean:
	rm *.program
