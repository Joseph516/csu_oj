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
接下来m行小路(u,next),u≠v,代表商店u和v之间有小路连接。
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
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

// 思路：
// 1. 从k种商品中买s种，只要商品不同即可，不要求顺序，可以在自己家买商品。
// 2. 权值为去商店买各种商品的路权之和，只计算去程，不包括返程。
// 3. 每个商店可以派多人去买不同的商品，理解为i商店每次购买商品均从自己店出发。
// 4. 应采用图的广度优先搜索算法
// DONE:
// 由于n可能远大于k，在使用BFS会出现时间或者空间超出限度。因此可以考虑针对商品进行BFS。
void GetLeastCost(int n, int m, int k, int s,
                  const std::vector<std::vector<int>>& road,
                  const std::vector<int>& tag, std::vector<int>& cost) {
  int head;  // 队首

  // 所有商店购买每件商品的代价
  unsigned int cost_all[n][k + 1];
  memset(cost_all, -1, sizeof(cost_all));

  // 求所有商店购买第i件商品的代价
  for (int i = 1; i <= k; i++) {
    // 初始化
    std::queue<int> q;
    // 在自己商店购买，代价为0，并以此为起点开始计算代价。
    for (int sh = 0; sh < n; sh++) {
      if (tag[sh] == i) {
        cost_all[sh][i] = 0;
        q.push(sh);
      }
    }
    
    // BFS
    while (!q.empty()) {
      head = q.front();
      q.pop();
      // 存在通路的商店
      for (int l = 0; l < road[head].size(); l++) {
        int next = road[head][l];
        if (cost_all[next][i] == -1) {
          // 该商店还没被搜索到, 则购买i物品的代价为上一步的代价+1
          cost_all[next][i] = cost_all[head][i] + 1;
          q.push(next);
        }
      }
    }
}

for (int i = 0; i < n; i++) {
  // sort
  std::sort(cost_all[i] + 1, cost_all[i] + 1 + k);
  cost[i] = 0;
  for (int j = 1; j <= s; j++) {
    cost[i] += cost_all[i][j];
  }
}
}

int main() {
  int n, m, k, s;
  int u, next;
  while (std::cin >> n >> m >> k >> s) {
    // 商店商品编号，最小代价
    std::vector<int> tag(n), cost(n);
    std::vector<std::vector<int>> road(n);
    for (int i = 0; i < n; i++) {
      std::cin >> tag[i];
      road[i].clear();  // 每个数组的size清零
    }
    // FIXME: 时间超限
    // 无向图邻接矩阵，链表形式。
    for (int i = 0; i < m; i++) {
      std::cin >> u >> next;
      road[u - 1].push_back(next - 1);
      road[next - 1].push_back(u - 1);
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