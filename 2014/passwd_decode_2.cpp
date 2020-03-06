/*
1007: 破译密码
时间限制: 1 Sec  内存限制: 128 MB
提交: 684  解决: 272
[提交] [状态] [讨论版] [命题人:外部导入]
- 题目描述
据说最早的密码来自于罗马的凯撒大帝。消息加密的办法是：对消息原文中的每个字母，分别用该字母之后的第5个字母替换（例如：消息原文中的每个字母A
都分别替换成字母F）。而你要获得消息原文，也就是要将这个过程反过来。 密码字母：A
B C D E F G H I J  K L M N O P Q R S T U V W X Y Z 原文字母：V W X Y Z A B C D E
F G H I J  K L M N O P Q R S T U （注意：
只有字母会发生替换，其他非字母的字符不变，并且消息原文的所有字母都是大写的。）

- 输入
最多不超过 100 个数据集组成，每个数据集之间不会有空行，每个数据集由 3 部分组成:
起始行： START
密码消息：由 1 到 200 个字符组成一行，表示凯撒发出的一条消息.
结束行： END
在最后一个数据集之后，是另一行：ENDOFINPUT。
- 输出
每个数据集对应一行，是凯撒的原始消息。

- 样例输入
START
NS BFW, JAJSYX TK NRUTWYFSHJ FWJ YMJ WJXZQY TK YWNANFQ HFZXJX
END
START
N BTZQI WFYMJW GJ KNWXY NS F QNYYQJ NGJWNFS ANQQFLJ YMFS XJHTSI NS WTRJ
END
START
IFSLJW PSTBX KZQQ BJQQ YMFY HFJXFW NX RTWJ IFSLJWTZX YMFS MJ
END
ENDOFINPUT
- 样例输出
IN WAR, EVENTS OF IMPORTANCE ARE THE RESULT OF TRIVIAL CAUSES
I WOULD RATHER BE FIRST IN A LITTLE IBERIAN VILLAGE THAN SECOND IN ROME
DANGER KNOWS FULL WELL THAT CAESAR IS MORE DANGEROUS THAN HE
*/

#include <iostream>
#include <string>

void PasswdDecode(const std::string& in, std::string& out) {
  for (auto c : in) {
    if (c >= 'A' && c <= 'Z') {
      out.push_back('A' + (c - 'A' + 21) % 26);
    } else {
      out.push_back(c);  // 处理非字符
    }
  }
}

int main() {
  std::string in;

  while (getline(std::cin, in)) {
    if (in == "ENDOFINPUT") {
      break;
    }
    if (in == "START" || in == "END") {
      continue;
    }

    std::string message_out;
    PasswdDecode(in, message_out);
    std::cout << message_out << std::endl;
  }
  return 0;
}