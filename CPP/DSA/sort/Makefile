APP_NAME := sort

# Directories
SRC_DIR := src
INC_DIR := include
BUILD_DIR := build
BIN_DIR := bin

# Tools and flags
CXX ?= g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O0 -g3 -ggdb
CPPFLAGS := -I$(INC_DIR)
LDFLAGS :=
LDLIBS :=

# Sources and objects
SRCS := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(filter %.cpp,$(SRCS))) \
        $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(filter %.c,$(SRCS)))
DEPS := $(OBJS:.o=.d)

.PHONY: all clean run debug

all: $(BIN_DIR)/$(APP_NAME)

$(BIN_DIR)/$(APP_NAME): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(LDFLAGS) $(LDLIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -MMD -MP -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -MMD -MP -c $< -o $@

$(BUILD_DIR) $(BIN_DIR):
	mkdir -p $@

run: all
	./$(BIN_DIR)/$(APP_NAME)

debug: all
	gdb ./$(BIN_DIR)/$(APP_NAME)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Include auto-generated dependency files
-include $(DEPS)

