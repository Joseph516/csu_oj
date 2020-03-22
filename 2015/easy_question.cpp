/*
1011: 容易的题
时间限制: 1 Sec  内存限制: 128 MB
提交: 637  解决: 276
- 题目描述
大家都很关心考试难易程度。K老师出题有一个规律，在出题之前，他会随机写下一个字符
串，只要这个字符串中能按顺序找到E,A,S,Y四个字母。他出题就会比较简单。你拿到了这个
字符串，请你告诉考试的题目难不难吧。
- 输入
输入数据有多组，每组占一行，由一个字符串组成（字符串的长度不超过1000）
- 输出
对于每组输入，输出一行，对应一个要求的答案（题目容易就输出easy，难就输出difficult)。
- 样例输入
eAsy
SEoAtSNY
- 样例输出
difficult
easy
*/

#include <iostream>
// #include <string>

void IsEasy(const std::string &in) {
  int cnt = 0;
  for (auto s : in) {
    // if(s > 'Z') {
    //   s -= 32; // 小写转大写
    // }

    if (s == 'E' && cnt == 0) {
      cnt++;
    } else if (s == 'A' && cnt == 1) {
      cnt++;
    } else if (s == 'S' && cnt == 2) {
      cnt++;
    } else if (s == 'Y' && cnt == 3) {
      std::cout << "easy" << std::endl;
      return;
    }
  }
  std::cout << "difficult" << std::endl;
}

int main() {
  std::string s;
  while (std::cin >> s) {
    IsEasy(s);
  }
  return 0;
}