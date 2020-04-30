/*
1256: 最小特征值之和
时间限制: 1 Sec  内存限制: 128 MB
提交: 51  解决: 30
- 题目描述
给定一个长度为 n 的数组 A 和一个整数 c，A
的特征值为前floor(n/c)个小的元素之外的元素的和。 比如A={3, 1, 6, 5, 2}, c =
2，那么 A 的特征值就为 3+5+6=14。 现要求将 A
划分为若干个子数组，使得所有子数组的特征值之和最小， 输出最小的特征值之和。
- 输入
首先输入两个整数 n，c (1<=n,c<=1e6)
接下来输入n个数字,代表数组A (0<=ai<=1e9)
- 输出
输入最小特征值之和。
- 样例输入
7 2
2 3 6 4 5 7 1
- 样例输出
17
- 提示
对于 2 3 6 4 5 7 1 可以划分为 2 3，6 4 5 7，1，那么结果就是 3 + 6 + 7 + 1 = 17
感谢太傅同学提供的原始题面，来源:
https://acm.taifua.com/archives/csu-summer-camp-2020.html
*/

#include <bits/stdc++.h>

// 注意： 划分时候不能改变原数组的顺序，否则排序后再划分，示例最小特征值和为16
// 思路：要是特征值和最小，应该尽量是c个元素为一组
long GetMiniumEVSum(std::vector<long>& a, const int n, const int c) {
  long sum = 0;

  // 处理余数r不为0的情况
  // 余数不为0时，数组前或末可以单独成为为一个划分，根据值大小觉得。
  int r = n % c;
  long sum_head = 0, sum_tail = 0;
  for (int i = 0; i < r; i++) {
    sum_head += a[i];
    sum_tail += a[n - 1 - i];
  }
  int start = r, end = n - 1;
  if (sum_head > sum_tail) {
    sum += sum_tail;
    start = 0;
    end = n - 1 - r;
  }

  // 后续每c个数作为一组
  for (int i = start; i <= end; i += c) {
    std::sort(&a[i], &a[i + c]);
    for (int j = 1; j < c; j++) {
      sum += a[i + j];
    }
  }

  return sum;
}

int main() {
  int n, c;
  while (std::cin >> n >> c) {
    std::vector<long> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    std::cout << GetMiniumEVSum(a, n, c) << std::endl;
  }
}