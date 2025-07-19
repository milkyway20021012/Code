#include <assert.h>
#include <iostream>
using namespace std;

// AVL樹節點結構定義
// 每個節點包含：左子節點指針、右子節點指針、父節點指針、鍵值對數據、平衡因子
template <class K, class V> struct AVLNode {
  // 構造函數：初始化節點的所有成員變量
  AVLNode(const pair<K, V> &kv)
      : _left(nullptr), _right(nullptr), _parent(nullptr), _kv(kv), _bf(0) {}
  AVLNode<K, V> *_left;   // 左子節點指針，指向左子樹的根節點
  AVLNode<K, V> *_right;  // 右子節點指針，指向右子樹的根節點
  AVLNode<K, V> *_parent; // 父節點指針，指向父節點（根節點的父節點為nullptr）
  pair<K, V> _kv;         // 鍵值對數據，存儲實際的鍵和值
  int _bf; // 平衡因子 = 右子樹高度 - 左子樹高度，用於判斷是否平衡
};

// AVL樹類模板定義
// K: 鍵的類型，V: 值的類型
template <class K, class V> class AVLTree {
  typedef AVLNode<K, V> Node; // 類型別名，簡化代碼書寫

public:
  // ========== 插入操作 ==========
  // 功能：在AVL樹中插入新的鍵值對，並自動維護平衡
  // 參數：kv - 要插入的鍵值對
  // 返回值：true表示插入成功，false表示鍵值已存在（不允許重複）
  bool insert(const pair<K, V> &kv) {
    // 情況1：空樹處理
    // 如果樹為空，直接創建根節點並返回成功
    if (_root == nullptr) {
      _root = new Node(kv);
      return true;
    }

    // 情況2：非空樹的插入邏輯
    Node *parent = nullptr; // 記錄插入位置的父節點，用於後續設置父子關係
    Node *cur = _root;      // 當前遍歷節點，從根節點開始搜索插入位置

    // 二叉搜索樹的標準插入邏輯：根據鍵值大小決定搜索方向
    while (cur) {
      if (cur->_kv.first < kv.first) {
        // 當前節點的鍵值小於要插入的鍵值，需要往右子樹搜索
        parent = cur;      // 更新父節點
        cur = cur->_right; // 移動到右子節點
      } else if (cur->_kv.first > kv.first) {
        // 當前節點的鍵值大於要插入的鍵值，需要往左子樹搜索
        parent = cur;     // 更新父節點
        cur = cur->_left; // 移動到左子節點
      } else {
        // 找到相同鍵值，AVL樹不允許重複鍵，返回插入失敗
        return false;
      }
    }

    // 找到合適的插入位置，創建新節點並建立父子關係
    cur = new Node(kv); // 創建新節點，平衡因子初始化為0
    if (parent->_kv.first < kv.first) {
      parent->_right = cur; // 新節點作為右子節點插入
    } else {
      parent->_left = cur; // 新節點作為左子節點插入
    }
    cur->_parent = parent; // 設置新節點的父節點指針

    // ========== AVL樹平衡調整階段 ==========
    // 從插入位置的父節點開始，向上更新平衡因子並進行必要的旋轉調整
    // 這是AVL樹區別於普通二叉搜索樹的關鍵部分

    while (parent) {
      // 更新平衡因子：根據新節點插入的位置調整父節點的平衡因子
      if (parent->_left == cur) {
        parent->_bf--; // 插入到左子樹，左子樹高度+1，平衡因子-1
      } else {
        parent->_bf++; // 插入到右子樹，右子樹高度+1，平衡因子+1
      }

      // 情況1：平衡因子為0，表示該節點已達到平衡狀態
      // 這種情況下，插入操作不會影響該節點的高度，因此不需要進一步調整
      if (parent->_bf == 0) {
        break; // 退出循環，插入操作完成
      }

      // 情況2：平衡因子為1或-1，表示該節點暫時平衡，但高度發生變化
      // 需要繼續向上更新祖先節點的平衡因子，因為高度的變化會影響上層節點
      else if (parent->_bf == 1 || parent->_bf == -1) {
        cur = parent;             // 當前節點向上移動到父節點
        parent = parent->_parent; // 父節點向上移動到祖父節點
      }

      // 情況3：平衡因子為2或-2，表示該節點不平衡，需要進行旋轉調整
      // 這是AVL樹維護平衡的核心操作
      else if (parent->_bf == 2 || parent->_bf == -2) {
        // 根據平衡因子和插入位置決定具體的旋轉類型
        if (parent->_bf == 2) {
          // 右子樹過高（平衡因子為2），需要左旋或右左旋
          if (cur->_bf == 1) {
            // 右右情況：cur的平衡因子為1，表示右子樹更高
            // 這種情況只需要一次左旋就能恢復平衡
            RotateL(parent);
          } else {
            // 右左情況：cur的平衡因子為-1，表示左子樹更高
            // 這種情況需要先右旋再左旋（右左旋）
            RotateRL(parent);
          }
        } else { // parent->_bf == -2
          // 左子樹過高（平衡因子為-2），需要右旋或左右旋
          if (cur->_bf == -1) {
            // 左左情況：cur的平衡因子為-1，表示左子樹更高
            // 這種情況只需要一次右旋就能恢復平衡
            RotateR(parent);
          } else {
            // 左右情況：cur的平衡因子為1，表示右子樹更高
            // 這種情況需要先左旋再右旋（左右旋）
            RotateLR(parent);
          }
        }
        break; // 旋轉完成後，整棵樹已恢復平衡，退出循環
      } else {
        // 理論上不應該出現其他情況，如果出現說明邏輯有問題
        // 平衡因子只能是-2, -1, 0, 1, 2這五種情況
        assert(false);
      }
    }
    return true; // 插入操作成功完成
  }

  // ========== 查找操作 ==========
  // 功能：在AVL樹中查找指定鍵值的節點
  // 參數：key - 要查找的鍵值
  // 返回值：找到則返回節點指針，找不到則返回nullptr
  Node *find(const K &key) {
    Node *cur = _root; // 從根節點開始搜索
    while (cur) {
      if (cur->_kv.first < key) {
        // 當前節點的鍵值小於目標鍵值，往右子樹搜索
        cur = cur->_right;
      } else if (cur->_kv.first > key) {
        // 當前節點的鍵值大於目標鍵值，往左子樹搜索
        cur = cur->_left;
      } else {
        // 找到目標鍵值，返回對應節點
        return cur;
      }
    }
    // 搜索完畢未找到目標鍵值，返回nullptr
    return nullptr;
  }

  // ========== AVL樹驗證操作 ==========
  // 功能：驗證當前樹是否為合法的AVL樹
  // 返回值：true表示是合法的AVL樹，false表示不是
  bool IsAVLTree() { return _IsAVLTree(_root); }

private:
  // ========== 右旋操作 ==========
  // 功能：對指定節點進行右旋，用於處理左左不平衡情況
  // 參數：parent - 需要進行右旋的節點
  void RotateR(Node *parent) {
    /*
    右旋的目標：
    1. 將parent的左子節點subL提升為新的根節點
    2. 將subL的右子節點subLR掛接到parent的左子節點位置
    3. 將parent掛接到subL的右子節點位置
    4. 更新所有相關的父節點指針，維護樹的完整性
    */
    Node *subL = parent->_left; // 獲取左子節點（將成為新的根節點）
    Node *subLR = subL->_right; // 獲取左子節點的右子節點（需要重新掛接）

    // 步驟1：將subLR掛接到parent的左子節點位置
    parent->_left = subLR;
    if (subLR) {
      subLR->_parent = parent; // 更新subLR的父節點指針
    }

    // 步驟2：將parent掛接到subL的右子節點位置
    subL->_right = parent;

    // 步驟3：更新祖父節點的指向關係
    Node *parentParent = parent->_parent; // 獲取祖父節點
    parent->_parent = subL;               // 更新parent的父節點指針
    if (parentParent == nullptr) {
      // 情況A：parent是根節點，subL成為新的根節點
      _root = subL;
      subL->_parent = nullptr; // 根節點沒有父節點
    } else {
      // 情況B：parent不是根節點，需要更新祖父節點的指向
      if (parent == parentParent->_left) {
        parentParent->_left = subL; // parent原本是左子節點，subL也成為左子節點
      } else {
        parentParent->_right = subL; // parent原本是右子節點，subL也成為右子節點
      }
      subL->_parent = parentParent; // 更新subL的父節點指針
    }

    // 步驟4：更新平衡因子
    // 右旋後，原來的parent和subL都變為平衡狀態（平衡因子為0）
    parent->_bf = 0;
    subL->_bf = 0;
  }

  // ========== 左旋操作 ==========
  // 功能：對指定節點進行左旋，用於處理右右不平衡情況
  // 參數：parent - 需要進行左旋的節點
  void RotateL(Node *parent) {
    /*
    左旋調整原理圖解：

    旋轉前：       旋轉後：
    parent           subR
       \            /    \
        subR  =>  parent  ...
       /    \        \
      ...   subRL    subRL

    左旋的目標：
    1. 將parent的右子節點subR提升為新的根節點
    2. 將subR的左子節點subRL掛接到parent的右子節點位置
    3. 將parent掛接到subR的左子節點位置
    4. 更新所有相關的父節點指針，維護樹的完整性
    */
    Node *subR = parent->_right; // 獲取右子節點（將成為新的根節點）
    Node *subRL = subR->_left;   // 獲取右子節點的左子節點（需要重新掛接）

    // 步驟1：將subRL掛接到parent的右子節點位置
    parent->_right = subRL;
    if (subRL) {
      subRL->_parent = parent; // 更新subRL的父節點指針
    }

    // 步驟2：將parent掛接到subR的左子節點位置
    subR->_left = parent;

    // 步驟3：更新祖父節點的指向關係
    Node *parentParent = parent->_parent; // 獲取祖父節點
    parent->_parent = subR;               // 更新parent的父節點指針
    if (parentParent == nullptr) {
      // 情況A：parent是根節點，subR成為新的根節點
      _root = subR;
      subR->_parent = nullptr; // 根節點沒有父節點
    } else {
      // 情況B：parent不是根節點，需要更新祖父節點的指向
      if (parent == parentParent->_right) {
        parentParent->_right =
            subR; // parent原本是右子節點，旋轉後subR成為新的右子節點
      } else {
        parentParent->_left =
            subR; // parent原本是左子節點，旋轉後subR成為新的左子節點
      }
      subR->_parent = parentParent; // 更新subR的父節點指針
    }

    // 步驟4：更新平衡因子
    // 左旋後，原來的parent和subR都變為平衡狀態（平衡因子為0）
    parent->_bf = 0;
    subR->_bf = 0;
  }

  // ========== 左右旋操作 ==========
  // 功能：對指定節點進行左右旋，用於處理左右不平衡情況
  // 參數：parent - 需要進行左右旋的節點
  void RotateLR(Node *parent) {
    /*
    左右旋調整原理圖解：

    旋轉前：       第一次左旋：     第二次右旋：
    parent         parent           subLR
       /              /            /    \
      subL           subLR    =>  subL   parent
       \            /    \         \       \
        subLR      subL   ...      ...     ...
       /    \        \
      ...   ...      ...

    左右旋的目標：
    1. 先對parent的左子節點subL進行左旋，將左右情況轉換為左左情況
    2. 再對parent進行右旋，恢復平衡
    3. 根據旋轉前subLR的平衡因子，正確調整最終的平衡因子
    */
    Node *subL = parent->_left; // 獲取左子節點
    Node *subLR = subL->_right; // 獲取左子節點的右子節點（關鍵節點）
    int bf = subLR->_bf;        // 記錄旋轉前subLR的平衡因子，用於後續調整

    // 步驟1：對subL進行左旋，將左右情況轉換為左左情況
    RotateL(subL);

    // 步驟2：對parent進行右旋，恢復平衡
    RotateR(parent);

    // 步驟3：根據旋轉前subLR的平衡因子調整最終的平衡因子
    // 注意：旋轉後，subLR成為新的根節點，subL和parent成為其子節點
    if (bf == 0) {
      // 情況A：subLR原本平衡（平衡因子為0）
      // 旋轉後所有相關節點都變為平衡狀態
      parent->_bf = 0;
      subL->_bf = 0;
    } else if (bf == 1) {
      // 情況B：subLR原本右子樹較高（平衡因子為1）
      // 旋轉後parent平衡，subL平衡
      parent->_bf = 0;
      subL->_bf = -1;
    } else if (bf == -1) {
      // 情況C：subLR原本左子樹較高（平衡因子為-1）
      // 旋轉後parent右子樹較高，subL平衡
      parent->_bf = 1;
      subL->_bf = 0;
    } else {
      // 理論上不應該出現其他情況，平衡因子只能是-1, 0, 1
      assert(false);
    }
  }

  // ========== 右左旋操作 ==========
  // 功能：對指定節點進行右左旋，用於處理右左不平衡情況
  // 參數：parent - 需要進行右左旋的節點
  void RotateRL(Node *parent) {
    /*
    右左旋調整原理圖解：

    旋轉前：       第一次右旋：     第二次左旋：
    parent         parent           subRL
       \              \            /    \
        subR           subRL  =>  parent  subR
       /    \            \         \       \
      subRL  ...         subR      ...     ...
       \                /    \
        ...            ...   ...

    右左旋的目標：
    1. 先對parent的右子節點subR進行右旋，將右左情況轉換為右右情況
    2. 再對parent進行左旋，恢復平衡
    3. 根據旋轉前subRL的平衡因子，正確調整最終的平衡因子
    */
    Node *subR = parent->_right; // 獲取右子節點
    Node *subRL = subR->_left;   // 獲取右子節點的左子節點（關鍵節點）
    int bf = subRL->_bf;         // 記錄旋轉前subRL的平衡因子，用於後續調整

    // 步驟1：對subR進行右旋，將右左情況轉換為右右情況
    RotateR(subR);

    // 步驟2：對parent進行左旋，恢復平衡
    RotateL(parent);

    // 步驟3：根據旋轉前subRL的平衡因子調整最終的平衡因子
    // 注意：旋轉後，subRL成為新的根節點，parent和subR成為其子節點
    if (bf == 0) {
      // 情況A：subRL原本平衡（平衡因子為0）
      // 旋轉後所有相關節點都變為平衡狀態
      parent->_bf = 0;
      subR->_bf = 0;
    } else if (bf == 1) {
      // 情況B：subRL原本右子樹較高（平衡因子為1）
      // 旋轉後parent左子樹較高，subR平衡
      parent->_bf = -1;
      subR->_bf = 0;
    } else if (bf == -1) {
      // 情況C：subRL原本左子樹較高（平衡因子為-1）
      // 旋轉後parent平衡，subR平衡
      parent->_bf = 0;
      subR->_bf = 1;
    } else {
      // 理論上不應該出現其他情況，平衡因子只能是-1, 0, 1
      assert(false);
    }
  }

  // ========== AVL樹驗證的私有方法 ==========
  // 功能：遞歸驗證以root為根的子樹是否為合法的AVL樹
  // 參數：root - 要驗證的子樹根節點
  // 返回值：true表示是合法的AVL樹，false表示不是
  bool _IsAVLTree(Node *root) {
    // 空樹是合法的AVL樹
    if (root == nullptr) {
      return true;
    }

    // 計算左右子樹的高度
    int leftHeight = _Height(root->_left);   // 左子樹高度
    int rightHeight = _Height(root->_right); // 右子樹高度

    // 驗證平衡因子的正確性
    // 平衡因子應該等於右子樹高度減去左子樹高度
    if (rightHeight - leftHeight != root->_bf) {
      // 平衡因子異常，輸出錯誤信息
      cout << "平衡因子異常:" << root->_kv.first << "平衡因子:" << root->_bf
           << "高度差:" << rightHeight - leftHeight << endl;
      return false;
    }

    // 驗證AVL樹的平衡性質
    // 1. 左右子樹高度差不能超過1（即平衡因子在[-1,1]範圍內）
    // 2. 遞歸驗證左右子樹是否也是合法的AVL樹
    return abs(rightHeight - leftHeight) < 2 && _IsAVLTree(root->_left) &&
           _IsAVLTree(root->_right);
  }

  // ========== 計算樹高度的私有方法 ==========
  // 功能：遞歸計算以root為根的子樹的高度
  // 參數：root - 要計算高度的子樹根節點
  // 返回值：子樹的高度（空樹高度為0，單個節點高度為1）
  int _Height(Node *root) {
    // 空樹高度為0
    if (root == nullptr) {
      return 0;
    }

    // 遞歸計算左右子樹的高度
    int leftHeight = _Height(root->_left);   // 左子樹高度
    int rightHeight = _Height(root->_right); // 右子樹高度

    // 返回較高的子樹高度加1（當前節點貢獻1個高度）
    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
  }

  Node *_root = nullptr; // 根節點指針，空樹時為nullptr
};