# Makefile for DSA project

# 編譯器
CC = gcc

# 編譯選項
CFLAGS = -Wall -Wextra -std=c99 -I include

# 調試選項
DEBUG_CFLAGS = $(CFLAGS) -g -O0

# 目標文件
TARGET = main
DEBUG_TARGET = main_debug

# 源文件
SOURCES = src/main.c src/seqlist.c

# 默認目標
all: $(TARGET)

# 編譯規則
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

# 調試版本編譯規則
debug: $(SOURCES)
	$(CC) $(DEBUG_CFLAGS) -o $(DEBUG_TARGET) $(SOURCES)

# 清理規則
clean:
	rm -f $(TARGET) $(DEBUG_TARGET)

# 運行規則
run: $(TARGET)
	./$(TARGET)

# 調試運行規則
run_debug: debug
	./$(DEBUG_TARGET)

# 使用 gdb 調試
gdb_debug: debug
	gdb $(DEBUG_TARGET)

.PHONY: all clean run debug run_debug gdb_debug 