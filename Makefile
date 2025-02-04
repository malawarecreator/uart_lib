# Toolchain
CC = xtensa-esp32-elf-gcc
AR = xtensa-esp32-elf-ar

# Compiler flags
CFLAGS = -mlongcalls -Wall -g -Iinclude

# Source and output directories
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Library name
LIB_NAME = libuart.a
LIB = $(LIB_DIR)/$(LIB_NAME)

# Default target
all: $(LIB)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create the static library
$(LIB): $(OBJS)
	@mkdir -p $(LIB_DIR)
	$(AR) rcs $@ $^

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR)

.PHONY: all clean
