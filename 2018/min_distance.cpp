/*
1025: 最短距离
时间限制: 1 Sec  内存限制: 128 MB
提交: 940  解决: 348
- 题目描述
小王和小明是好朋友，两人最开始各有一个初始位置 p 和一个恒定速度 v，
从0时刻起开始，他们从初始位置以恒定速度开始行走，请告诉我行走过程中两人的最短距离是多少。
- 输入
第一行输入T代表测试样例数目。
对于每个样例，
第一行包含四个整数 x1，y1，x2，y2，表示人的起点（x1，y1），（x2，y2）。
第二行是四个整数u1，v1，u2，v2，表示人的初始速度（u1，v1），（u2，v2）（分别为x轴和y轴方向的分速度）。
T <= 1000 , x1，y1，x2，y2，u1，v1，u2，v2的绝对值不大于1000。
- 输出
对于每个样例，输出一行。"Case i: d"。i
代表案例编号，d代表答案，四舍五入到小数点后6位。
- 样例输入
5
1 1 2 2
1 1 2 2
1 1 2 2
1 1 -1 -1
1 1 2 2
0 1 0 -1
1 1 1 1
1 1 2 2
0 0 0 1
0 1 1 0
- 样例输出
Case 1: 1.414214
Case 2: 0.000000
Case 3: 1.000000
Case 4: 0.000000
Case 5: 0.707107
*/
#include <cmath>
#include <iostream>
#include <vector>

void PrintMinDist(const std::vector<std::vector<int>>& in, const int n) {
  int indx = 1;
  double dist;  // 最短距离
  for (int i = 0; i < n * 2; i += 2) {
    // 求出相对速度与距离
    int rx = in[i][2] - in[i][0];
    int ry = in[i][3] - in[i][1];
    int rvx = in[i + 1][2] - in[i + 1][0];
    int rvy = in[i + 1][3] - in[i + 1][1];

    // 起点与原点的连线与速度方向的夹角
    double mod_start = sqrt(rx * rx + ry * ry);
    double mod_speed = sqrt(rvx * rvx + rvy * rvy);
    if (mod_start == 0 || mod_speed == 0) {
      printf("Case %d: %.6f\n", indx++, mod_start);
      continue;
    }
    double cos = (double)(-rx * rvx - ry * rvy) / (mod_start * mod_speed);
    if (cos <= 0) {
      // 夹角超过90度，取起点与原点的距离
      dist = mod_start;
    } else {
      // TODO: 方法1在oj提交时显示答案错误
      // 1. 求相对坐标下的直线方程
      // if (rvx == 0) {
      //   // 斜率不存在
      //   dist = abs(rx);
      // } else {
      //   double k = (double)rvy / rvx;
      //   double b = ry - k * rx;
      //   // 原点到直线的距离
      //   dist = abs(b) / sqrt(1 + k * k);
      // }
      // 2. 利用余弦值值求出垂直距离
      dist = mod_start * sqrt(1 - cos * cos);
    }
    printf("Case %d: %.6lf\n", indx++, dist);
  }
}

int main() {
  int n;
  while (std::cin >> n) {
    std::vector<std::vector<int>> in(n * 2, std::vector<int>(4, 0));
    for (int i = 0; i < n * 2; i++) {
      for (int j = 0; j < 4; j++) {
        std::cin >> in[i][j];
      }
    }
    PrintMinDist(in, n);
  }
}