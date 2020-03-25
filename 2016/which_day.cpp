/*
1015: 第几天
时间限制: 1 Sec  内存限制: 128 MB
提交: 881  解决: 379
- 题目描述
多组输入。
给定一个日期， 输出这个日期是该年的第几天。
- 输入
数据格式为 YYYY/MM/DD组成， 具体参见输入示例。另外，所有输入数据是合法的。
- 输出
对于每组输入数据，输出一行，表示该日期是该年的第几天。
- 样例输入
1985/01/20
2006/03/12
- 样例输出
20
71
*/

#include <iostream>

const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int WhichDay(const int yy, const int mm, const int dd) {
  // 计算日子
  int res = 0;
  for (int i = 1; i < mm; i++) {
    res += days[i - 1];
  }
  res += dd;

  // 闰年
  if (yy % 4 == 0 && yy % 100 != 0 || yy % 400 == 0) {
    if (mm > 2) { // !易错：闰年中月份不大于2月，同样不需要加1.
      res++;
    }
  }
  return res;
}

int main() {
  int yy, mm, dd;
  while (scanf("%d/%d/%d", &yy, &mm, &dd) != EOF) {
    std::cout << WhichDay(yy, mm, dd) << std::endl;
  }
  return 0;
}