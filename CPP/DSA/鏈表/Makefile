# Makefile for 鏈表專案
# 支援編譯不同資料夾的 .h 和 .c 檔案，包含 debug 模式

# 編譯器設定
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# 目錄設定
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
DEBUG_DIR = build/debug
RELEASE_DIR = build/release

# 源檔案
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEBUG_OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(DEBUG_DIR)/%.o)
RELEASE_OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(RELEASE_DIR)/%.o)

# 目標檔案
TARGET = slist
DEBUG_TARGET = $(DEBUG_DIR)/$(TARGET)
RELEASE_TARGET = $(RELEASE_DIR)/$(TARGET)

# 預設目標
all: release

# Debug 模式編譯
debug: CFLAGS += -g -DDEBUG -O0
debug: $(DEBUG_TARGET)

$(DEBUG_TARGET): $(DEBUG_OBJ_FILES)
	@echo "連結 debug 版本..."
	@mkdir -p $(DEBUG_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $^ -o $@
	@echo "Debug 版本編譯完成: $@"

$(DEBUG_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "編譯 debug 版本: $<"
	@mkdir -p $(DEBUG_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Release 模式編譯
release: CFLAGS += -O2 -DNDEBUG
release: $(RELEASE_TARGET)

$(RELEASE_TARGET): $(RELEASE_OBJ_FILES)
	@echo "連結 release 版本..."
	@mkdir -p $(RELEASE_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $^ -o $@
	@echo "Release 版本編譯完成: $@"

$(RELEASE_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "編譯 release 版本: $<"
	@mkdir -p $(RELEASE_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# 快速編譯（使用預設設定）
quick: $(TARGET)

$(TARGET): $(OBJ_FILES)
	@echo "連結目標檔案..."
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $^ -o $@
	@echo "編譯完成: $@"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "編譯: $<"
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# 清理檔案
clean:
	@echo "清理編譯檔案..."
	rm -rf $(BUILD_DIR)
	@echo "清理完成"

# 清理並重新編譯
rebuild: clean all

# 執行 debug 版本
run-debug: debug
	@echo "執行 debug 版本..."
	./$(DEBUG_TARGET)

# 執行 release 版本
run-release: release
	@echo "執行 release 版本..."
	./$(RELEASE_TARGET)

# 執行預設版本
run: quick
	@echo "執行程式..."
	./$(TARGET)

# 顯示專案資訊
info:
	@echo "=== 鏈表專案 Makefile ==="
	@echo "源檔案: $(SRC_FILES)"
	@echo "目標檔案: $(TARGET)"
	@echo "Debug 目標: $(DEBUG_TARGET)"
	@echo "Release 目標: $(RELEASE_TARGET)"
	@echo ""
	@echo "可用指令:"
	@echo "  make          - 編譯 release 版本"
	@echo "  make debug    - 編譯 debug 版本"
	@echo "  make release  - 編譯 release 版本"
	@echo "  make quick    - 快速編譯"
	@echo "  make clean    - 清理編譯檔案"
	@echo "  make rebuild  - 清理並重新編譯"
	@echo "  make run      - 編譯並執行"
	@echo "  make run-debug    - 編譯並執行 debug 版本"
	@echo "  make run-release  - 編譯並執行 release 版本"
	@echo "  make info     - 顯示專案資訊"

# 防止與同名檔案衝突
.PHONY: all debug release quick clean rebuild run run-debug run-release info 