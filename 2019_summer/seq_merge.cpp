/*
1113: 有序合并
时间限制: 1 Sec  内存限制: 128 MB
提交: 450  解决: 162
- 题目描述
已知线性表LA和LB中的数据元素按值非递减有序排列，现要求LA和LB归并为一个新的线性表LC，
且LC中的数据元素仍然按值非递减有序排列。
例如，设LA=（3,5,8,11），LB=（2,6,8,9,11,15,20）则LC=（2,3,6,6,8,8,9,11,11,15,20）。
- 输入
有多组测试数据，每组测试数据占两行。
第一行是集合A，第一个整数m（0<=m<=100）代表集合A起始有m个元素，后面有m个非递减排序的整数，代表A中的元素。
第二行是集合B，第一个整数n（0<=n<=100）代表集合B起始有n个元素，后面有n个非递减排序的整数，代表B中的元素。
每行中整数之间用一个空格隔开。
- 输出
每组测试数据只要求输出一行，这一行含有m+n个来自集合A和集合B中的元素。结果依旧是非递减的。每个整数间用一个空格隔开。
- 样例输入
4 3 5 8 11
7 2 6 8 9 11 15 20
- 样例输出
2 3 5 6 8 8 9 11 11 15 20
*/

#include <bits/stdc++.h>

void Merge(const std::vector<int>& a, const std::vector<int>& b) {
  int m = a.size(), n = b.size();
  int i = 0, j = 0;
  while (i != m && j != n) {
    if (a[i] < b[j]) {
      std::cout << a[i] << " ";
      i++;
    } else {
      std::cout << b[j] << " ";
      j++;
    }
  }
  while (i != m) {
    std::cout << a[i] << " ";
    i++;
  }
  while (j != n) {
    std::cout << b[j] << " ";
    j++;
  }
  // 多打印一个空格也没有关系
  std::cout << std::endl;
}

int main() {
  int m, n;
  while(std::cin >> m) {
    std::vector<int> a(m);
    for(int i = 0; i < m; i++) {
      std::cin >> a[i];
    }
    std::cin >> n;
    std::vector<int> b(n);
    for(int i = 0; i < n; i++) {
      std::cin >> b[i];
    }
    Merge(a, b);
  }
}