/*
1021: 机器人走迷宫
时间限制: 1 Sec  内存限制: 128 MB
提交: 946  解决: 236
- 题目描述
有一个愚蠢的机器人走进一个w*h的迷宫，迷宫里有空地和陷阱。
他想要访问迷宫的每个方格，但是它很笨，只会按照指令的方向走。
当机器人不能走的时候，也就是下一步会遇到陷阱、迷宫边界或者访问过的格子，
它会向右转90度(顺时针旋转90度，不能访问已经访问过的方格，且在原地只转一次，移动后可获得又一次旋转机会)。
请问这个机器人最多可以经过多少个方格。
例如：
5 5
R****
*****
*****
*****
*****
机器人可以经过25个格子，但是
2 3
**L
***
机器人只能经过3个格子。

- 输入
对于每组数据，第一行两个数w和h，表示迷宫的行和列(1<=w,h<=10)
接下来w行每行有h个字符用于描述这个迷宫。迷宫的‘.’表示空地，即为可以走的地方。
‘*’表示陷阱，即为不能走的地方。迷宫中有一个英文字母，表示机器人的出发点，字母只有’U’,’D’,’L’,’R’四种。
分别表示机器人的初始指令是向上，向下，向左，向右。
- 输出
对于每组数据，输出一个整数，即机器人一共经过多少个方格。
- 样例输入
2 3
U..
.*.
4 4
R...
.**.
.**.
....
- 样例输出
4
12
*/

#include <cstring>
#include <iostream>
#include <vector>

typedef struct {
  int x, y;
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

int GetPassedSteps(const std::vector<std::string>& maze, const int w,
                   const int h) {
  int cnt = 0, wrong_try = 0;
  Point curr, next_pos;  // 当前位置,下一个位置
  char dir;              // 当前运动方向
  int visited[w][h];     // 记录迷宫结点是否被访问
  memset(visited, 0, sizeof(visited));

  // 确定起始方向,即初始指令字母所在位置.
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      if (maze[i][j] == 'U' || maze[i][j] == 'D' || maze[i][j] == 'R' ||
          maze[i][j] == 'L') {
        curr.x = i;
        curr.y = j;
        dir = maze[i][j];
        break;
      }
    }
  }

  visited[curr.x][curr.y] = 1;
  cnt++;
  while (wrong_try != 2) {
    // 下一个位置
    NextPos(curr, next_pos, dir);
    if (next_pos.x >= 0 && next_pos.x < w && next_pos.y >= 0 &&
        next_pos.y < h && maze[next_pos.x][next_pos.y] == '.' &&
        visited[next_pos.x][next_pos.y] == 0) {
      curr = next_pos;
      visited[curr.x][curr.y] = 1;
      cnt++;
      wrong_try = 0;
    } else {
      dir = NextDir(dir);
      wrong_try++;  // 错误试探自增
    }
  }

  return cnt;
}

int main() {
  int w, h;
  while (std::cin >> w >> h) {
    // TODO: 如果采用char保存maze数据会显示答案错误,原因?
    std::vector<std::string> maze(w);
    for (int i = 0; i < w; i++) {
      std::cin >> maze[i];
    }
    std::cout << GetPassedSteps(maze, w, h) << std::endl;
  }
  return 0;
}