CC=gcc
CFLAGS=-std=c99 -O2 -Wall -Wextra
LIBS=-lpcap
	
SOURCES=$(filter-out service.c,$(wildcard *.c)) $(wildcard utils/*.c)
OBJECTS=$(SOURCES:.c=.o)
TARGET=goodbyedpi

all: $(TARGET)
	
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
