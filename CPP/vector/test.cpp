#include <iostream>
#include <stack>
#include <string>
using namespace std;
string decodeString(string s) {
  stack<string> st;
  string ret;
  for (int i = 0; i < s.size(); ++i) {
    // Not ']' => push elements to stack.
    if (s[i] != ']') {
      st.push(string(1, s[i]));
    }
    // ']' => append n times element which is in [];
    else {
      int num = 0;
      string tmp = "";
      while (st.top() != "[") {
        tmp = st.top() + tmp;
        st.pop(); // pop elements in []
      }
      string apend = tmp;
      string dig = "";
      st.pop(); // pop '['
      while (
          !st.empty() &&
          isdigit(
              st.top()[0])) { // isdigit() 是 C++ 標準函式庫中的函數，用來判斷一個字元（char）是不是數字（0~9）
        dig = st.top() + dig;
        st.pop(); // pop digits
      }
      num = stoi(dig);
      while (num > 1) {
        tmp += apend;
        --num;
      }
      st.push(tmp);
    }
  }
  // append all string.
  while (!st.empty()) {
    ret = st.top() + ret;
    st.pop();
  }

  return ret;
}
int main() {
  string s = "3[a]2[bc]";
  cout << decodeString(s) << endl;
  return 0;
}
