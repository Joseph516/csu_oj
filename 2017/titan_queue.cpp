/*
1023: 巨人排队
提交: 981  解决: 202
- 题目描述
巨人国的小学生放假了，老师要给小朋友们排队了。
可是这个老师有强迫症，一定要路队上的小朋友按照身高从高到矮排序（也就是排在前面的不能比后面的矮）。
小朋友呢也很调皮，一旦老师给他排好队就不愿意动了。
这个时候小朋友们一个一个的从教室里出来了，每个小朋友一出来老师就要给小朋友安排好位置。
请问老师最少要给小朋友排几条路队呢？
- 输入
对于每组数据，第一行一个数n，表示小朋友总数量(1<=n<=100000)
第二行n个整数，表示小朋友身高，身高不超过30000
- 输出
对于每组数据，输出一个整数，表示最少的路队数
- 样例输入
8
389 207 155 300 299 170 158 65
- 样例输出
2
- 提示
最少要排两条路队，其中一种方案是398-207-155-65 和 300-299-170-158
*/
#include <iostream>
#include <vector>

// 时间超限
int GetQueueNum(const std::vector<int>& titan) {
  int n = titan.size();
  std::vector<int> tail;  // 保存队尾身高（特点：队尾身高为增序）

  for (int i = 0; i < n; i++) {
    // 新来的小朋友在离身高最近的位置插入
    int min_indx = -1;
    int min_height = 30000;
    for (int j = 0; j < tail.size(); j++) {
      int diff = tail[j] - titan[i];
      if (diff > 0 && diff <= min_height) {
        min_indx = j;
        min_height = diff;
      }
    }
    if (min_indx == -1) {
      tail.push_back(titan[i]);
    } else {
      tail[min_indx] = titan[i];
    }
  }

  return tail.size();
}

// 折半查找优化
int GetQueueNumOptim(const std::vector<int>& titan) {
  int n = titan.size();
  std::vector<int> tail;  // 保存队尾身高（特点：队尾身高为增序）

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    // 如果大于最后一队的队尾身高，则直接插入新队
    if (i == 0 || titan[i] > tail[cnt - 1]) {
      tail.push_back(titan[i]);
      cnt++;
    } else {
      // 由于队尾数组是增序，则采用折半查找更新队尾数据
      int low = 0, high = cnt - 1, mid = 0;
      while (low < high) {
        mid = low + (high - low) / 2;
        if (tail[mid] == titan[i]) {
          break;
        } else if (tail[mid] < titan[i]) {
          low = mid + 1;
        } else {
          high = mid;
        }
      }
      if (low >= high) {
        tail[high] = titan[i];
      }
    }
  }

  return cnt;
}

int main() {
  int n;
  while (std::cin >> n) {
    std::vector<int> titan(n, 0);
    for (int i = 0; i < n; i++) {
      std::cin >> titan[i];
    }
    std::cout << GetQueueNumOptim(titan) << std::endl;
  }
  return 0;
}
