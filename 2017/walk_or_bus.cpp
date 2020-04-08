/*
1024: 走路还是坐公交
提交: 1656  解决: 445
- 题目描述
你收到通知被中南大学录取了，高兴的来到了长沙，很快你就来到了岳麓南路上，
已知你的位置是N，中南大学的位置是K。
为了去中南大学，你有两种移动方式：走路或者坐公交。
走路：你可以从位置X移动到X+1或者X-1
搭公交车：你可以从位置X移动到2X
每次走路或者搭公交车所需要的时间都是1分钟，你想尽快到达中南大学，所需的时间是多少呢？
- 输入
多组数据。
对于每组数据，输入一行，分别是N和K(0<=N,K<=100,000)
- 输出
对于每组数据，输出一行，所需时间
- 样例输入
5 17
- 样例输出
4
*/
#include <iostream>
#include <vector>

// 保存1-k任意位置所需的最小时间
int least_time[100001];

int GetLeastTime(int n, int k) {
  // 只有走路倒退的方式到达
  if (n >= k) {
    return n - k;
  }

  // 当k大于n的情况
  // 计算n倒退至1所需要的时间
  for (int i = 1; i <= n; i++) {
    least_time[i] = n - i;
  }
  // 计算n+1到k所需要的最小时间
  for (int i = n + 1; i <= k; i++) {
    if (i & 1) {
      // 如果i是奇数
      // 可以从(i-1)/2, (i+1)/2处坐公交，再退步行，共计新增2分钟
      // 或者直接i-1步行至i处，共计新增1分钟，三种情况取最小值
      least_time[i] = std::min(least_time[(i - 1) / 2], least_time[(i + 1) / 2]) + 2;
      least_time[i] = std::min(least_time[i], least_time[i - 1] + 1);
    } else {
      // i是偶数情况
      // 可以从i/2处坐公交或者i-1步行至i处，共计新增1分钟，两种情况取最小值
      least_time[i] = std::min(least_time[i / 2], least_time[i - 1]) + 1;
    }
  }
  return least_time[k];
}

int main() {
  int n, k;
  while (std::cin >> n >> k) {
    std::cout << GetLeastTime(n, k) << std::endl;
  }
  return 0;
}