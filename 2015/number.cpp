/*
1012: 数字
时间限制: 1 Sec  内存限制: 128 MB
提交: 533  解决: 294
- 题目描述
PIPI在做一个调查，0到9的10个数字中大家最喜欢哪一个？
他询问了N个人，用这些人的方法告诉他的数字组成了一个N位的整数。
然后PIPI就去给女朋友打电话了，他叫你帮忙统计一下，这个整数中哪一个数字出现最多。
- 输入
输入数据有多组，每组占一行，由一个N为的整数构成（PIPI急着打电话，没有告诉你N是多少，只告诉这个数字小于10的1000次方）。
- 输出
对于每组输入数据，输出一行，对应一个要求的答案（答案为0~9之间的一个数字，如果有多个数字出现次数一样多的情况，输出最小的数字）
- 样例输入
1234567891
11122333
1235564
- 样例输出
1
1
5
*/

#include <iostream>
// #include <string>
#include <vector>

int MostFreqNum(const std::string &in) {
  std::vector<int> cnt(10, 0);
  for(auto s:in) {
    cnt[s - '0']++; // 字符转数字，注意stoi函数是字符串转数字
  }

  int most_num = 0;
  int most_cnt = 0;
  for(int i = 0; i < 10; i++) {
    if(cnt[i] > most_cnt) {
      most_num = i;
      most_cnt = cnt[i];
    }
  }
  return most_num;
}

int main() {
  std::string s;
  while(std::cin >> s) {
    std::cout << MostFreqNum(s) << std::endl;
  }
  return 0;
}