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

// 注意：题中给坐标是列在前，算法按照习惯改成行在前。
// TODO: 这里搜索到的不是起点终点的最短路径！

#include <cstring>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

typedef struct {
  int x, y;
  char dir;
} Point;

void NextPos(const Point& curr, Point& next_pos, const char dir) {
  switch (dir) {
    case 'U':
      next_pos.x = curr.x - 1;
      next_pos.y = curr.y;
      break;
    case 'R':
      next_pos.x = curr.x;
      next_pos.y = curr.y + 1;
      break;
    case 'D':
      next_pos.x = curr.x + 1;
      next_pos.y = curr.y;
      break;
    case 'L':
      next_pos.x = curr.x;
      next_pos.y = curr.y - 1;
      break;
  }
  next_pos.dir = dir;
}

char NextDir(const char dir) {
  switch (dir) {
    case 'U':
      return 'R';
    case 'R':
      return 'D';
    case 'D':
      return 'L';
    case 'L':
      return 'U';
  }
}

void EscapeMaze(const std::vector<std::string>& maze, int k, int x1, int y1,
                int x2, int y2) {
  int m = maze.size(), n = maze[0].size();
  if (maze[x1][y1] == '*' || maze[x2][y2] == '*') {
    std::cout << "no" << std::endl;
    return;
  }

  std::stack<Point> s;
  int cnt_turn = 0;
  Point curr, next_pos, e;  // 当前位置,下一个位置
  int visited[m][n];        // 记录迷宫结点是否被访问
  memset(visited, 0, sizeof(visited));

  curr.x = x1;
  curr.y = y1;
  curr.dir = 'U';  // 默认方向寻找为顺时针

  do {
    // 当前位置可通
    if (curr.x >= 0 && curr.x < m && curr.y >= 0 && curr.y < n &&
        maze[curr.x][curr.y] == '.' && visited[curr.x][curr.y] == 0) {
      visited[curr.x][curr.y] = 1;
      e = {curr.x, curr.y, 'U'};
      s.push(e);
      // 到达终点
      if (curr.x == y2 && curr.y == x2) {
        // 计算转弯次数
        e = s.top();
        char dir = e.dir;
        while (!s.empty()) {
          e = s.top();
          if (dir != e.dir && e.x != x1 || e.y != y1) {
            cnt_turn++;
            dir = e.dir;
          }
        }
        if (cnt_turn <= k) {
          std::cout << "yes" << std::endl;
        } else {
          std::cout << "no" << std::endl;
        }
        return;
      }
      NextPos(curr, next_pos, 'U');
      curr = next_pos;
    } else {
      if (!s.empty()) {
        e = s.top();
        s.pop();
        while (e.dir == 'L' && !s.empty()) {
          // 留些不能通过的标记
          visited[curr.x][curr.y] = -1;
          e = s.top();
          s.pop();
        }
        if (e.dir != 'L') {
          e.dir = NextDir(e.dir);
          s.push(e);
          NextPos(e, curr, e.dir);
        }
      }
    }
  } while (!s.empty());

  std::cout << "no" << std::endl;
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
      EscapeMaze(maze, k, x1 - 1, y1 - 1, x2 - 1, y2 - 1);
    }
  }
}