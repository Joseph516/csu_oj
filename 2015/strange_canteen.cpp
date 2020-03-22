/*
1014: 奇怪的餐厅
时间限制: 1 Sec  内存限制: 128 MB
提交: 551  解决: 199
- 题目描述
鲁大师和他的朋友经常去一家奇怪的餐厅，为什么说奇怪呢，一是餐厅提供的菜品比较奇怪，二是餐厅的付费规则比较奇怪，
每个人有不同的折扣上限（单人从总结里折算的最高金额），超过折扣上限的部分原价付费（N个人可以每人出一部分），
这次鲁大师和魏然层风以及朋友一共N个人去这家餐厅吃饭，他们点的菜品总金额为T，
现在告诉你每个人的折扣率z和折扣上限H，请告诉他们最少需要支付多少钱？
- 输入
输入数据有多组，每组占N+1行，第一行是N和T，接下来N行，每行两个数字z和H（0<N<100）。
- 输出
对于每组输入数据，输出一行，对应一个要求的答案。答案向下取整。
- 样例输入
2 100
0.7 70
0.6 50
3 500
0.6 100
0.8 200
0.7 100
1 100
0.6 100
- 样例输出
65
390
60
*/

#include <iostream>
#include <vector>
#include <algorithm>

int GetMinCost(std::vector<std::vector<float>>& bill, int total) {
  std::sort(bill.begin(), bill.end(),
            [](const std::vector<float>& lhs, const std::vector<float>& rhs) {
              return lhs[0] < rhs[0];
            });
  float cost = 0;
  float single_cost;
  for(int i = 0; i < bill.size(); i++) {
    if(bill[i][1] <= total) {
      cost += bill[i][0] * bill[i][1];
      total -= bill[i][1]; 
    } else{
      cost += bill[i][0] * total;
      total = 0; 
    }
  }

  cost += total;
  return (int)cost;
}

int main() {
  int n, t;
  while (std::cin >> n >> t) {
    std::vector<std::vector<float>> bill(n, std::vector<float>(2, 0));
    for(int i = 0; i < n; i++) {
      std::cin >> bill[i][0] >> bill[i][1];
    }
    std::cout << GetMinCost(bill, t) << std::endl;
  }
  return 0;
}