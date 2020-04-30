/*
1255: 最大容量和
时间限制: 1 Sec  内存限制: 128 MB
提交: 538  解决: 164
- 题目描述
有 m 根木棍，m = n * k，n 个桶，每个桶由 k 块木板构成，
桶的容量由最短的木板长度决定，桶的底面积为 1，
现要求任意两个桶间的容量差小于等于 L，问 n 个桶的最大容量和。
如果无法满足组成n个桶，输出0.
- 输入
第一行输入三个整数 n,k, L(n*k<=1e5)。
第二行输入n*k根木板长度，a1,a2,a3...1 ≤ ai ≤ 10^9
- 输出
输出n个木桶最大容量和。
- 样例输入
4 2 1
2 2 1 2 3 2 2 3
- 样例输出
7
- 提示
这四个桶可以是1 2, 2 2, 2 3, 2 3，那么答案就是1+2+2+2 = 7。
*/

#include <bits/stdc++.h>

long GetMaxiumVolume(std::vector<long>& a, const int n, const int k,
                     const int l) {
  // 升序
  std::sort(a.begin(), a.end());
  long volume = 0;
  int m = n * k;

  long min = a[0];  // 最小容量
  int indx_long = -1;    // 第一个不满足长度要求的长木板的索引
  for (int i = 0; i < m; i++) {
    if (a[i] - min > l) {
      indx_long = i;
      break;
    }
  }

  if (indx_long != -1) {
    // 长木板数量过多，无法满足任意两个桶间的容量差小于等于L
    if (m - indx_long > m - n) {
      return 0;
    }
    // 将较长的木板与短木板搭配构成桶，可以理解长木板被削短。
    int i = 1, indx_short = indx_long - 1;
    while (indx_long < m) {
      // 尽量将长木板与次长木板组合，每块次长木板可以搭配k-1块长木板。
      if (i < k) {
        a[indx_long++] = a[indx_short];
        i++;
      } else {
        indx_short--;
        i = 1;
      }
    }
    // 升序
    std::sort(a.begin(), a.end());
  }

  for (int i = 0; i < m; i += k) {
    volume += a[i];
  }
  return volume;
}

int main() {
  int n, k, l, m;
  while (std::cin >> n >> k >> l) {
    m = n * k;
    std::vector<long> a(m);
    for (int i = 0; i < m; i++) {
      std::cin >> a[i];
    }
    std::cout << GetMaxiumVolume(a, n, k, l) << std::endl;
  }
}
