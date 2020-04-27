/*
1111: 最小花费
- 时间限制: 1 Sec  内存限制: 128 MB
提交: 489  解决: 110
- 题目描述
在n个人中，某些人的银行账号之间可以互相转账。这些人之间转账的手续费各不相同。
给定这些人之间转账时需要从转账金额里扣除百分之几的手续费，
请问A最少需要多少钱使得转账后B收到100元。
- 输入
输入包含多组测试用例。
对于每组样例，第一行输入两个正整数n,m,分别表示总人数和可以互相转账的人的对数。
（0<n<=2000）以下m行每行输入三个正整数x,y,z。
表示标号为x的人和标号为y的人之间互相转账需要扣除z%的手续费（z<100）。
最后一行输入两个正整数A,B。数据保证A与B之间可以直接或间接地转账
- 输出
输出A使得B到账100元最少需要的总费用。精确到小数点后8位。
- 样例输入
3 3
1 2 1
2 3 2
1 3 3
1 3
- 样例输出
103.07153164
*/

#include <bits/stdc++.h>

const double Kmax = std::numeric_limits<double>::max();

// 思路：本质上求a和b间的最短距离，由于b是确定的，计算从b开始到a。
// 注意：由于精度的原因，z需要转成都变了后进行运算。
double GetLeastCost(const std::vector<std::vector<int>>& trans, const int a,
                    const int b) {
  if (a == b) {
    return 0;
  }
  int n = trans.size();
  // 初始化
  int final[n];
  double d[n];
  for (int v = 0; v < n; v++) {
    final[v] = 0;
    d[v] = 100.f / (1 - (double)trans[b][v] / 100);
  }

  d[b] = 0;
  final[b] = 1;
  double min;
  for (int i = 1; i < n; i++) {
    int lowest = -1; // 手续费最少的人
    min = Kmax;
    for (int v = 0; v < n; v++) {
      if (final[v] == 0 && d[v] < min) {
        lowest = v;
        min = d[v];
      }
    }
    if (lowest == -1) {
      return 0;  // 不能转账
    }
    if (lowest == a) {
      return d[lowest];
    }
    // 加入s集
    final[lowest] = 1;
    // 更新手续费
    for (int w = 0; w < n; w++) {
      double b_to_w = min / (1 - (double)trans[lowest][w] / 100);
      if (final[w] == 0 && b_to_w < d[w]) {
        d[w] = b_to_w;
      }
    }
  }
  return d[a];
}

int main() {
  int n, m;
  int x, y, z;
  int a, b;
  while (std::cin >> n >> m) {
    std::vector<std::vector<int>> trans(n, std::vector<int>(n, 100));
    // 构建图的邻接表
    for (int i = 0; i < m; i++) {
      std::cin >> x >> y >> z;
      trans[x - 1][y - 1] = z;
      trans[y - 1][x - 1] = z;
      trans[x - 1][x - 1] = 0;
      trans[y - 1][y - 1] = 0;
    }
    std::cin >> a >> b;

    printf("%.8f\n", GetLeastCost(trans, a - 1, b - 1));
  }

  return 0;
}
