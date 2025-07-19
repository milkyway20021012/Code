#include "../include/AVLtree.h"
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

// 測試函數：基本插入和驗證
void testBasicInsertion() {
  cout << "=== 基本插入測試 ===" << endl;

  AVLTree<int, int> tree;

  // 插入一些測試數據
  vector<pair<int, int>> testData = {{10, 100}, {20, 200}, {30, 300}, {40, 400},
                                     {50, 500}, {25, 250}, {35, 350}, {45, 450},
                                     {15, 150}, {5, 50}};

  for (size_t i = 0; i < testData.size(); ++i) {
    const auto &kv = testData[i];
    cout << "正在插入第 " << (i + 1) << " 個節點: (" << kv.first << ", "
         << kv.second << ")" << endl;
    bool success = tree.insert(kv);
    cout << "插入結果: " << (success ? "成功" : "失敗") << endl;

    // 每插入幾個節點就驗證一次
    if ((i + 1) % 3 == 0) {
      cout << "驗證 AVL 樹性質..." << endl;
      bool isValid = tree.IsAVLTree();
      cout << "AVL樹驗證結果: " << (isValid ? "通過" : "失敗") << endl;
    }
  }

  // 最終驗證
  cout << "最終驗證 AVL 樹性質..." << endl;
  bool isValid = tree.IsAVLTree();
  cout << "AVL樹驗證結果: " << (isValid ? "通過" : "失敗") << endl;
  cout << endl;
}

// 測試函數：查找功能
void testFindOperation() {
  cout << "=== 查找功能測試 ===" << endl;

  AVLTree<int, string> tree;

  // 插入一些測試數據
  tree.insert({10, "蘋果"});
  tree.insert({20, "香蕉"});
  tree.insert({30, "橙子"});
  tree.insert({40, "葡萄"});
  tree.insert({50, "草莓"});

  // 測試查找存在的鍵
  vector<int> searchKeys = {10, 20, 30, 40, 50};
  for (int key : searchKeys) {
    auto *node = tree.find(key);
    if (node) {
      cout << "找到鍵 " << key << ": " << node->_kv.second << endl;
    } else {
      cout << "未找到鍵 " << key << endl;
    }
  }

  // 測試查找不存在的鍵
  vector<int> notFoundKeys = {5, 15, 25, 35, 45, 55};
  for (int key : notFoundKeys) {
    auto *node = tree.find(key);
    if (node) {
      cout << "錯誤：找到了不應該存在的鍵 " << key << endl;
    } else {
      cout << "正確：未找到鍵 " << key << endl;
    }
  }

  // 驗證AVL樹性質
  bool isValid = tree.IsAVLTree();
  cout << "AVL樹驗證結果: " << (isValid ? "通過" : "失敗") << endl;
  cout << endl;
}

// 測試函數：重複插入
void testDuplicateInsertion() {
  cout << "=== 重複插入測試 ===" << endl;

  AVLTree<int, int> tree;

  // 第一次插入
  bool success1 = tree.insert({100, 1000});
  cout << "第一次插入 (100, 1000): " << (success1 ? "成功" : "失敗") << endl;

  // 嘗試重複插入相同的鍵
  bool success2 = tree.insert({100, 2000});
  cout << "重複插入 (100, 2000): " << (success2 ? "成功" : "失敗") << endl;

  // 驗證AVL樹性質
  bool isValid = tree.IsAVLTree();
  cout << "AVL樹驗證結果: " << (isValid ? "通過" : "失敗") << endl;
  cout << endl;
}

// 測試函數：簡單序列插入
void testSimpleSequence() {
  cout << "=== 簡單序列插入測試 ===" << endl;

  AVLTree<int, int> tree;

  // 按順序插入 1-10
  for (int i = 1; i <= 10; ++i) {
    cout << "插入 " << i << "..." << endl;
    bool success = tree.insert({i, i * 10});
    if (!success) {
      cout << "插入失敗！" << endl;
      return;
    }

    // 每插入3個節點驗證一次
    if (i % 3 == 0) {
      bool isValid = tree.IsAVLTree();
      cout << "驗證結果: " << (isValid ? "通過" : "失敗") << endl;
    }
  }

  cout << "簡單序列插入完成" << endl;
  bool isValid = tree.IsAVLTree();
  cout << "最終驗證結果: " << (isValid ? "通過" : "失敗") << endl;
  cout << endl;
}

int main() {
  cout << "AVL樹測試程序開始運行..." << endl << endl;

  try {
    // 執行各種測試
    testSimpleSequence();
    testBasicInsertion();
    testFindOperation();
    testDuplicateInsertion();

    cout << "所有測試完成！" << endl;

  } catch (const exception &e) {
    cout << "測試過程中發生異常: " << e.what() << endl;
    return 1;
  } catch (...) {
    cout << "測試過程中發生未知異常" << endl;
    return 1;
  }

  return 0;
}