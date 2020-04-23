/*
1209: 模拟出入栈游戏
时间限制: 1 Sec  内存限制: 128 MB
提交: 737  解决: 295
- 题目描述
PIPI现有a-z
26个小球模拟出入栈操作，小球按照a~z的顺序压入栈，在栈顶的元素可以随时被取出，
在游戏开始前给出任意26个字母的一些排列，问是否能够由出栈顺序得到这个排列。
- 输入
输入包含多组测试用例。
每组测试用例包含26个字母组成的一个序列。
- 输出
若出栈顺序合法，输出"yes",否则输出"no".
- 样例输入
abcdefghijklmnopqrstuvwxyz
zabcdefghijklmnopqrstuvwxy
- 样例输出
yes
no
*/
#include <cstring>
#include <iostream>

void IsStackOptLegal(const std::string& s) {
  int out_stack[26]; // 记录字母是否出栈数组 
  int j;
  memset(out_stack, 0, sizeof(out_stack));

  out_stack[s[0] - 'a'] = 1;
  char pre = s[0]; // 上一个出栈字母
  for (int i = 1; i < s.size(); i++) {
    if(s[i] < pre) {
      // 从大到小顺序出栈
      j = pre - 'a' - 1;
    } else {
      // 可以直接出栈
      j = s[i] - 'a';
    }
    while (j >= 0 && out_stack[j] == 1) {
      j--;
    }
    if (s[i] - 'a' == j) {
      out_stack[j] = 1;
      pre = s[i];
    } else if(j > 0){
      std::cout << "no" << std::endl;
      return;
    }
  }
  std::cout << "yes" << std::endl;
}

int main() {
  std::string s;
  while (std::cin >> s) {
    IsStackOptLegal(s);
  }
}