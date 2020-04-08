/*
1022: 淘金
时间限制: 1 Sec  内存限制: 128 MB
提交: 563  解决: 254
- 题目描述
在一片n*m的土地上，每一块1*1的区域里都有一定数量的金子。
这一天，你到这里来淘金，然而当地人告诉你，如果你挖了某一区域的金子，
上一行，下一行，左边，右边的金子你都不能被允许挖了。
那么问题来了：你最多能淘金多少？
- 输入
对于每组数据，第一行两个数n,m，表示土地的长和宽(1<=n,m<=200)
接下来n行,每行m个数，表示每个区域的金子数量，每个区域的金子数量不超过1000
- 输出
对于每组数据，输出最多得到的金子数量
- 样例输入
4 6
11 0  7  5  13 9
78 4  81 6  22 4
1  40 9  34 16 10
11 22 0  33 39 6
- 样例输出
242
*/

#include <cstring>
#include <iostream>
#include <vector>

// 动态规划
int GetSingleMostGold(const std::vector<int>& map_single) {
  int m = map_single.size();
  if (m == 0) {
    return 0;
  }

  if (m == 1) {
    return map_single[0];
  } else if (m == 2) {
    return std::max(map_single[0], map_single[1]);
  } else {
    int max[m];
    max[0] = map_single[0];
    max[1] = std::max(map_single[0], map_single[1]);
    for (int j = 2; j < m; j++) {
      max[j] = std::max(max[j - 1], max[j - 2] + map_single[j]);
    }
    return max[m - 1];
  }
}

int GetMostGold(const std::vector<std::vector<int>>& map) {
  int n = map.size();
  std::vector<int> gold;
  // 求出每行可以淘金的最大值
  for (int i = 0; i < n; i++) {
    gold.push_back(GetSingleMostGold(map[i]));
  }

  // 在每行的最大值数组中求出整个淘金最大值
  return GetSingleMostGold(gold);
}

int main() {
  int n, m;
  while (std::cin >> n >> m) {
    std::vector<std::vector<int>> map(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        std::cin >> map[i][j];
      }
    }
    std::cout << GetMostGold(map) << std::endl;
  }
}