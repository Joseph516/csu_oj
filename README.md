# 中南大学历年机试解答

使用语言：c++

## 试题

### 2013

[回文串问题](/2013/palindrome_string.cpp)

[水仙花数](/2013/num_narciscus.cpp)

[安全密码](/2013/safe_password.cpp)

[最少钱币数](/2013/fewest_money.cpp)

[惠民工程](/2013/benefit_project.cpp)

### 2014

[成绩转换](/2014/grades_translation.cpp)

[最大连续子序列](/2014/max_continued_sub_seq.cpp)

[破译密码1](/2014/passwd_decode.cpp)  

[破译密码2](/2014/passwd_decode_2.cpp)

[安全路径](/2014/safe_path.cpp)  

[平方和与立方和](/2014/square_cube_sum.cpp)

### 2015

[电子地图](2015/e_map.cpp)

[容易的题](2015/easy_question.cpp)

[数字](2015/number.cpp)

[奇怪的餐厅](2015/strange_canteen.cpp)

[防水堤坝](2015/strange_dam.cpp)

### 2016

[序列求平均](2016/average_sequence.cpp)

[加油站](2016/gas_station.cpp)

[堆石子](2016/rock_fill.cpp)

[士兵排阵](2016/soldier_rank.cpp)

[士兵排阵2](2016/soldier_rank2.cpp)

[第几天](2016/which_day.cpp)

### 2017

[切木棍](2017/cut_stick.cpp)

[淘金](2017/gold_rush.cpp)

[机器人走迷宫](2017/robot_maze.cpp)

[巨人排队](2017/titan_queue.cpp)

[走路还是坐公交](2017/walk_or_bus.cpp)

### 2018

[a+b问题](2018/a_plus_b.cpp)

[淘金](2018/cola.cpp)

[逃离迷宫](2018/escape_maze_2.cpp)

[最短距离](2018/min_distance.cpp)

### 2019

[选球问题](2019/choose_ball.cpp)

[爬楼梯游戏](2019/climbing_stairs.cpp)

[小镇购物](2019/shopping_3.cpp)

[模拟出入栈游戏](2019/stack_simulation.cpp)

[graph's connected components(弱化版)](2019/graph_connected_components_weak.cpp)

#### TODO

[小镇购物(空间超限)](2019/shopping_1.cpp)

[小镇购物(时间超限%12)](2019/shopping_2.cpp) 

[graph's connected components(时间超限)](2019/graph_connected_components.cpp)

### 2019_summer

[地砖问题](2019_summer/floor_bricks.cpp)

[十六进制转换](2019_summer/hexadecimal.cpp)

[最小花费](2019_summer/least_cost.cpp)

[回文串](2019_summer/palindrome_string.cpp)

[有序合并](2019_summer/seq_merge.cpp)

### 2020_summer

[最小价值和](2020_summer/least_cost.cpp)

[最大容量和](2020_summer/max_volume_sum.cpp)

[最小特征值之和](2020_summer/minium_eigenvalue_sum.cpp)

[缺失的彩虹](2020_summer/missing_rainbow.cpp)

[PIPI上学路](2020_summer/way_to_school.cpp)

## 注意事项

1. 算法格式错误可能是因为在有多个输出情况下，答案要求一一及时输出，而不是统一输出。见2014年破译密码1。

2. 算法可能因为精度答案出错，如float与double；可能因为发生溢出而答案出错。

3. `memeset()`是按字节赋值的，对于非字符类型的初始化：

   可以使用<algotithm>头文件中的fill函数直接进行数值填充。

```c++ 
int a[10];
memset(a, 0, sizeof(a)); // a[0] = 0x00000000
memset(a, 1, sizeof(a)); // a[0] = 0x01010101
memset(a, 127, sizeof(a)); // a[0] = 0x7f7f7f7f
memset(a, 255, sizeof(a)); // a[0] = 0xffffffff = -1
```