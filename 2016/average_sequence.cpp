/*
1017: 序列求平均
时间限制: 1 Sec  内存限制: 128 MB
提交: 515  解决: 240
- 题目描述
有一个长度为 n(n<=100)的数列， 该数列定义为从2开始的递增有序偶数，
现在要求你按照顺序每 m个数求出一个平均值， 如果最后不足 m个，
则以实际数量求平均值。编程输出该平均值序列。
- 输入
输入数据有多组， 每组占一行， 包含两个整数 n和 m （1<=m,n<=100）， n和
m的含义如上所述。
- 输出
对于每组输入数据， 输出一个平均值序列， 每组输出占一行。
- 样例输入
3 2
4 2
- 样例输出
3 6
3 7
*/

#include <iostream>

void PrintAverage(int n, int m) {
  int adder = 2, sum;

  while (n >= m) {
    sum = 0;
    for (int i = 0; i < m; i++) {
      sum += adder;
      adder += 2;
      n--;
    }
    std::cout << sum / m;
    if (n != 0) {
      std::cout << " ";
    }
  }

  // 处理剩余数的平均值
  int n_cnt = n;
  sum = 0;
  while (n > 0) {
    sum += adder;
    adder += 2;
    n--;
    if (n == 0) {
      std::cout << sum / n_cnt;
    }
  }

  std::cout << std::endl;
}

int main() {
  int n, m;
  while (std::cin >> n >> m) {
    PrintAverage(n, m);
  }

  return 0;
}