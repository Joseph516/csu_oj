/*
1001: 水仙花数 时间限制: 1 Sec  内存限制: 128 MB
- 题目描述
春天是鲜花灿烂的季节，水仙花就是其中最迷人的代表，数学上有个水仙花数，他是这样定义的：“水仙花数”是指一个三位数，
它的各位数字的立方和等于其本身，比如：153=1^3+5^3+3^3。现在要求输出所有在m和n范围内的水仙花数。
- 输入
输入数据有多组，每组占一行，包括两个整数m和n（100<=m<=n<=999）。
- 输出
对于每个测试实例，要求输出所有在给定范围内的水仙花数，就是说，输出的水仙花数必须大于等于m,并且小于等于n，
如果有多个，则要求从小到大排列在一行内输出，之间用一个空格隔开(注意每组输出的最后一个数之后不要加空格);
如果给定的范围内不存在水仙花数，则输出no;每个测试实例的输出占一行。
- 样例输入
100 120
300 380
- 样例输出
no
370 371
*/

#include <cmath>
#include <iostream>
#include <vector>

std::vector<int> GetNumNarciscus(const int m, const int n) {
  if (m > n) {
    return std::vector<int>{};
  }

  std::vector<int> res;
  int n1, n2, n3;
  for (int i = m; i <= n; i++) {
    n1 = i / 100;
    n2 = (i % 100) / 10;
    n3 = (i % 100) % 10;
    if (pow(n1, 3) + pow(n2, 3) + pow(n3, 3) == i) {
      res.push_back(i);
    }
  }
  return res;
}

int main() {
  int m, n;
  std::vector<int> res;

  while (std::cin >> m >> n) {
    res = GetNumNarciscus(m, n);
    int len = res.size();

    if (len == 0) {
      std::cout << "no" << std::endl;
    } else {
      for (int i = 0; i < len; i++) {
        std::cout << res[i];
        if (i != len - 1) {
          std::cout << " ";
        }
      }
      std::cout << std::endl;
    }
  }
  return 0;
}
