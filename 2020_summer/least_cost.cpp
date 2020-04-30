/*
1253: 最小价值和
时间限制: 1 Sec  内存限制: 128 MB
提交: 604  解决: 189
- 题目描述
给定 n 个整数对(ai, bi) , 每个整数对的价值是(i-1)*ai + (n-i)*bi (下标从1开始，
这里的 ai 、bi 和输入不一定对应)，然后问所有整数对的最小价值总和。
- 输入
输入包含多组测试用例。
对于每组测试用例，首先输入数对的数量n(n<=1e5)
接下来输入n对数对 ai bi (0<=ai,bi<=1e9)
- 输出
对于每组测试用例，输出这些整数对的最小价值总和。
- 样例输入
3
3 2
2 4
6 1
- 样例输出
11
提示
0 * 6 + 2 * 1 + 1 * 3 + 1 * 2 + 2 * 2 + 0 * 4 = 11
*/

#include <bits/stdc++.h>

// 思路：
// pair1位于位置i，pair2位于位置j：
// (i - 1) * a1 + (n - i) * b1 + (j - 1) * a2 + (n - j) * b2  ①
// pair2位于位置i，pair1位于位置j：
// (i - 1) * a2 + (n - i) * b2 + (j - 1) * a1 + (n - j) * b1  ②
// ① - ②：(j - i)(b1 + a2 - a1 - b2)
// 若① < ②：b1 + a2 < a1 + b2  即：a1 - b1 > a2 - b2 反之则：a2 - b2 > a1 - b1
long GetLeastCost(std::vector<std::vector<long>>& pair) {
  int n = pair.size();
  std::sort(pair.begin(), pair.end(),
            [](const std::vector<long>& lhs, const std::vector<long>& rhs) {
              return lhs[0] - lhs[1] > rhs[0] - rhs[1];
            });
  long res = 0;
  for (int i = 0; i < n; i++) {
    res += i * pair[i][0] + (n - 1 - i) * pair[i][1];
  }
  return res;
}

int main() {
  int n;
  while (std::cin >> n) {
    std::vector<std::vector<long>> pair(n, std::vector<long>(2, 0));
    for (int i = 0; i < n; i++) {
      std::cin >> pair[i][0] >> pair[i][1];
    }
    std::cout << GetLeastCost(pair) << std::endl;
  }
}