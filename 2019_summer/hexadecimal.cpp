/*
1114: 十六进制转换
时间限制: 1 Sec  内存限制: 128 MB
提交: 682  解决: 245
- 题目描述
输入一个不超过100000位的十六进制数，请转换成八进制数。
注：十六进制数中，字母0~9还对应表示数字0~9。字母”A”（大写）表示10，”B”表示11，”...”，”F”表示15，
比如：十六进制数A10B表示的是10进制数是10×16^3+1×16^2+0×16^1+11×16^0=41227。
转换成的八进制数是120413，因为1×8^5+2×8^4+0×8^3+4×8^2+1×8^1+3×8^0=41227。
- 输入
一个十六进制数，没有前导0（除非是数字0）。
- 输出
一个八进制数，没有前导0（除非是数字0）。
- 样例输入
123ABC
- 样例输出
4435274
*/

#include <bits/stdc++.h>

// 当hex的位数过多时，求得的十进制会溢出
void HexadecimalToOctal(const std::string& hex) {
  int n = hex.size();
  // 十六进制转十进制
  long long dec = 0;
  for (int i = 0; i < n; i++) {
    int temp;
    if (hex[i] <= 57) {
      temp = hex[i] - '0';
    } else {
      temp = hex[i] - 'A' + 10;
    }
    dec = dec * 16 + temp;
  }
  if (dec == 0) {
    std::cout << 0 << std::endl;
    return;
  }
  // 十进制转八进制
  std::stack<int> s;
  while (dec != 0) {
    s.push(dec % 8);
    dec /= 8;
  }
  while (!s.empty()) {
    std::cout << s.top();
    s.pop();
  }

  std::cout << std::endl;
}

const std::string hex_to_bin[16] = {
    "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
    "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};

void HexadecimalToOctal2(std::string& hex) {
  int n = hex.size();
  // 十六进制转二进制
  std::string bin;
  for (int i = 0; i < n; i++) {
    int indx;
    if (hex[i] <= 57) {
      indx = hex[i] - '0';
    } else {
      indx = hex[i] - 'A' + 10;
    }
    bin += hex_to_bin[indx];
  }

  // 二进制转八进制， 从高位开始
  int m = bin.size(), i;
  int r = m % 3;
  // 根据余数单独输出高位
  int temp;
  if (r == 1) {
    temp = bin[0] - '0';
    i = 1;
  } else if (r == 2) {
    temp = (bin[0] - '0') * 2 + (bin[1] - '0');
    i = 2;
  } else {
    temp = (bin[0] - '0') * 4 + (bin[1] - '0') * 2 + (bin[1] - '0');
    i = 3;
  }
  if (temp != 0) {
    std::cout << temp;
  }
  
  // 输出其余位
  while (i != m) {
    std::cout << (bin[i] - '0') * 4 + (bin[i + 1] - '0') * 2 +
                     (bin[i + 2] - '0');
    i += 3;
  }
  std::cout << std::endl;
}

int main() {
  std::string hex;
  while (std::cin >> hex) {
    // HexadecimalToOctal(hex);
    HexadecimalToOctal2(hex);
  }
}