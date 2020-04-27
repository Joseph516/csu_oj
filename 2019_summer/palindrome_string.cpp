/*
1112: 回文串
时间限制: 1 Sec  内存限制: 128 MB
提交: 470  解决: 168
- 题目描述
现在给你一个字符串S，请你计算S中有多少连续子串是回文串。
- 输入
输入包含多组测试数据。每组输入是一个非空字符串，长度不超过5000.
- 输出
对于每组输入，输出回文子串的个数。
- 样例输入
aba
- 样例输出
4
*/

#include <bits/stdc++.h>

int IsPalindromeString(std::string const& s, int head, int tail) {
  while (tail > head && s[tail] == s[head]) {
    tail--;
    head++;
  }
  return tail > head ? 0 : 1;
}

// 方法一：暴力判断长度依次为1~n的子串是不是回文子串
int GetNumPalindromeStringForce(const std::string& s) {
  int n = s.size();
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n - i; j++) {
      cnt += IsPalindromeString(s, j, j + i - 1);
    }
  }
  return cnt;
}

// 方法二：由中心向外扩散方法回文子串
int GetNumPalindromeStringCenter(const std::string& s) {
  int n = s.size();
  int cnt = 0, l, r;
  for (int i = 0; i < n; i++) {
    // 由中心向两边扩散
    // 若中心子串不是回文，则无需扩散。如abaa，由于ba不是回文串，则abaa肯定不是回文串。
    for (l = i - 1, r = i + 1; l >= 0 && r < n && s[l] == s[r]; --l, ++r) {
      cnt++;
    }
    // 错开一个字符再继续由中心向两边扩散搜索
    // 可以令l=i，r=i+1开始搜索，结果一样。
    for (l = i - 1, r = i; l >= 0 && r < n && s[l] == s[r]; --l, ++r) {
      cnt++;
    }

    cnt++;  // // 单个字符也是回文串
  }

  return cnt;
}

int main() {
  std::string s;
  while (std::cin >> s) {
    std::cout << GetNumPalindromeStringCenter(s) << std::endl;
  }
}