/*
1005: 成绩转换
- 题目描述
某地区中考实行等级选拔制，为此需要将相应科目的卷面计分成绩转换为相应的等级。假设
门课程卷面总分 120 分，根据考试情况，各等级划线情况如下：
108~120 为 A;
100~107 为 B;
80~99 为 C;
72~79 为 D;
0~71 为 E;

- 输入
输入数据有多组，每组占一行，由一个整数组成。
- 输出
对于每组输入数据，输出一行。
如果输入数据不在 0~120 范围内，请输出一行：“Score is error!”。

- 样例输入
56
67
100
123
- 样例输出
E
E
B
Score is error!
*/

#include <iostream>

std::string GradesTranslation(const int& grade) {
  if(grade >=0 &&grade <=71) {
    return "E";
  } else if(grade <=79) {
    return "D";
  } else if(grade <= 99) {
    return "C";
  } else if(grade <= 107) {
    return "B";
  } else if (grade <= 120) {
    return "A";
  } else {
    return "Score is error!";
  }
}

int main(void) {
  int grade;
  while(std::cin >> grade) {
    std::cout << GradesTranslation(grade) << std::endl;
  }
  return 0;
}