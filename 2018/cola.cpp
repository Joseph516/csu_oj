/*
1028: 可乐
提交: 1188  解决: 329
- 题目描述
猪年快乐！在这个快乐的日子里我们当然要去超市买可乐喝啦!
现在超市有n种可乐，第 i 种可乐的价格为C[i] ，体积为 2^(i-1) 毫升，
每种可乐都是无限供应的，现在你想买至少 L毫升的可乐 ，
作为一个省钱小能手，聪明的你能够想到最少要花多少钱吗?
- 输入
输入包含多组测试用例。
每组测试用例第一行包含两个数字 n 和 L (1 ≤ n ≤ 30; 1 ≤ L ≤ 10^9)，
n是可乐的种类数， L是我们最终要买的可乐体积。
第二行包含 n 个数字 C1，C2,...Cn n (1 ≤ ci ≤ 10^9),代表每一种可乐的价格。
- 输出
输出一个数字，购买至少L毫升的可乐需要的最少花费。
- 样例输入
4 12
20 30 70 90
4 3
10000 1000 100 10
4 3
10 100 1000 10000
- 样例输出
150 // 30*2+90
10
30 // 10*3
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

typedef struct {
  long long c, v;
  double ppml;
} Cola;

// 贪心算法，类似但不同于背包问题
long long GetLeastCost(std::vector<Cola>& cola, long long l) {
  int n = cola.size();
  
  // 按单价由低至高排序
  std::sort(cola.begin(), cola.end(), [](const Cola& lhs, const Cola& rhs) {
    return lhs.ppml < rhs.ppml;
  });

  // 优化购买单价低的可乐
  long long cost = 0, min_cost = 0;
  for (int i = 0; i < n; i++) {
    cost += (l / cola[i].v) * cola[i].c;
    if (i == 0) {
      // 预先用最低单价多买一瓶
      min_cost = cost + cola[i].c;
    }

    l %= cola[i].v;  // 剩下所需可乐体积
    if (l == 0) {
      return std::min(min_cost, cost);
    } else {
      // 剩下可乐的体积不足一瓶，则多买一瓶
      // 同样上次也是多购买了一瓶可乐，两个取小值
      // 注意cost没有变，即cost对应的一直是整数瓶可乐的总价格
      min_cost = std::min(min_cost, cost + cola[i].c);
    }
  }

  return min_cost;
}

int main() {
  int n;
  long long l;
  while (std::cin >> n >> l) {
    std::vector<Cola> cola(n);
    for (int i = 0; i < n; i++) {
      std::cin >> cola[i].c;
      if (i == 0) {
        cola[i].v = 1;
      } else {
        cola[i].v = cola[i - 1].v * 2;
      }
      cola[i].ppml = (double)cola[i].c / cola[i].v;
    }

    std::cout << GetLeastCost(cola, l) << std::endl;
  }
}