/*
1212: graph's connected components
时间限制: 2 Sec  内存限制: 128 MB
提交: 185  解决: 48
- 题目描述
Given an integers set of m integers,each integer is in the range [0, 2^n-1].
A graph is build on the following constraints: if integers X and Y satisfy X&Y=0
(& is bitwise AND operation),X and Y are connected by an undirected edge.Please
help PIPI count the number of connected components in the graph!
- 输入
Input contains multiple test cases.
Each test case starts with a number n(0 <= n <= 22) and m(1<=m<=2^n) .
The next line contains m different integers: a1,a2...am,each integer 0<=ai <2^n.
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

// FIXME:n的值更大，一般DFS时间超出限制

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

/*
// TODO: 没看懂！
// 参考链接： https://blog.csdn.net/lightindarkness/article/details/104928999
// x ^ y ^ y = x

#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 22;
int A[N], n, m, tp;
// vertex数组用来表示某个顶点是否存在，vis数组用来表示是否访问。
bool vertex[N], vis[N];

// 描述：找到所有与A[i]相与为0的结点并标记
// 输入：now = A[i] ^ tp
// (tp=01...1, 即now=A[i]除符号位外，其余位取反，相当于now=tp-A[i])
void dfs(int now) {
  if (vis[now]) return;
  vis[now] = 1;
  if (vertex[now]) dfs(now ^ tp);
  // x & -x : 获取x的最低非零位，如6&-6=2(6二进制为110，最低非0位是2)
  int x = now, t = now - (x & -x);
  while (1) {
    if (!vis[t]) dfs(t);
    if (!x) break;
    x -= (x & -x);
    t = now - (x & -x);
  }
}

int main() {
  while (cin >> n >> m) {
    memset(vertex, 0, sizeof(vertex));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < m; i++) {
      cin >> A[i];
      vertex[A[i]] = 1;
    }
    // 只有一个结点
    if (!n) {
      cout << "1" << endl;
      continue;
    }
    tp = (1 << n) - 1; // tp = (2^n)-1, 二进制表示位符号位为0，其余位全为1
    int ans = 0; // 连通分量
    for (int i = 0; i < m; i++) {
      if (!vis[A[i]]) {
        vis[A[i]] = 1;
        dfs(A[i] ^ tp);
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
*/