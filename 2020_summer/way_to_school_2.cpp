// cnt数组占用内存过大出现segment falut

#include <bits/stdc++.h>

const long long Kmod = 1000000007;
const int Kmax = 5000;

long long cnt[Kmax + 1][Kmax + 1];

int main() {
  cnt[1][1] = 1;
  for (int i = 2; i <= Kmax; i++) {
    cnt[i][1] = cnt[i - 1][1];
  }
  for (int j = 2; j <= Kmax; j++) {
    cnt[1][j] = cnt[1][j - 1];
  }
  for (int i = 2; i <= Kmax; i++) {
    for (int j = 2; j <= Kmax; j++) {
      cnt[i][j] = (cnt[i - 1][j] + cnt[i][j - 1]) % Kmod;
    }
  }

  int n, m, q;
  int x1, y1, x2, y2;
  while (std::cin >> n >> m >> q) {
    long long res[q];
    for (int i = 0; i < q; i++) {
      std::cin >> x1 >> y1 >> x2 >> y2;
      res[i] = (cnt[x2][y2] - cnt[x1][y1] + 1);
    }
    for (int i = 0; i < q; i++) {
      std::cout << res[i] << std::endl;
    }
  }
}