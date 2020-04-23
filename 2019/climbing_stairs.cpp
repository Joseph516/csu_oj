/*
1210: 爬楼梯游戏
时间限制: 1 Sec  内存限制: 128 MB
提交: 852  解决: 198
- 题目描述
现有n阶楼梯，PIPI从第一阶走到第n阶，每次可以跨一阶或者两阶，问PIPI从第一阶走到第n阶总共有多少种可能。
为了防止结果过大，需要让结果对p取模。
ps: p = 1e9+7.
- 输入
输入包含多组测试用例。
每组样例第一行输入楼梯的阶数n。(1<=n<=1000000)
- 输出
对于每组样例，输出方案数。最后结果对109+7取模。
- 样例输入
1
2
3
- 样例输出
1
2
3
*/
#include <iostream>

const unsigned long Kp = 1e9 + 7;

// 方法1：时间超出限制
unsigned long Solution(const unsigned long n) {
  if (n == 1) {
    return 1;
  }
  if (n == 2) {
    return 2;
  }

  unsigned long si, si_1 = 2, si_2 = 1;
  for (int i = 3; i <= n; i++) {
    // s(i) = s(i-1) + s(i-2)
    si = si_1 + si_2;
    si_2 = si_1 % Kp;
    si_1 = si % Kp;
  }

  return si % Kp;
}

// 方法2：快速矩阵乘法
// 斐波那契数列的快速球法：矩阵快速幂, 时间复杂度O(logn).
/* |fib(n+1)| = |1 1| * |fib(n)  | = |1 1|^n * |fib(0)|
   |fib(n)  |   |1 0|   |fib(n-1)|   |1 0|     |fib(1)|

*/
struct matrix {
  unsigned long m[2][2];
} fib, base;

//定义矩阵乘法
matrix multi(const matrix a, const matrix b) {
  matrix tmp;
  for (unsigned int i = 0; i < 2; ++i) {
    for (unsigned int j = 0; j < 2; ++j) {
      tmp.m[i][j] = 0;
      for (unsigned int k = 0; k < 2; ++k)
        tmp.m[i][j] = (tmp.m[i][j] + a.m[i][k] * b.m[k][j]) % Kp;
    }
  }
  return tmp;
}

// 求矩阵 base 的  n 次幂
unsigned long SolutionOpt(unsigned long n) {
  base.m[0][0] = base.m[0][1] = base.m[1][0] = 1;
  base.m[1][1] = 0;
  // fib 初始化
  fib.m[0][0] = 1;
  fib.m[1][1] = 2;
  fib.m[0][1] = fib.m[1][0] = 0;

  while (n) {
    if (n & 1) {
      fib = multi(fib, base);
    }
    base = multi(base, base);
    n >>= 1;  // O(logn)
  }
  return fib.m[0][1];
}

// 方法3：可以先将所有结果一次性全部算出来
// 该方法适用于n不太的情况
// int f[1000005];
// int main() {
//   int n;
//   f[1] = 1;
//   f[2] = 2;
//   for (int i = 3; i <= 1000000; i++) {
//     f[i] = f[i - 1] + f[i - 2];
//     f[i] %= Kp;
//   }
//   while (scanf("%d", &n) != EOF) {
//     // 用cin和cout时间会超限
//     printf("%d\n", f[n]);
//   }
//   return 0;
// }

int main() {
  unsigned long n;
  while (scanf("%ld", &n) != EOF) {
    // 用cin和cout时间会超限
    printf("%ld\n", SolutionOpt(n+1));
    // printf("%ld\n", Solution(n));
  }
  return 0;
}