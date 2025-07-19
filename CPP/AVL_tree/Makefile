# AVL樹項目 Makefile

# 編譯器設置
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# 目錄設置
SRC_DIR = src
INCLUDE_DIR = include
TARGET_DIR = target
BUILD_DIR = $(SRC_DIR)/build

# 源文件和目標文件
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# 可執行文件名
TARGET = $(TARGET_DIR)/avl_tree_test

# 默認目標
all: $(TARGET)

# 創建必要的目錄
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET_DIR):
	mkdir -p $(TARGET_DIR)

# 編譯目標文件
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# 鏈接生成可執行文件
$(TARGET): $(OBJ_FILES) | $(TARGET_DIR)
	$(CXX) $(OBJ_FILES) -o $(TARGET)

# 清理編譯產物
clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(TARGET_DIR)

# 運行測試
run: $(TARGET)
	./$(TARGET)

# 重新編譯
rebuild: clean all

.PHONY: all clean run rebuild 