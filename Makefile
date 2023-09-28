CC := gcc
CFLAGS := -Wall -Werror -O2
LDFLAGS := -shared

SRC_DIR := source
BUILD_DIR := build
LIB_DIR := .

SRC_FILES := $(wildcard *.c)
OBJ_FILES := $(patsubst %.c,%.o,$(SRC_FILES))
STATIC_LIB := libstring.a
SHARED_LIB := libstring.so

.PHONY: all clean

all: $(STATIC_LIB) $(SHARED_LIB)

$(STATIC_LIB): $(OBJ_FILES)
	ar rcs $@ $^

$(SHARED_LIB): $(OBJ_FILES)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	mkdir -p source
	$(CC) $(CFLAGS) -fPIC -c -o $@ $<

clean:
	rm -rf *.o $(STATIC_LIB) $(SHARED_LIB)