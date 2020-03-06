/*
- 1006: 平方和与立方和
时间限制: 1 Sec  内存限制: 128 MB
提交: 1262  解决: 288
[提交] [状态] [讨论版] [命题人:外部导入]
- 题目描述
给定一段 n 与 m之间连续的整数（包括 n 和
m），求出他们中所有偶数的平方和以及所有奇数的立方和。
- 输入
输入数据包含多组测试实例，每组测试实例包含一行，两个整数m和 n（0 <= n<= 10000，
0 <= m <= 10000）
- 输出
对于每组输入数据，输出一行，应包括两个整数 x 和
y，分别表示该段连续的整数中所有偶数的平方和以及所有奇数的立方和。
- 样例输入
1 3
2 5
- 样例输出
4 28
20 152
*/
#include <iostream>
#include <vector>

void SumSquareAndCube(int m, int n, std::vector<long long>& res) {
  if (m > n) {
    int temp = m;
    m = n;
    n = temp;
  }
  res[0] = res[1] = 0;
  for (long i = m; i <= n; i++) {
    if (i % 2 == 0) {
      res[0] += i * i;
    } else {
      res[1] += i * i * i; // 若i为int，则i的三次方将出现上溢出
    }
  }
}

int main() {
  int m, n;
  std::vector<long long> res(2);
  while (std::cin >> m >> n) {
    if (m > 10000 || m < 0 || n > 10000 || n < 0) {
      continue;
    }
    SumSquareAndCube(m, n, res);
    std::cout << res[0] << ' ' << res[1] << std::endl;
  }
  return 0;
}