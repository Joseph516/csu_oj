/*
1019: 堆石子
时间限制: 1 Sec  内存限制: 128 MB
提交: 898  解决: 169
- 题目描述
在一片沙滩上摆放着 n堆石子。 现要将石子有次序地合并成一堆。
规定每次选2 堆相邻石子合并成新的一堆，合并的费用为新的一堆石子数。
试设计一个算法，计算出将n堆石子合并成一堆的最小总费用。
- 输入
多组数据
输入数据第1行有1个正整数 n（1≤n≤300），表示有 n堆石子，每次选2堆石子合并。
第2行有 n个整数， 分别表示每堆石子的个数（每堆石子的取值范围为[1,1000]） 。
- 输出
数据输出为一行， 表示对应输入的最小总费用。
- 样例输入
7
45 13 12 16 9 5 22
- 样例输出
313
*/

// 参考：https://blog.csdn.net/qq_40507857/article/details/81266843
// 注意计算合并费用时不要漏算，如合并1，2，3石块：合并1和2，费用为3；合并3和3，费用为6，总费用为9.
// 若不考虑相邻石块合并，则总费用为huffman树的带权路径长度和

#include <cstring>
#include <iostream>
#include <limits>
#include <vector>

const int KInf = 127;

// 解答思路：动态规划
// dp[i][j] 表示第i到第j堆石子合并成一堆，所需最小费用
// 状态转移方程：dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] -
// sum[i - 1]) 条件:i<=k<j， sum[i]：第1堆到第i堆石子的总数
// 求解：dp[1][n]
long GetMiniumCost(const std::vector<int>& rocks) {
  int n = rocks.size();
  int sum[n + 1];
  sum[0] = 0;
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + rocks[i - 1];
  }

  int dp[n + 1][n + 1];
  memset(dp, 127, sizeof(dp)); // 2139062143, 查下memset函数手册
  for (int i = 1; i <= n; i++) {
    dp[i][i] = 0;
  }
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= n; j++) {
  //     if (i == j) {
  //       dp[i][i] = 0;  // 自身石堆合并费用为0
  //     } else {
  //       dp[i][j] = KInf;
  //     }
  //   }
  // }

  for (int i = n; i != 0; i--) {
    for (int j = i + 1; j <= n; j++) {
      for (int k = i; k < j; k++) {
        dp[i][j] =
            std::min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
      }
    }
  }

  return dp[1][n];
}

int main() {
  int n;
  while (std::cin >> n) {
    std::vector<int> rocks(n, 0);
    for (int i = 0; i < n; i++) {
      std::cin >> rocks[i];
    }
    std::cout << GetMiniumCost(rocks) << std::endl;
  }
  return 0;
}