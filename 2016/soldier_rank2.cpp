/*
1018: 士兵排阵
时间限制: 1 Sec  内存限制: 128 MB
提交: 559  解决: 232
- 题目描述
在一个划分成网格的操场上，n个士兵散乱地站在网格点上。
网格点由整数坐标(x,y)表示。 士兵们可以沿网格边上、 下、 左、 右移动一步，
但在同一时刻任一网格点上只能有一名士兵。
按照军官的命令，士兵们要整齐地列成一个水平队列，即排列成(x,y),(x+1,y),…,(x+n-1,y)。
如何选择 x 和 y的值才能使士兵们以最少的总移动步数排成一列。
计算使所有士兵排成一行需要的最少移动步数。
- 输入
多组测试用例。
对于每一组测试用例,第1行是士兵数 n， 1≤n≤10000。 接下来 n行是士兵的初始位置，
每行有2个整数 x和 y，-10000≤x， y≤10000。
- 输出
数据的输出为一行， 表示士兵排成一行需要的最少移动步数。
- 样例输入
5
1 2
2 2
1 3
3 -2
3 3
- 样例输出
8
*/

/*
解题思路：
移动距离等于：横向移动距离+纵向移动距离，理论：最小一乘法的解是中位数。
根据题意，要求所有士兵的最小移动步数，首先要找出他们需站成的水平队列的第一个坐标（x,y）。
1.求纵坐标y：需要|y0-y|+|y1-y|+…+|(yn-1)-y|最小，即士兵纵坐标的中位数为所求纵坐标y。
2. 求横坐标x：设每个士兵的横坐标按由小到大排序后为X0，X1，X2,……
所以，所有士兵在x方向的移动步数为|X0-x|+|X1-(x+1)|+…+|Xn-1-(x+n-1)|
= |X0-x|+|(X1-1)-x|+…+|(Xn-1-(n-1))-x|。
可以发现，要使该式子最小，则x为X0,X1-1,X2-2,…,Xn-1-(n-1)的中位数。
3. 根据曼哈顿距离计算公式求出移动距离
*/

#include <algorithm>
#include <iostream>
#include <vector>

// 优化前
int GetLeastMove(std::vector<std::vector<int>>& position) {
  int n = position.size();
  std::vector<int> temp(n, 0);

  // 计算y坐标
  for (int i = 0; i < n; i++) {
    temp[i] = position[i][1];
  }
  std::sort(temp.begin(), temp.end(),
            [](const int lhs, const int rhs) { return lhs < rhs; });
  int y = temp[temp.size() / 2];

  // 计算x坐标
  for (int i = 0; i < n; i++) {
    temp[i] = position[i][0];
  }
  std::sort(temp.begin(), temp.end(),
            [](const int lhs, const int rhs) { return lhs < rhs; });

  for (int i = 0; i < n; i++) {
    temp[i] -= i;
  }
  std::sort(temp.begin(), temp.end(),
            [](const int lhs, const int rhs) { return lhs < rhs; });
  int x = temp[temp.size() / 2];

  std::sort(position.begin(), position.end(),
            [](const std::vector<int>& lhs, const std::vector<int>& rhs) {
              return lhs[0] < rhs[0];
            });
  // 计算总距离
  int dist = 0;
  for (int i = 0; i < n; i++) {
    dist += abs(position[i][0] - x - i) + abs(position[i][1] - y);
  }

  return dist;
}

int main() {
  int n;
  while (std::cin >> n) {
    std::vector<std::vector<int>> position(n, std::vector<int>(2, 0));
    for (int i = 0; i < n; i++) {
      std::cin >> position[i][0] >> position[i][1];
    }
    std::cout << GetLeastMove(position) << std::endl;
  }
  return 0;
}