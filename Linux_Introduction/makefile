#define the C compiler to use
CC = gcc
#define compiler flags
CFLAGS 	= -std=c11 -Wall -fmax-errors=10 -Wextra
#define library paths in additions to /usr/lib
LFLAGS = -L.
#define libraries to use
LIBS = -lweather
#define the object files that this project needs
OBJFILES = program.o weatherstats.o
#define the name of the executable file
MAIN = program

#all of the code below is generic

all: $(MAIN)

$(MAIN): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJFILES)

%.o: %.C
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJFILES) $(MAIN)

launch: program
	./program

