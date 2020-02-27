/*
1002: 安全密码
- 题目描述
网络上各类交易活动越来越普及，为了能够安安心心地上网，经常需要设置一个安全的密码。一般来说一个比较安全的密码至少应该满足下面两个条件：
(1)密码长度大于等于8。
(2)密码中的字符应该来自下面“字符类别”中四组中的至少三组。
这四个字符类别分别为：
(1)大写字母：A,B,C...Z;
(2)小写字母：a,b,c...z;
(3)数字：0,1,2...9;
(4)特殊符号：~,!,@,#,$,%,^;
给你一个密码，你的任务就是判断它是不是一个安全的密码。
- 输入
输入数据有多组，每组占一行，每行一个密码（长度最大可能为50），密码仅包括上面的四类字符。
- 输出
对于每个测试实例，判断这个密码是不是一个安全的密码，是的话输出YES，否则输出NO。
- 样例输入
a1b2c3d4
Linle@ACM
^~^@^@!%
- 样例输出
NO
YES
NO
*/

#include <iostream>
#include <string>

std::string IsSafePassword(const std::string password) {
  int len = password.size();
  if (len < 8) {
    return "NO";  // 长度不够
  }

  int count[4] = {0};  // 四种字符的统计
  for (int i = 0; i < len; i++) {
    int ascii_pw = int(password[i]);
    if (48 <= ascii_pw && ascii_pw <= 57) {
      count[0] = 1;  // '0'-'9':49-57
    } else if (65 <= ascii_pw && ascii_pw <= 90) {
      count[1] = 1;  // A-Z:65-90
    } else if (97 <= ascii_pw && ascii_pw <= 122) {
      count[2] = 1;  // a-z:97-122
    } else {
      count[3] = 1;  // 密码仅包括四种字符
    }
  }

  int kind = count[0] + count[1] + count[2] + count[3];

  return kind >= 3 ? "YES" : "NO";
}

int main(void) {
  std::string password;
  while (std::cin >> password) {
    std::cout << IsSafePassword(password) << std::endl;
  }
  return 0;
}