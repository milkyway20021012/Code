# 鏈表專案

這是一個 C 語言的鏈表實作專案，使用 Makefile 進行編譯管理。

## 專案結構

```
鏈表/
├── include/          # 標頭檔案
│   └── slist.h
├── src/             # 源檔案
│   ├── main.c
│   └── slist.c
├── build/           # 編譯輸出目錄（自動生成）
│   ├── debug/       # Debug 版本
│   └── release/     # Release 版本
├── Makefile         # 編譯腳本
└── README.md        # 說明文件
```

## 編譯指令

### 基本編譯
```bash
# 編譯 release 版本（預設）
make

# 編譯 debug 版本
make debug

# 快速編譯
make quick
```

### 執行指令
```bash
# 編譯並執行 release 版本
make run-release

# 編譯並執行 debug 版本
make run-debug

# 編譯並執行（快速版本）
make run
```

### 清理指令
```bash
# 清理編譯檔案
make clean

# 清理並重新編譯
make rebuild
```

### 其他指令
```bash
# 顯示專案資訊
make info
```

## Debug 模式特點

- 包含除錯符號 (`-g`)
- 定義 `DEBUG` 巨集
- 關閉最佳化 (`-O0`)
- 適合使用 gdb 進行除錯

## Release 模式特點

- 開啟最佳化 (`-O2`)
- 定義 `NDEBUG` 巨集
- 適合生產環境使用

## 編譯器設定

- 編譯器：gcc
- 標準：C99
- 警告：-Wall -Wextra
- 包含目錄：include/

## 使用範例

1. **開發階段**：
   ```bash
   make debug
   gdb build/debug/slist
   ```

2. **測試階段**：
   ```bash
   make run-debug
   ```

3. **發布階段**：
   ```bash
   make release
   ./build/release/slist
   ```

## 注意事項

- 確保 `include/` 目錄中的標頭檔案正確包含
- 確保 `src/` 目錄中的源檔案正確實作
- 編譯時會自動創建 `build/` 目錄結構
- 使用 `make clean` 可以清理所有編譯檔案 