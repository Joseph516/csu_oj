/*
1027: 逃离迷宫
提交: 2162  解决: 396
- 题目描述
PIPI被困在一个迷宫中了!
给定一个m × n (m行,n列)的迷宫，迷宫中有两个位置，
PIPI想从迷宫的一个位置走到另外一个位置，当然迷宫中有些地方是空地，
PIPI可以穿越，有些地方是障碍，她必须绕行，从迷宫的一个位置，
只能走到与它相邻的4个位置中,当然在行走过程中，PIPI不能走到迷宫外面去。
令人头痛的是，PIPI是个没什么方向感的人，因此，她在行走过程中，
不能转太多弯了，否则她会晕倒的。
起点和终点也有可能为障碍，初始时，PIPI所面向的方向未定，她可以选择4个方向的任何一个出发，
而不算成一次转弯。PIPI能从一个位置走到另外一个位置吗？
- 输入
第1行为一个整数t (1 ≤ t ≤100),表示测试数据的个数，接下来为t组测试数据，
每组测试数据中，第1行为两个整数m, n (1 ≤ m, n ≤100),分别表示迷宫的行数和列数，
接下来m行，每行包括n个字符，其中字符'.'表示该位置为空地，字符'*'表示该位置为障碍，
输入数据中只有这两种字符，每组测试数据的最后一行为5个整数
k, x1, y1, x2, y2 (1 ≤ k ≤ 10, 1 ≤ x1, x2 ≤ n, 1 ≤ y1, y2 ≤m),
其中k表示PIPI最多能转的弯数，(x1, y1),
(x2,y2)表示两个位置，其中x1，x2对应列，y1, y2对应行。
- 输出
 每组测试数据对应为一行，若PIPI能从一个位置走到另外一个位置，输出“yes”，否则输出“no”。
- 样例输入
2
5 5
...**
*.**.
.....
.....
*....
1 1 1 1 3
5 5
...**
*.**.
.....
.....
*....
2 1 1 1 3
- 样例输出
no
yes
*/

// 难！
// 注意：题中给坐标是列在前，算法按照习惯改成行在前。
// 在每次转弯的时候，都直接走到底，这样每次到达的地方都是转弯次数最少的。
// 因为如果拐弯的话，转弯的次数肯定是比这多的，所以这题的思路就是这直接走到底走到不能走位置。

#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};  // 上下左右

typedef struct {
  int x, y, turn;
} Point;

bool EscapeMaze(const std::vector<std::string>& maze, int k, int x1, int y1,
                int x2, int y2) {
  // 特殊情况
  if (maze[x1][y1] == '*' || maze[x2][y2] == '*') {
    return false;
  }
  if (x1 == x2 && y1 == y2) {
    return true;
  }

  Point st, curr, next;
  std::queue<Point> q;
  int m = maze.size(), n = maze[0].size();
  int visited[m][n];  // 记录迷宫结点是否被访问
  memset(visited, 0, sizeof(visited));
  
  //起点加入队列
  st.x = x1;
  st.y = y1;
  st.turn = -1;
  q.push(st);
  visited[x1][y1] = 1;

  while (!q.empty()) {
    // 对当前结点BFS搜索
    curr = q.front();
    q.pop();
    // 转弯次数过多
    if (curr.turn >= k) {
      break;
    }
    // 找到终点
    if (curr.x == x2 && curr.y == y2) {
      return true;
    }
    for (int i = 0; i < 4; i++) {
      // 下一个位置
      next.x = curr.x + dir[i][0];
      next.y = curr.y + dir[i][1];
      next.turn = curr.turn + 1;
      while (true) {
        // 位置超出范围
        if (next.x < 0 || next.x >= m || next.y < 0 || next.y >= n) break;
        // 位置不通
        if (maze[next.x][next.y] == '*') break;
        // 找到终点
        if (next.x == x2 && next.y == y2) {
          return true;
        }
        // 未访问的点加入
        if (visited[next.x][next.y] == 0) {
          visited[next.x][next.y] = 1;
          q.push(next);
        }
        // 沿着一个方向走到底
        next.x += dir[i][0];
        next.y += dir[i][1];
      }
    }
  }
  return false;
}

int main() {
  int t, m, n;
  int k, x1, y1, x2, y2;
  while (std::cin >> t) {
    for (int i = 0; i < t; i++) {
      std::cin >> m >> n;
      std::vector<std::string> maze(m);
      for (int j = 0; j < m; j++) {
        std::cin >> maze[j];
      }
      std::cin >> k >> y1 >> x1 >> y2 >> x2;
      bool res = EscapeMaze(maze, k, x1 - 1, y1 - 1, x2 - 1, y2 - 1);
      if (res) {
        std::cout << "yes" << std::endl;
      } else {
        std::cout << "no" << std::endl;
      }
    }
  }
}