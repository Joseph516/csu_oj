/*
1003: 最少钱币数
- 题目描述
作为A公司的职员，最盼望的日子就是每月的8号了，因为这一天是发工资的日子，养家糊口就靠它了。
但是对于公司财务处的工作人员来说，这一天则是很忙碌的一天，财务处的小胡最近就在考虑一个问题：
如果每个员工的工资额都知道，最少需要准备多少张人民币，才能在给每位职员发工资的时候都不用老师找零呢？
这里假设员工的工资都是正整数，单位元，人民币一共有100元、50元、10元、5元、2元和1元六种。
- 输入
输入数据包含多个测试实例，每个测试实例的第一行是一个整数n（n<=100），表示老师的人数，然后是n个老师的工资（工资<5000）。
- 输出
每个测试用例输出一行，即凑成钱数值M最少需要的钱币个数。如果凑钱失败，输出“Impossible”。你可以假设，每种待凑钱币的数量是无限多的。
- 样例输入
3
1 2 3
2
1 2
- 样例输出
4
2
*/
#include <iostream>
#include <vector>

int GetFewestMoney(const std::vector<int>& wages) {
  // 找出最大工资
  int max_money = 0;
  for (auto w : wages) {
    if (w > max_money) {
      max_money = w;
    }
  }

  // 动态规划
  int num_arr[max_money + 1];  // 一定数值钱对应的最少纸币数
  int money_init[6] = {1, 2, 5, 10, 50, 100};  // 现有纸币种类
  int diff, min_temp;
  num_arr[0] = 0;
  num_arr[1] = 1;
  num_arr[2] = 1;
  for (int i = 3; i <= max_money; i++) {
    min_temp = num_arr[i - 1] + 1;
    for (int j = 0; j < 6; j++) {
      diff = i - money_init[j];
      if (diff >= 0) {
        if (num_arr[diff] + 1 < min_temp) {
          min_temp = num_arr[diff] + 1;
        }
      } else {
        break;
      }
    }
    num_arr[i] = min_temp;
    // std::cout << num_arr[i] << " ";
  }

  // 计算总钱币数
  int num = 0;
  for (auto w : wages) {
    num += num_arr[w];
  }
  return num;
}
int main() {
  int n, wage;             // 人数，个人工资
  std::vector<int> wages;  // 工资向量表

  while (std::cin >> n) {
    wages = {};
    for (int i = 0; i < n; i++) {
      std::cin >> wage;
      wages.push_back(wage);
    }

    if (n == wages.size()) {
      std::cout << GetFewestMoney(wages) << std::endl;
    } else {
      std::cout << "Impossible" << std::endl;
    }
  }
  return 0;
}