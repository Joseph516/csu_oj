/*
1211: 小镇购物
时间限制: 2 Sec  内存限制: 128 MB
提交: 442  解决: 202
- 题目描述
CSU镇上有n个商店，n个商店有m条双向小路相连，在这n个商店里共有k种不同商品，
每个商店只有一种商品，每条路的权重都为1。现问你从每个商店出发，
买够k种商品中的s种商品所需的最小代价,每个商店可以同时派出多个人(出发)买不同商品，买够即可。
- 输入
输入包含多组测试用例。
对于每一组输入包含四个数字n ,m, k,s (1<=n<=m<=1e5 , 1<=s<=k<=min(n,100))
分别代表商店数，小路数，商品种数，需要的商品数。
接下来n个数 a1,a2...an (1<=ai<=k),ai代表第i个商店的商品编号。
接下来m行小路(u,v),u≠v,代表商店u和v之间有小路连接。
- 输出
输出n个数字，第i个数字代表从商店i出发买够s种商品所需的最小代价。
- 样例输入
5 5 4 3
1 2 4 3 2
1 2
2 3
3 4
4 1
4 5
7 6 3 2
1 2 3 3 2 2 1
1 2
2 3
3 4
2 5
5 6
6 7
- 样例输出
2 2 2 2 3
1 1 1 2 2 1 1
*/
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

// 思路：
// 1. 从k种商品中买s种，只要商品不同即可，不要求顺序，可以在自己家买商品。
// 2. 权值为去商店买各种商品的路权之和，只计算去程，不包括返程。
// 3. 每个商店可以派多人去买不同的商品，理解为i商店每次购买商品均从自己店出发。
// 4. 应采用图的广度优先搜索算法
void GetLeastCost(int n, int m, int k, int s, const std::vector<std::vector<int>>& road,
                  const std::vector<int>& tag, std::vector<int>& cost) {
  int cnt = 0;                    // 已经购买商品计数
  int bought[k + 1], visited[n];  // 已经购买商品， 已访问商店
  int head, rear, layer;          // 队首， 队尾， BFS层数
  for (int i = 0; i < n; i++) {
    // 初始化
    std::queue<int> q;
    memset(bought, 0, sizeof(bought));
    memset(visited, 0, sizeof(visited));
    q.push(i);
    bought[tag[i]] = 1;
    visited[i] = 1;
    cnt = 1;
    cost[i] = 0;
    rear = i;
    layer = 0;
    // BFS
    while (cnt != s && !q.empty()) {
      head = q.front();
      q.pop();
      visited[head] = 1;
      for (int j = 0; j != road[head].size(); j++) {
        int v = road[head][j];
        if (visited[v] == 0) {
          q.push(v);
        }
      }

      if (bought[tag[head]] != 1) {
        cnt++;
        bought[tag[head]] = 1;
        cost[i] += layer;
      }

      if (head == rear) {
        layer++;
        rear = q.back();
      }
    }
  }
}

int main() {
  int n, m, k, s;
  int u, v;
  while (std::cin >> n >> m >> k >> s) {
    // 商店商品编号，最小代价
    std::vector<int> tag(n), cost(n);
    std::vector<std::vector<int>> road(n);
    for (int i = 0; i < n; i++) {
      std::cin >> tag[i];
      road[i].clear(); // 每个数组的size清零
    }
    // FIXME: 时间超限%12，当n>>k时，BFS花费时间较长。
    // 无向图邻接矩阵，链表形式。
    for (int i = 0; i < m; i++) {
      std::cin >> u >> v;
      road[u - 1].push_back(v - 1);
      road[v - 1].push_back(u - 1);
    }

    GetLeastCost(n, m, k, s, road, tag, cost);

    // output
    for (int i = 0; i < n; i++) {
      std::cout << cost[i];
      if (i != n - 1) {
        std::cout << " ";
      }
    }
    std::cout << std::endl;
  }
}