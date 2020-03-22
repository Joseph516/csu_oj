/*
1010: 好坑的电子地图
提交: 667  解决: 280
- 题目描述
小明是今年参加复试的外校考生，他要去民主楼小礼堂签到。由于对中南大学校本部很不熟悉，小明找到了这边读书的好朋友鲁大师，
不巧，鲁大师在忙着自由探索项目的结题工作，不能给他带路，只好给他发了一份半成品的电子地图。
地图上只列出了校本部内的N个点，M条路，小明处于S点，民主楼小礼堂是T点。小明感谢鲁大师，当然只是在拿到地图的一瞬间，
后面的情况让他知道这半成品到底有多坑。鲁大师制作的电子地图是带有语音提示功能的，
但是在编号为奇数的点他要等1分钟才能告诉他具体怎么走，而在编号为偶数的点要等2分钟。
现在告诉你地图的具体情况，小明想知道他能不能在A分钟内赶到民主楼小礼堂。
- 输入
输入数据有多组，每组占M+1行，第一行有5个数字N，M，S，T，A，接下来M行，每行三个数字u,v,t，
代表每条路的两个顶点和步行时间。（输入数据保证不含重边0<N<M<1000）
- 输出
对于每组输入数据，输出一行，小明能在A分钟内赶到民主楼小礼堂输出YES和最少花费的时间，否则输出KENG
- 样例输入
4 3 1 4 10
1 2 1
3 2 2
3 4 3
5 4 2 4 7
1 2 5
5 4 2
3 5 1
2 3 1
- 样例输出
YES 10
KENG
*/

#include <iostream>
#include <limits>
#include <vector>

const int Kmax = std::numeric_limits<int>::max();

// 返回src与dest两地的最短距离（加入询问时间）
int Dijkstra(const std::vector<std::vector<int>>& matrix_e, const int src,
             const int dest) {
  int ask_time = src % 2 == 0 ? 1 : 2;  // 邻接矩阵是从0开始不是1
  if (src == dest) {
    return ask_time;  // 起点与终点相同
  }

  // 初始化
  int n = matrix_e.size();
  int final[n];
  int d[n];
  for (int v = 0; v < n; v++) {
    final[v] = 0;
    d[v] = matrix_e[src][v] == Kmax ? matrix_e[src][v]
                                    : matrix_e[src][v] + ask_time;
  }

  // 从src开始算法
  d[src] = 0;
  final[src] = 1;
  int min;
  for (int i = 1; i < n; ++i) {
    // 最快的下一点
    int min_point = -1;
    min = Kmax;
    for (int w = 0; w < n; w++) {
      if (final[w] == 0 && d[w] < min) {
        min_point = w;
        min = d[w];
      }
    }
    if (min_point == -1) {
      return -1;  // 与剩下的点不通
    }
    if (min_point == dest) {
      return d[dest];  // 终点，后续结点可以不用搜索
    }

    // 加入S集
    final[min_point] = 1;
    // 更新距离
    ask_time = min_point % 2 == 0 ? 1 : 2;
    for (int w = 0; w < n; w++) {
      // min为src至min_point的时间
      // int src_to_w = min + matrix_e[min_point][w]; // 可能出现溢出
      if (final[w] == 0 && matrix_e[min_point][w] != Kmax &&
          min + matrix_e[min_point][w] + ask_time < d[w]) {
        d[w] = min + matrix_e[min_point][w] + ask_time;
      }
    }
  }
  return d[dest];
}

void IsArrival(const int n, const int s, const int t, const int a,
               const std::vector<std::vector<int>>& matrix_e) {
  int res = Dijkstra(matrix_e, s - 1, t - 1);

  if (res <= a) {
    std::cout << "YES " << res << std::endl;
  } else {
    std::cout << "KENG" << std::endl;
  }
}

int main() {
  int n, m, s, t, a;
  int u, v, w;

  while (std::cin >> n >> m >> s >> t >> a) {
    // 定义邻接矩阵
    std::vector<std::vector<int>> matrix_e(n, std::vector<int>(n, Kmax));
    for (int i = 0; i < m; i++) {
      std::cin >> u >> v >> w;  // 边的顶点与权值
      // 将path转化成邻阶矩阵
      matrix_e[u - 1][v - 1] = w;
      matrix_e[v - 1][u - 1] = w;
    }
    for (int i = 0; i < n; i++) {
      matrix_e[i][i] = 0;  // 自己到自己的距离
    }
    IsArrival(n, s, t, a, matrix_e);
  }

  return 0;
}
