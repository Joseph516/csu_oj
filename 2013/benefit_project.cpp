/*
1004: 惠民工程
- 题目描述
市政府“惠民工程”的目标是在全市n个居民点间之架设煤气管道（但不一定有直接的管道相连，只要能间接通过管道可达即可）。
很显然最多可架设
n(n-1)/2条管道,然而实际上要连通n个居民点只需架设n-1条管道就可以了。
现请你编写程序，计算出该惠民工程需要的最低成本。
- 输入
测试输入包含若干测试用例。每个测试用例的第1行给出居民点数目M ( < =100 )、
评估的管道条数 N； 随后的N行对应居民点间管道的成本，每行给出一对正整数，
分别是两个居民点的编号，以及此两居民点间管道的成本（也是正整数）。
为简单起见，居民点从1到M编号。
- 输出
对每个测试用例，在1行里输出全市管道畅通所需要的最低成本。若统计数据不足以保证畅通，则输出“?”。
- 样例输入
3 3
1 2 1 // 1和2居民间的管道成本是1
1 3 2
2 3 4
3 1
2 3 2
- 样例输出
3
?
*/

#include <algorithm>
#include <iostream>
#include <vector>

// 查看根节点
int Find(int u, int parent[]) {
  while (u != parent[u]) {
    u = parent[u];
  }
  return u;
}

// 合并根节点
void Merge(const int set_u, const int set_v, int parent[]) {
  parent[set_u] = set_v;
}

// 最小生成树算法kruskal
int GetMinimumCost(const int &vertexs, std::vector<std::vector<int>> &cost) {
  int mst_weight = 0;

  // 定义顶点的父节点，初试时指向自身
  int parent[vertexs];
  for (int i = 0; i < vertexs; i++) {
    parent[i] = i;
  }

  // 按成本升序排序评估管道
  std::sort(cost.begin(), cost.end(),
            [](std::vector<int> lhs, std::vector<int> rhs) {
              return lhs[2] < rhs[2];
            });

  int edge_cnt = 0;  // 统计边
  for (auto c : cost) {
    int u = c[0] - 1;  // 居民点从1开始
    int v = c[1] - 1;

    // 找到顶点的根节点，若根节点不同则属于不同的集合
    int set_u = Find(u, parent);
    int set_v = Find(v, parent);

    if (set_u != set_v) {
      mst_weight += c[2];
      Merge(set_u, set_v, parent);
      edge_cnt++;
    }
  }
  return edge_cnt == vertexs - 1 ? mst_weight : -1;
}

int main() {
  int m, n, in;
  while (std::cin >> m >> n) {
    std::vector<std::vector<int>> cost(n, std::vector<int>(3, 0));  // nx3矩阵
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 3; j++) {
        std::cin >> in;
        cost[i][j] = in;
      }
    }

    int min_cost = GetMinimumCost(m, cost);
    if (min_cost != -1) {
      std::cout << min_cost << std::endl;
    } else {
      std::cout << '?' << std::endl;
    }
  }
  return 0;
}