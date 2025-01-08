CC = gcc
CFLAGS = -Wall -Wextra -pedantic -O2 -Iinclude
LDFLAGS = -shared
AR = ar
ARFLAGS = rcs

SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
LIB_DIR = lib

SRC = $(SRC_DIR)/gabby.c
OBJ = $(BUILD_DIR)/gabby.o
STATIC_LIB = $(LIB_DIR)/libgabby.a
SHARED_LIB = $(LIB_DIR)/libgabby.so

all: $(STATIC_LIB) $(SHARED_LIB)

$(BUILD_DIR) $(LIB_DIR):
	mkdir -p $@

$(STATIC_LIB): $(OBJ) | $(LIB_DIR)
	$(AR) $(ARFLAGS) $@ $^

$(SHARED_LIB): $(OBJ) | $(LIB_DIR)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ): $(SRC) $(INCLUDE_DIR)/gabby.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(LIB_DIR)

install: all
	install -m 0755 $(STATIC_LIB) /usr/local/lib/
	install -m 0755 $(SHARED_LIB) /usr/local/lib/
	install -m 0644 $(INCLUDE_DIR)/gabby.h /usr/local/include/

uninstall:
	rm -f /usr/local/lib/libgabby.a
	rm -f /usr/local/lib/libgabby.so
	rm -f /usr/local/include/gabby.h

.PHONY: all clean install uninstall
