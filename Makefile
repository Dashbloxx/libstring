CC := gcc
CFLAGS := -Wall -Werror -O2
LDFLAGS := -shared

SRC_DIR := source
BUILD_DIR := build
LIB_DIR := .

SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,source/%.o,$(SRC_FILES))
STATIC_LIB := libstring.a
SHARED_LIB := libstring.so

.PHONY: all clean

all: $(STATIC_LIB) $(SHARED_LIB)

$(STATIC_LIB): $(OBJ_FILES)
	ar rcs $@ $^

$(SHARED_LIB): $(OBJ_FILES)
	$(CC) $(LDFLAGS) -o $@ $^

source/%.o: $(SRC_DIR)/%.c
	mkdir -p source
	$(CC) $(CFLAGS) -fPIC -c -o $@ $<

clean:
	rm -rf source/*.o $(STATIC_LIB) $(SHARED_LIB)