# Compilers and flags
CC := gcc
CXX := g++
INC_DIR := include
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin
TARGET := $(BIN_DIR)/app

# Default: debug build suitable for VS Code debugging
CFLAGS_DEBUG := -std=c11 -g -O0 -Wall -Wextra -I$(INC_DIR)
CXXFLAGS_DEBUG := -std=c++17 -g -O0 -Wall -Wextra -I$(INC_DIR)
CFLAGS_RELEASE := -std=c11 -O2 -DNDEBUG -Wall -Wextra -I$(INC_DIR)
CXXFLAGS_RELEASE := -std=c++17 -O2 -DNDEBUG -Wall -Wextra -I$(INC_DIR)

# Sources and objects
CPP_SRCS := $(wildcard $(SRC_DIR)/*.cpp)
C_SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(CPP_SRCS)) \
        $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(C_SRCS))

# Choose linker: use C++ linker if any C++ sources exist
LINK := $(CC)
ifneq ($(strip $(CPP_SRCS)),)
LINK := $(CXX)
endif

.PHONY: all debug release run clean

all: debug

debug: CFLAGS := $(CFLAGS_DEBUG)
debug: CXXFLAGS := $(CXXFLAGS_DEBUG)
debug: dirs $(TARGET)

release: CFLAGS := $(CFLAGS_RELEASE)
release: CXXFLAGS := $(CXXFLAGS_RELEASE)
release: dirs $(TARGET)

dirs:
	@mkdir -p "$(BUILD_DIR)" "$(BIN_DIR)"

$(TARGET): $(OBJS)
	$(LINK) $(OBJS) -o $@

# Compile C++ sources
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | dirs
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile C sources
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | dirs
	$(CC) $(CFLAGS) -c $< -o $@

run: debug
	"./$(TARGET)"

clean:
	rm -rf "$(BUILD_DIR)" "$(BIN_DIR)"

