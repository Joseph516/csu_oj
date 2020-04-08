/*
1020: 切木棍
时间限制: 1 Sec  内存限制: 128 MB
提交: 1079  解决: 354
- 题目描述
你有一根长度为n的木棍(n是整数)，现在需要你用这个木棍做一个矩形（但是不能是正方形），矩形的每条边的长度为整数。
你可以将这个木棍切成四份，作为矩形的四条边，请问你组成多少种不同的矩形？
- 输入
对于每组数据，输入一个整数，即为木棍的长度n（1<=n<=105）
- 输出
对于每组数据，输出一个整数，表示能组成的矩形种数。
- 样例输入
6
20
- 样例输出
1
4
- 提示
数据量巨大，请使用scanf代替cin
*/

#include <stdio.h>
// #include <iostream>

int GetSquareNum(const int n) {
  if(n & 1) {
    // n是奇数
    return 0;
  }

  int half_n = n >> 1;
  if (half_n & 1) {
    return half_n >> 1;
  } else {
    return (half_n >> 1) - 1; // 注意运算顺序
  }
}

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    // std::cout << GetSquareNum(n) << std::endl;
    printf("%d\n", GetSquareNum(n));
  }
  return 0;
}