/*
1009: 安全路径
时间限制: 1 Sec  内存限制: 128 MB
提交: 1146  解决: 227

- 题目描述
卫斯理小说经常提及外星人，比如蓝血人。
在土星星球有很多城市，每个城市之间有一条或多条飞行通道，
但是并不是所有的路都是很安全的，每一条路有一个安全系数 s,s 是在 0和1 间的实数
(包括0和1)。一条从 u 到 v 的通道 P 的安全度为 Safe(P) =
s(e1)*s(e2)…*s(ek)e1,e2,ek是P 上的边。
现在蓝血人想出去旅游，面对这这么多的路，他想找一条最安全的路。但是蓝血人的数学不好，想请你帮忙。
- 输入
输入包括多个测试实例，每个实例包括：
第一行： 一个整数 n。 n 表示城市的个数 n<=1000;
接着是一个 n*n 的矩阵表示两个城市之间的安全系数，
(0可以理解为那两个城市之间没有直接的通道 )。 接着是一个整数m
(m<=100)表示若干个蓝血人要旅游的路线
,下面每行有两个数字，表示蓝血人所在的城市和要去的城市。
- 输出
如果蓝血人无法达到他的目的地，输出 "What a pity!" ，
其他的输出这两个城市之间的最安全道路的安全系数，保留三位小数。
- 样例输入
3
1 0.5 0.5
0.5 1 0.4
0.5 0.4 1
3
1 2
2 3
1 3
- 样例输出
0.500
0.400
0.500
*/

// 注意：算法需要使用double，float会因为精度问题而出现答案不正确.

#include <iostream>
#include <vector>

// 返回src与dest两地的安全系数
double SafeDijkstra(const std::vector<std::vector<double>>& matrix_e,
                   const int src, const int dest) {
  if (src == dest) {
    return 1.0;  // 起点与终点相同
  }

  int n = matrix_e.size();  // 顶点总数
  // 初始化
  int final[n];
  double d[n];
  for (int v = 0; v < n; v++) {
    final[v] = 0;
    d[v] = matrix_e[src][v];
  }

  // 从src开始算法
  d[src] = 1;
  final[src] = 1;
  double max;
  for (int i = 1; i < n; ++i) {
    // 安全系数最小的城市
    int safest_city = -1;
    max = 0;
    for (int w = 0; w < n; w++) {
      if (final[w] == 0 && d[w] > max) {
        safest_city = w;
        max = d[w];
      }
    }
    if (safest_city == -1) {
      return 0.0;  // 与剩下的点不通
    }
    if (safest_city == dest) {
      return d[dest];  // 终点，后续结点可以不用搜索
    }

    // 加入S集
    final[safest_city] = 1;
    // 更新距离
    for (int w = 0; w < n; w++) {
      // max为src至safest_city的安全系数
      double src_to_w = max * matrix_e[w][safest_city];
      if (final[w] == 0 && matrix_e[w][safest_city] != 0 && src_to_w > d[w]) {
        d[w] = src_to_w;
      }
    }
  }
  return d[dest];
}

int main() {
  int n, m;

  while (std::cin >> n) {
    // 保存安全系数
    std::vector<std::vector<double>> matrix_e(n, std::vector<double>(n, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        std::cin >> matrix_e[i][j];
      }
    }

    // 保存目标路径
    std::cin >> m;
    int src, dest;
    for (int i = 0; i < m; i++) {
      std::cin >> src >> dest;

      // 计算安全系数
      double res = SafeDijkstra(matrix_e, src - 1, dest - 1);

      if (res == 0) {
        // std::cout << "What a pity!\n";
        printf("What a pity!\n");
      } else {
        // std::cout << std::fixed << std::setprecision(3) << res << std::endl;
        printf("%.3lf\n", res);
      }
    }
  }
  return 0;
}