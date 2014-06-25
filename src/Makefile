CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=myvm.c myvm_main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=myvm

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)