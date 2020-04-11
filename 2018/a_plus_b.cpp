/*
1026: a+b问题
提交: 987  解决: 483
- 题目描述
读入两个小于100的正整数A和B，计算A+B，注意: A+B的每一位由对应的英文字母给出。
- 输入
测试输入包含若干测试用例,每个测试用例占一行,格式为"A + B
=",相邻两字符串有一个空格间隔.当A和B同时为zero时输入结束,相应的结果不要输出.
- 输出
对每个测试用例输出1行,即A+B的值.
- 样例输入
one + two =
three four + five six =
zero + zero =
- 样例输出
3
90
*/
#include <iostream>
#include <string>
#include <vector>

// 这里可以用map实现，即 std::map<std::string, int> m;
int StringToInt(const std::string& s) {
  if (s == "one") {
    return 1;
  } else if (s == "two") {
    return 2;
  } else if (s == "three") {
    return 3;
  } else if (s == "four") {
    return 4;
  } else if (s == "five") {
    return 5;
  } else if (s == "six") {
    return 6;
  } else if (s == "seven") {
    return 7;
  } else if (s == "eight") {
    return 8;
  } else if (s == "nine") {
    return 9;
  } else {
    return 0;
  }
}

void TranslationAnB(const std::vector<std::string>& exp, int& a, int& b) {
  int i = 0;
  a = 0, b = 0;
  while (i < exp.size() && exp[i] != "+") {
    a *= 10;
    a += StringToInt(exp[i]);
    i++;
  }
  i++; // 跳过+号
  while (i < exp.size()) {
    b *= 10;
    b += StringToInt(exp[i]);
    i++;
  }
}

int main() {
  std::string s;
  int a, b;
  while (true) {
    std::vector<std::string> exp;
    while (std::cin >> s && s != "=") {
      exp.push_back(s);
    }
    TranslationAnB(exp, a, b);
    if (a == 0 && b == 0) {
      exit(0);
    } else {
      std::cout << a + b << std::endl;
    }
  }
  return 0;
}