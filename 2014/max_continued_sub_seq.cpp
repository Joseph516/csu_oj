/*
1008: 最大连续子序列
时间限制: 1 Sec  内存限制: 128 MB
提交: 954  解决: 235
- 题目描述
给定 K 个整数的序列{ N1,  N2,  ..., NK }
，其任意连续子序列可表示为{Ni,Ni+1,...,Nj}，其中1 <= i<= j <=K。
最大连续子序列是所有连续子序列中元素和最大的一个，例如给定序列{ -2, 11, -4,
13, -5, -2 } ，其最大连续子序列为{ 11, -4, 13 }
，最大和为20。编写程序得到其中最大子序列的和并输出该子序列的第一个和最后一个元素的下标。
- 输入
测试输入包含若干测试用例，每个测试用例占2 行，第 1 行给出正整数 K( <100000) ，第
2 行给出 K 个整数，每个整数的范围-10000至10000 ，中间用空格分隔。
- 输出
对每个测试用例， 在 1 行里输出最大和、
最大连续子序列的第一个和最后一个元素的下标，中间用空格分隔。
如果最大连续子序列不唯一， 则输出序号 i 和 j 最小的那个（如输入样例的第
2、3组）。若所有 K 个元素都是负数，则定义其最大和为0，输出"0 0 0"。
- 样例输入
8
6 -2 11 -4 13 -5 -2 10
20
-10 1 2 3 4 -5 -23 3 7 -21 6 5 -8 3 2 5 0 1 10 3
8
-1 -5 -2 3 -1 0 -2 0
4
-1 -2 -4 -3
- 样例输出
27 0 7
27 10 19
3 3 3
0 0 0
*/
#include <iostream>
#include <vector>

// 算法参考屈婉玲《算法设计与分析（第二版）》3.3.5

// 暴力算法，O(n^3)
void GetMaxSubSeqForce(const std::vector<int>& seq, std::vector<int>& res) {
  res = {0, 0, 0};  // res三个数值分别对应sum，first，last

  int thissum, n = seq.size();

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      thissum = 0;
      for (int k = i; k <= j; k++) {
        thissum += seq[k];
      }
      if (thissum > res[0]) {
        res[0] = thissum;
        res[1] = i;
        res[2] = j;
      }
    }
  }
}

// 分治法，O(nlogn)
// 左右边界不易确定
int GetMaxSubSeqDC(const std::vector<int>& seq, const int& left, const int& right) {
  if (left == right) {
    return seq[left] > 0 ? seq[left] : 0;
  }

  int center = left + (right - left) / 2;
  // 计算左部分的最大序列和
  int leftsum = GetMaxSubSeqDC(seq, left, center);
  // 计算右部分的最大序列和
  int rightsum = GetMaxSubSeqDC(seq, center + 1, right);
  // 计算左右横跨情况的最大序列和
  int s1 = 0, s1_temp = 0;
  for (int i = center; i >= left; i--) {
    s1_temp += seq[i];
    if (s1_temp > s1) {
      s1 = s1_temp;
    }
  }
  int s2 = 0, s2_temp = 0;
  for (int i = center + 1; i <= right; i++) {
    s2_temp += seq[i];
    if (s2_temp > s2) {
      s2 = s2_temp;
    }
  }
  int sum = s1 + s2;

  // leftsum，rughtsum，sum的最大值为序列的连续最大和
  if (leftsum > sum) {
    sum = leftsum;
  }
  if (rightsum > sum) {
    sum = rightsum;
  }
  return sum;
}

// 动态规划， O(n)
void GetMaxSubSeqDynamic(const std::vector<int>& seq, std::vector<int>& res) {
  res = {0, 0, 0};  // res三个数值分别对应sum，first，last
  int ci = 0, n = seq.size();
  for (int i = 0; i < n; i++) {
    if (ci > 0) {
      ci += seq[i];
    } else {
      ci = seq[i];
    }

    if (ci > res[0]) {
      res[0] = ci;
      res[2] = i;
    }
  }

  // 确定首位置
  int temp = res[0];
  for (int i = res[2]; i >= 0; i--) {
    temp -= seq[i];
    if(temp == 0) {
      res[1] = i;
      break; 
    }
  }
}
int main(void) {
  int k, temp;
  std::vector<int> seq, res(3);
  while (std::cin >> k) {
    seq = {};
    for (int i = 0; i < k; i++) {
      std::cin >> temp;
      seq.push_back(temp);
    }

    // GetMaxSubSeqForce(seq, res);
    // std::cout << res[0] << " " << res[1] << " " << res[2] << std::endl;

    // int sum = GetMaxSubSeqDC(seq, 0, k-1);
    // std::cout << sum << std::endl;

    GetMaxSubSeqDynamic(seq, res);
    std::cout << res[0] << " " << res[1] << " " << res[2] << std::endl;
  }
  
  return 0;
}