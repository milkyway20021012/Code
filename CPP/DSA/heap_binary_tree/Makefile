# Project Makefile for heap_binary_tree

# Compiler and tools
CC ?= clang

# Directories
SRC_DIR := src
INC_DIR := include
BUILD_DIR := build
BIN_DIR := bin

# Target binary name
TARGET := $(BIN_DIR)/heap_demo

# Sources and derived objects/deps
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

# Common flags
CPPFLAGS := -MMD -MP -I$(INC_DIR)
CFLAGS_COMMON := -Wall -Wextra -Werror -std=c11
LDFLAGS :=

# Build-type specific flags
DEBUG_FLAGS := -O0 -g -DDEBUG
RELEASE_FLAGS := -O2 -DNDEBUG

.PHONY: all debug release run clean help

# Default target
all: debug

# Debug build
debug: CFLAGS := $(CFLAGS_COMMON) $(DEBUG_FLAGS)
debug: $(TARGET)

# Release build
release: CFLAGS := $(CFLAGS_COMMON) $(RELEASE_FLAGS)
release: $(TARGET)

# Link
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# Compile
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Ensure directories
$(BUILD_DIR) $(BIN_DIR):
	mkdir -p $@

# Run the program (builds debug by default)
run: debug
	$(TARGET)

# Remove build artifacts
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Helpful info
help:
	@echo "Available targets:"
	@echo "  make debug    - Build with debug info (-g, -O0)"
	@echo "  make release  - Build with optimizations (-O2)"
	@echo "  make run      - Build (debug) and run the program"
	@echo "  make clean    - Remove build and binary directories"

# Auto-include dependency files
-include $(DEPS)

