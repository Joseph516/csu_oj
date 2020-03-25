/*
1016: 加油站
时间限制: 1 Sec  内存限制: 128 MB
提交: 1118  解决: 300
- 题目描述
一辆汽车加满油后可行驶n公里。 旅途中有若干加油站。
设计一个有效算法,指出应在哪些加油站停靠加油,使沿途加油次数最少。
请对于给定的n和k个加油站位置， 计算最少加油次数。
- 输入
输入包含多组测试用例。
对于每一组数据，其第1行有2个正整数n（1≤n≤5000）和 k（1≤k≤5000）。
表示汽车加满油后可行驶 n公里，且旅途中有 k个加油站。接下来的1行中，有
k+1个整数， 表示第 k个加油站与第 k-1个加油站之间的距离。第
0个加油站表示出发地，汽车已加满油。 第 k+1个加油站表示目的地。
- 输出
数据输出一行。 如果所对应的输入数据数据可以到达， 将计算的最少加油次数输出。
如果无法到达目的地，则输出“NoSolution”。
- 样例输入
7  7
1  2  3  4  5  1  6  6
- 样例输出
4
*/

#include <iostream>
#include <vector>

// 使用贪心算法，每次汽车走到最远且离自己最近的地方加油
// 注意: 加满油后，行驶距离是恢复至n，而不是叠加。
int GetLeastGasUp(const int dist, const std::vector<int> gas_position) {
  int k = gas_position.size() - 1;
  int cnt = 0;          // 加油次数
  int dist_run = dist;  // 初始化汽车可以行驶的距离

  for (int i = 0; i <= k; i++) {
    if (dist_run >= gas_position[i]) {
      dist_run -= gas_position[i];
    } else {
      cnt++;
      dist_run = dist;  // 加满油
      if (dist_run < gas_position[i]) {
        return -1;  // 加完油仍无法行驶至下一个加油站
      } else {
        dist_run -= gas_position[i];
      }
    }
  }
  return cnt;
}

int main() {
  int n, k;
  while (std::cin >> n >> k) {
    std::vector<int> gas_position(k + 1, 0);
    for (int i = 0; i <= k; i++) {
      std::cin >> gas_position[i];
    }

    int cnt = GetLeastGasUp(n, gas_position);

    if (cnt == -1) {
      std::cout << "NoSolution" << std::endl;
    } else {
      std::cout << cnt << std::endl;
    }
  }

  return 0;
}