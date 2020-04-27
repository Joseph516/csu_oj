/*
1110: 地砖问题
时间限制: 1 Sec  内存限制: 128 MB
提交: 939  解决: 309
- 题目描述
小明站在一个矩形房间里，这个房间的地面铺满了地砖，每块地砖的颜色或是红色或是黑色。
小明一开始站在一块黑色的地砖上，并且小明从一块地砖可以向上下左右四个方向移动到其他的地砖上，
但是他不能移动到红色地砖上，只能移动到黑色地砖上。
请你编程计算小明可以走到的黑色地砖最多有多少块。
- 输入
输入包含多组测试数据。
每组输入首先是两个正整数W和H，分别表示地砖的列行数。（1<=W，H<=25）
接下来H行，每行包含W个字符，字符含义如下：
‘.’表示黑地砖；
‘#’表示红地砖；
‘@’表示小明一开始站的位置，此位置是一块黑地砖，并且这个字符在每组输入中仅会出现一个。
当W=0，H=0时，输入结束。
- 输出
对于每组输入，输出小明可以走到的黑色地砖最多有多少块，包括小明最开始站的那块黑色地砖。
- 样例输入
7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..
0 0
样例输出
13
*/

#include <bits/stdc++.h>

typedef struct {
  int x, y;
} Point;

const int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  // 上下左右

int GetMostBlackMove(const std::vector<std::string>& bricks) {
  int h = bricks.size(), w = bricks[0].size();
  if (h == 0 || w == 0) {
    return 0;
  }
  // 寻找起点
  Point start;
  bool found = false;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (bricks[i][j] == '@') {
        start.x = i;
        start.y = j;
        found = true;
        break;
      }
    }
    if (found) {
      break;
    }
  }

  int cnt = 1;  // 初始位置是黑地砖
  int visited[h][w];
  memset(visited, 0, sizeof(visited));
  visited[start.x][start.y] = 1;

  Point next, curr;
  std::stack<Point> s;
  s.push(start);
  int dir = 0;

  while (!s.empty()) {
    curr = s.top();
    next.x = curr.x + direction[dir][0];
    next.y = curr.y + direction[dir][1];
    if (next.x < h && next.x >= 0 && next.y < w && next.y >= 0 &&
        bricks[next.x][next.y] == '.' && visited[next.x][next.y] == 0) {
      cnt++;
      s.push(next);
      visited[next.x][next.y] = 1;  // 记录已访问位置
      dir = 0;                      // ！重要，容易遗漏。
    } else {
      if (dir != 3) {
        dir++;
      } else {
        s.pop();
        dir = 0;
        // visited[curr.x][curr.y] = -1;  // 当前位置四周不通
      }
    }
  }
  return cnt;
}

/*
// 方法二：递归方法
// 可将bricks，visited和cnt设置为全局变量
void DFS(const Point& curr) {
  cnt++; // cnt 初值为0
  visited[curr.x][curr.y] = 1;

  Point next;
  int w = bricks.size(), h = bricks[0].size();
  for (int i = 0; i < 4; i++) {
    next.x = curr.x + direction[i][0];
    next.y = curr.y + direction[i][1];
    if (next.x < 0 || next.x >= h || next.y < 0 || next.y >= w) {
      continue;
    }
    if (bricks[next.x][next.y] == '.' && visited[next.x][next.y] == 0) {
      DFS(next);
    }
  }
}
*/

int main() {
  int w, h;  // 列行
  while (std::cin >> w >> h) {
    if (w == 0 && h == 0) {
      exit(0);
    }

    std::vector<std::string> bricks(h);
    for (int i = 0; i < h; i++) {
      std::cin >> bricks[i];
    }

    std::cout << GetMostBlackMove(bricks) << std::endl;
  }
  return 0;
}
