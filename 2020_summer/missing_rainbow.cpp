/*
1252: 缺失的彩虹
时间限制: 1 Sec  内存限制: 128 MB
提交: 302  解决: 125
- 题目描述
众所周知，彩虹有7种颜色，我们给定七个字母和颜色的映射，如下所示：
'A' -> "red"
'B' -> "orange"
'C' -> "yellow"
'D' -> "green"
'E' -> "cyan"
'F' -> "blue"
'G' -> "purple"
但是在某一天，彩虹的颜色少了几种，你能告诉PIPI哪些彩虹的颜色没有出现过吗?
- 输入
输入包含多组测试用例。
对于每组测试用例，输入n个合法的颜色字符串(0<=n<=100)，输出有多少种颜色没有出现过，并分别输出对应的字母。
- 输出
对于每一组测试样例，输出一个数字，代表缺失的颜色种数，然后按照升序输出缺失颜色对应的字母。
- 样例输入
3
red
orange
cyan
样例输出
4
C
D
F
G
*/

#include <bits/stdc++.h>

int rainbow[7];
const char alph[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
std::map<std::string, int> color = {
    {"red", 0},  {"orange", 1}, {"yellow", 2}, {"green", 3},
    {"cyan", 4}, {"blue", 5},   {"purple", 6}};

int main() {
  int n, cnt;
  std::string s;
  while(std::cin >> n) {
    memset(rainbow, 0, sizeof(rainbow));
    cnt = 0;
    for(int i = 0; i < n; i++) {
      std::cin >> s;
      int indx = color[s];
      if(rainbow[indx] == 0) {
        cnt++;
      }
      rainbow[indx] = 1;
    }
    std::cout << 7 - cnt << std::endl;
    for(int i = 0; i < 7; i++) {
      if(rainbow[i] == 0) {
        std::cout << alph[i] << std::endl;
      }
    }
    
  }
  return 0;
}