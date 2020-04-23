/*
1208: 选球问题
提交: 1159  解决: 314
- 题目描述
PIPI现有a-z共26种球，权值从a到z依次为1,2,3...26,现从已有的n个球中选出固定k个从左到右排列，
要求右边的球权值至少比左边大2，在给定n和k的情况下，求最小权重和。
- 输入
输入包含多组数据。
每组数据第一行包含两个整数 n,k (1<=k<=n<=50)
第二行是一个长度为n的字符串。
- 输出
对于每组样例，输出最小权重和。若不存在输出-1.
- 样例输入
5 3
xyabd
- 样例输出
29*/
#include <algorithm>
#include <iostream>
#include <string>

// 贪心算法：排序后优先选择前排符合要求的字母
int GetLeastWeight(int n, int k, std::string &s) {
  // 按照字母升序排序
  std::sort(s.begin(), s.end(),
            [](const char &lhs, const char &rhs) { return lhs < rhs; });
  int cnt = 1, sum = s[0] - 'a' + 1;
  char pre = s[0];
  for(int i = 1; i < n; i++) {
    if(cnt != k && s[i] - pre >= 2) {
      cnt++;
      sum += s[i] - 'a' + 1;
      pre = s[i];
    }
  }
  return cnt == k ? sum : -1;
} 

int main() {
  int n, k;
  std::string s;
  while (std::cin >> n >> k) {
    std::cin >> s;
    std::cout << GetLeastWeight(n, k, s) << std::endl;
  }
  return 0;
}