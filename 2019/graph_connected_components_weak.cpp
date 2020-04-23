/*
1245: graph's connected components(弱化版)
时间限制: 1 Sec  内存限制: 128 MB
提交: 67  解决: 31
- 题目描述
Given an integers set of m integers, each integer is in the range [0, 2^n-1].
A graph is build on the following constraints: if integers X and Y satisfy X&Y=0
(& is bitwise AND operation),X and Y are connected by an undirected edge.
Please help PIPI count the number of connected components in the graph!
- 输入
Input contains multiple test cases.
Each test case starts with a number n(0 <= n <= 12) and m(1<=m<=2^n) .
The next line contains m different integers: a1,a2...am ,each integer 0<=ai
<2^n.
- 输出
For each case,print connected components for each group of input data.
- 样例输入
2 3
1 2 3
5 5
5 19 10 20 12
5 6
5 19 10 20 12 0
- 样例输出
2
2
1
*/

// 使用一般DFS求解连通分量

#include <iostream>
#include <map>
#include <vector>

std::map<int, bool> visited;
std::map<int, int> indx;  // 结点v对应邻接表中的序号

void DFS(const std::vector<std::vector<int>>& adj_list, int v) {
  visited[v] = true;
  int k = indx[v];
  for (int i = 0; i < adj_list[k].size(); i++) {
    int u = adj_list[k][i];
    if (!visited[u]) {
      DFS(adj_list, u);
    }
  }
}

// 当结点x和y与为0，表示x和y结点之间通过无向边连接。
// 题中要求计算图的连通分量。
int GetConnectedComp(const std::vector<std::vector<int>>& adj_list) {
  int m = adj_list.size();
  int cnt = 0;

  for (int i = 0; i < m; i++) {
    int v = adj_list[i][0];
    if (!visited[v]) {
      DFS(adj_list, v);
      cnt++;
    }
  }

  return cnt;
}

int main() {
  int n, m, ai;
  while (std::cin >> n >> m) {
    std::vector<std::vector<int>> adj_list;  // 邻接表
    visited.clear();
    indx.clear();
    for (int i = 0; i < m; i++) {
      std::cin >> ai;
      adj_list.push_back(std::vector<int>{ai});
      visited[ai] = false;
      indx[ai] = i;
    }
    // 创建结点之间的无向边
    for (int i = 0; i < m - 1; i++) {
      for (int j = i + 1; j < m; j++) {
        if (!(adj_list[i][0] & adj_list[j][0])) {
          // 无向图的对称性
          adj_list[i].push_back(adj_list[j][0]);
          adj_list[j].push_back(adj_list[i][0]);
        }
      }
    }
    std::cout << GetConnectedComp(adj_list) << std::endl;
  }
}