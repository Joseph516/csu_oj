/*
1254: PIPI上学路
时间限制: 1 Sec  内存限制: 128 MB
提交: 503  解决: 114
- 题目描述
PIPI每天早上都要从CSU的某个位置走到另一个位置。CSU可以抽象为一个n*m的方格。
PIPI每天都要从(x1,y1)走到(x2,y2)，规定每次可以向下或者向右移动一格。
总共有q次询问，每次询问从(x1,y1)走到(x2,y2)有多少条不同的路径，答案对1000000007取模。
- 输入
输入包含多组测试用例。
对于每组测试用例，首先输入三个整数n,m,q(1<=n,m,q<=5000),代表方格的大小和询问次数。
接下来q行，每行输入四个正整数 x1, y1 ,x2,y2(1<=x1<=x2<=n ,1<=y1<=y2<=m)
。意义如题所示。
- 输出
每次询问从(x1,y1)走到(x2,y2)有多少条不同的路径。
- 样例输入
4 4 4
1 1 1 1
1 1 2 2
1 1 1 2
1 1 2 1
- 样例输出
1
2
1
1
*/

#include <bits/stdc++.h>

const long long Kmod = 1000000007;

long long p1[5005];

// 整数快速幂: a^b
long long quick_pow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % Kmod;
    a = a * a % Kmod;
    b >>= 1;
  }
  return ans;
}

// 动态规划，时间超限
long long GetPathCount(const int n, const int m, const int x1, const int y1,
                       const int x2, const int y2) {
  long long cnt[n + 1][m + 1];
  cnt[x1][y1] = 1;
  for (int i = x1 + 1; i <= x2; i++) {
    cnt[i][y1] = cnt[i - 1][y1];
  }
  for (int j = y1 + 1; j <= y2; j++) {
    cnt[x1][j] = cnt[x1][j - 1];
  }
  for (int i = x1 + 1; i <= x2; i++) {
    for (int j = y1 + 1; j <= y2; j++) {
      cnt[i][j] = cnt[i - 1][j] % Kmod + cnt[i][j - 1] % Kmod;
    }
  }

  return cnt[x2][y2];
}

// 用排列组合方式求解
// 思路：根据两点之间的曼哈顿距离是a，若x相差b1，y相差b2。
// 显然a=b1+b2，则总的路线方式为C(a, b1)或C(a, b2)
long long GetPathCount2(const int x1, const int y1, const int x2,
                        const int y2) {
  int a = x2 - x1 + y2 - y1;
  int b;
  if (x2 - x1 < y2 - y1) {
    b = x2 - x1;
  } else {
    b = y2 - y1;
  }
  // 求C(a, b) = a*(a-1)*...*(a-b+1) / (b*(b-1)*...*1)
  long long res = 1;
  int cycle_cnt = b;
  for (int i = 0; i < cycle_cnt; i++) {
    res = (res * a) % Kmod;
    // 没有(a/b)%Kmod = (a%Kmod / b%Kmod )%Kmod, 所以需要将除转化为逆元
    // 逆元：https://zhuanlan.zhihu.com/p/100587745
    res = (res * p1[b]) % Kmod;
    a--;
    b--;
  }
  return res;
}

int main() {
  int n, m, q;
  int x1, y1, x2, y2;
  // 求解逆元，注意这个方法只对Kmod是质数的情形有效。
  for (int i = 1; i <= 5000; i++) p1[i] = quick_pow(i, Kmod - 2);
  while (std::cin >> n >> m >> q) {
    for (int i = 0; i < q; i++) {
      std::cin >> x1 >> y1 >> x2 >> y2;
      // std::cout << GetPathCount(n, m, x1, y1, x2, y2) << std::endl;
      std::cout << GetPathCount2(x1, y1, x2, y2) << std::endl;
    }
  }
}