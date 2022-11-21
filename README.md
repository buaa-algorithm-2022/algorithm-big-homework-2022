# algorithm-big-homework-2022

算法大作业的代码仓库。

## 小组命名
WA自动机队


# 一、作业要求
**《程序设计与算法》大作业**

大家根据自己的兴趣和知识熟悉程度，进行大作业选题，并按照下面的要求完成。

【选题清单】
（1）【排序算法：选择排序，归并排序，快速排序，希尔排序，基数排序】，对所有算法进行分析并实现，分析其在不同规模的输入下单机性能变化情况；同时实现对于以下两种输入的排序:  
①对数值的范围在[{-10}^{100},{10}^{100}]的数组排序，此项任务只能使用C或C++完成。  
②利用多线程实现大规模数据的分布式排序，输入超过100万为最低大规模要求。  
（2）【图算法：PageRank，子图匹配】，尝试选择一种图算法进行复杂度分析并实现，分析其在不同规模的图问题上的性能变化情况；同时调研其分布式实现的框架和性能。  
（3）【智能算法：模拟退火，遗传算法，蚁群算法，禁忌搜索】，尝试选择两种智能算法进行分析并实现，分析其算法复杂度受影响的可能因素，分析其至少在两种特定问题中解决的优劣势。  
（4）【机器学习算法：xgboost，支持向量机，随机森林，卷积神经网络】，尝试选择一种机器学习算法进行分析并实现（深度学习方法不能使用框架），分析其算法复杂度受影响的可能因素，并思考与传统算法分析的异同。

以上题目实现，如无特殊说明不限制代码语言的选择。要求用github/gitee对代码进行管理，需要写readme.md文件作为完成大作业的一部分。


【组队要求】
每队限制3名学生，自行商定一名组长，并明确各自分工。
请将组队信息填报到在线文档中：
https://docs.qq.com/sheet/DWU1tSU9JZGlzdEFE?tab=BB08J2


【提交要求】
提交时请提交“**代码+报告(readme转换为PDF)+答辩ppt**”的压缩文件，并附上代码的仓库连接。命名为“组长学号_队伍名_大作业”，如“ZF1234567_北航队_大作业.zip”。  
提交地址：https://bhpan.buaa.edu.cn:443/link/63102068A3BE541D9A7A8C577CA1B04D  
（访问密码：H5oW）。  
最晚提交时间：11月14日（最后一次课前）  

## 说明
排序算法中的要求（1）需要所有排序算法全部实现。要求（2）分布式尽量实现。  
提醒一下，这两个要求不需要同时满足，分类讨论即可。  
![image](https://user-images.githubusercontent.com/28506614/199456658-b3dc2e5e-42e0-42c9-9b84-3165d1bc8a60.png)


## 备选题目
1、排序算法  
2、随机森林 https://www.jianshu.com/p/fdcda700d135  
3、卷积神经网络  

# 二、git说明
https://www.runoob.com/git/git-basic-operations.html
## 常用命令
|命令                |说明|
|:-------------------|:----------|
|git pull            |拉取当前分支的远程代码 |
|git pull origin main|从远程main分支拉取代码到当前分支|
|git add .           |将当前文件夹下的所有更改提交到暂存区  |
|git commit -m ''    |提交暂存区到本地仓库。|
|git push            |将当前分支代码上传远程并合并|
|git diff            |比较文件的不同，即暂存区和工作区的差异。   |
|git branch -a       |列出所有分支|
|git branch test     |创建分支    |
|git checkout test   |切换分支    |

## 代码提交规范
每个人创建自己的分支。修改都是基于自己的分支，修改完成后提交merge请求，代码审核通过后merge到main分支。


# 三、作业选题调研
## 1、排序算法调研
（1）【排序算法：选择排序，归并排序，快速排序，希尔排序，基数排序】，对所有算法进行分析并实现，分析其在不同规模的输入下单机性能变化情况；同时实现对于以下两种输入的排序:
①对数值的范围在[{-10}^{100},{10}^{100}]的数组排序，此项任务只能使用C或C++完成。
②利用多线程实现大规模数据的分布式排序，输入超过100万为最低大规模要求。

### 语言选择
由于大整数排序部分只能使用c或c++完成，c++提供了丰富的公共库，所以排序算法的实现统一使用C++比较好。

### 大整数排序
定义为class/struct，通过传入的string初始化。
实现compare方法。

有两种实现：  
1、通过string类型实现，每个字符代表一个位上的数字。  
2、通过int数组实现，进制为int类型可表示的最大十进制整数。  
   这样做的好处是可以直接截取输入string的固定位数生成。  

2更节省空间，但是计算复杂度稍高。

### 多线程实现大规模数据分布式排序
https://blog.csdn.net/qq_36622751/article/details/124807254

## 2、随机森林调研

#### 优点：1）有现成代码（python底层源码），在此基础上上进行优化；2）python有很多封装好的包，可以使用，可以做的很简单，也可以很复杂
#### 难点：1）算法原理细节需要搞懂，涉及到数学知识；2）需要进行算法分析

### 具体源码

随机森林 https://github.com/scikit-learn/scikit-learn/blob/main/sklearn/ensemble/_forest.py

决策树 （随机森林是由决策树集成）https://github.com/scikit-learn/scikit-learn/blob/main/sklearn/tree/_classes.py

### 源码参数解读：
https://blog.csdn.net/ys676623/article/details/78111196

## 最终选题
综合时间和小组成员的意向，最终决定选择排序算法作为最终题目。

## 时间安排
- 调研选题：2022年11月3日  
- 代码开发：
  - 算法实现：2022年11月4日\~2022年11月8日，4天
  - 多线程实现：2022年11月9日\~2022年11月13日，5天
  - 分布式实现：2022年11月14日\~2022年11月18日，5天
- ppt准备：2022年11月19日\~2022年11月21日，3天  
- 课程答辩：2022年11月22日

## 分工
张梁：项目创建，快速排序、希尔排序，分布式实现

边俊林：基数排序，大数运算，程序框架，多线程实现

杨小梅：选择排序、归并排序算法实现，PPT制作

共同参与部分：随机数生成，readme.md文件编写

# 四、排序算法实现

## 4.1 选择排序分析
1、核心思想  
   第i趟排序从序列的后n-i+1（i=1,2,...,n-1)个元素中选择一个值最小的元素与该n-i+1元素的最前面的那个元素交换位置，即与整个序列的第i个位置上的元素交换位置。  
2、时间复杂度  
   对具体n个元素的序列采用选择排序法，要经过n-1趟排序。  
   移动次数：元素移动的次数最少为0次（当原始序列为升序时），最多为3（n-1）次（当原始序列为降序时，3是第i趟排序中，值最小元素与未排序的第一个元素交换位置的次数，即代码中交换arr[i]与arr[d]的执行次数）  
   比较次数：无论序列中元素的初始排列状态如何，第i趟排序要找出值最小元素都需要经过n-i次元素之间的比较。因此，整个排序过程中元素之间的比较总次数为n (n - 1）/ 2 。  
   因此，算法的时间复杂度为O（n2）。  
   这个算法的执行效率当n相对小的时候，效率比较快，但是n一旦扩大，效率将会下降明显。  
3、空间复杂度  
   值最小元素与未排序的第一个元素交换位置时需要设置一个临时辅助空间，空间复杂度为O（1）。  
4、稳定性分析  
   由于值最小元素与未排好序的元素中第1个元素的交换动作是在不相邻的元素之间进行的，因而很有可能会改变值相同元素的前后位置，因此选择排序法是一种不稳定的排序方法。  

## 4.2 归并排序分析
1、核心思想  
   1）将整个待排序序列划分成多个不可再分的子序列，每个子序列中仅有 1 个元素；  
   2）所有的子序列进行两两合并，合并过程中完成排序操作，最终合并得到的新序列就是有序序列。  
2、时间复杂度  
   设n为待排序数组中的元素个数，T(n)为算法需要的时间复杂度，则  
   <img src=./data/T1.png width=30% />  
   其中C(n)是将两个含有n/2个数据元素的序列合并为一个含有n个数据元素的序列所需要的比较操作次数。  
   1） 最优时间复杂度分析:  
由对合并操作的最优时间复杂度分析我们知道，当刚好一个序列的最后一个值是另一个序列的最小值时， C(n)=n/2。  
   <img src=./data/T2.png width=30% />  
   2）最坏时间复杂度分析  
   由对合并操作的最坏时间复杂度分析我们知道，当两个序列各个元素的大小交叉排列时， C(n)=n-1。  
   <img src=./data/T3.png width=40% />  
   <img src=./data/T4.png width=30% />  
   综上:2路归并排序的最优时间复杂度和最坏时间复杂度均为$O(log_{2}n)$。  
3、空间复杂度  
   由于该算法需要用到与参加排序的序列同样大小的辅助空间，算法的空间复杂度为O（n）。  
4、稳定性分析  
   归并排序是一种稳定的排序算法，因为在两个有序子序列的归并过程中，若2个按值有序序列中出现相同元素，merge算法能够使前一个序列中那个相同元素先被复制，从而确保这两个相同元素的相对次序不发生改变。  
   
## 4.3 快速排序分析
1、快速排序的基本思想是：在待排序元素中选择一个基准，经过一趟排序后把元素分为小于基准元素和大于等于基准元素的两部分。然后递归的对两个子表重复上述过程，直到每个部分中只有一个元素或者为空为止。  
2、空间效率：由于快速排序是递归的，需要借助递归工作栈来保存每层递归调用的必要信息，其容量与递归调用的最大深度一致。最好情况下为$O(log_{2}n)$；最坏情况下，因为要进行n-1次递归，所以栈深度为$O(n)$；平均情况下栈的深度为$O(log_{2}n)$。  
3、时间效率：快速排序的实现使用了前后指针法，一趟排序从头尾交替搜索，直到low，hight重合，因此单趟的时间复杂度为O(n)，整个快速排序的时间复杂度与划分的趟数有关。理想情况下每次都从可以从中间划分为左右两个基本相等的两部分，共经过$log_{2}n$趟排序，最高情况下的时间复杂度为$O(log_{2}n)$。  最坏情况下，每次都将剩下的部分划分到同一侧，此时排序的趟数为n，排序的时间复杂度为$O(n^2)$。  
4、稳定性：在划分算法中，若右端区域中有两个元素相同，且小于基准值的记录，则在交换到区间左侧之后，他们的相对位置会发生变化，所以快速排序是一种不稳定的排序。

## 4.4 希尔排序分析
1、希尔排序的基本思想是：先将待排序序列表分割成若干形如L[i, i + d, i + 2d, ... , i + kd]的“特殊”子表，即把相隔固定距离的元素组成一个子表，对各个子表分别进行直接插入排序，然后不断缩小间隔的距离，当整个表的元素已基本有序时，再对全体记录进行一次直接插入排序。  
2、空间效率：由于希尔排序使用了常数个辅助单元，空间复杂度为O(1)。  
3、时间效率：由于希尔排序的时间复杂度依赖增量排序列的函数，这涉及数学上尚未解决的难题，所以其时间复杂度分析比较困难。当n在某个特定范围时，希尔排序的时间复杂度为$O(n^{1.3})$。在最坏情况下希尔排序的时间复杂度为$O(n^2)$  
4、稳定性：当相同关键字的记录被划分到不同的子表时，可能会改变他们之间的相对次序，因此希尔排序是一种不稳定的排序算法。

## 4.5 基数排序分析
1、核心思想  
- 首先按照位数从小到大(个、十、百、千、万)进行分配，依次将数据分配到对应的桶中，每次分配完成后按数值从小到大的顺序从桶中依次取出元素重新拼接成数组
- 由于数值范围为`[1e-100, 1e100]`，为了使基数排序支持负数，故分配19个桶，使用第0~19桶分别存放该位为-9~9的数
算法的描述如下  
```
RadixSort(arr,size)
   1. find max of input array arr. 
   2. find number of digits d in max. 
   3. for i = 1 to d
       3.1 sort the array elements according to ith place digits using CountingSort.

CountingSort(array, sizeOfArr, place)
   1. k --> the size of count array, size=19 is our case (storing [-9, 9])
   2. initialize count array with all elements as zeros.
   3. for i = 0 to (size-1)
       3.1 find the total count of each unique digit in dth place of elements and store the count at ith index in the count array.
   4. for i = 0 to k
       4.1 find the cumulative sum and store it in count array itself. 
   5. for j = (size-1) to 1
       5.1 store the elements from input array to output array using index from count array.
       5.2 decrease count of each element stored by 1.
```
2、时间复杂度
令n为输入数组中元素的数量，k为所有数字第i位（个、十、百、千、万）的最大值，在本算法中即k=19（用于支持负数排序，存放[-9,9]），d为所有元素中位数最多数字的位数。
由上述过程图，我们可以知道
- 计数排序的时间复杂度为O(n+k)
- 基数排序中循环调用了d次计数排序，故时间复杂度为O(d(n+k))

综上，算法总时间复杂度为O(d(n+k)))

3、空间复杂度  
如过程所示，在技术排序中，我们需要开辟O(k)的空间用于计数，同时O(n)的空间用于存放临时数组。

故算法总空间复杂度为O(n+k)
  
4、稳定性分析  
基数排序是一种稳定的排序算法，因为其将数据分配到桶中的遍历过程是按照原数组顺序的，所以对于将要放入同一个桶中的数据位置较前，从而确保这两个相同元素的相对次序不发生改变。

## 4.6 性能分析
### 4.6.1 单线程
|排序类型|线程数|数据规模|时间|
|:----------|:----------|:----------|:----------|
|选择排序|1|1万|8813ms|
|归并排序|1|1万|40ms|
|快速排序|1|1万|52ms|
|希尔排序|1|1万|74ms|
|基数排序|1|1万|400ms|
|选择排序|1|10万|917320ms|
|归并排序|1|10万|640ms|
|快速排序|1|10万|730ms|
|希尔排序|1|10万|1303ms|
|基数排序|1|10万|6084ms|

### 4.6.2 多线程
|排序类型|线程数|数据规模|时间|
|:----------|:----------|:----------|:----------|
|选择排序|8|1万|269ms|
|归并排序|8|1万|40ms|
|快速排序|8|1万|29ms|
|希尔排序|8|1万|33ms|
|基数排序|8|1万|124ms|
|选择排序|8|10万|31946ms|
|归并排序|8|10万|355ms|
|快速排序|8|10万|345ms|
|希尔排序|8|10万|432ms|
|基数排序|8|10万|1530ms|

### 4.6.3 分布式
|排序类型|节点数|总线程数|数据规模|时间|
|:----------|:----------|:----------|:----------|:----------|
|选择排序|2|8|100万|ms|
|归并排序|2|8|100万|21337ms|
|快速排序|2|8|100万|25137ms|
|希尔排序|2|8|100万|24946ms|
|基数排序|2|8|100万|ms|

## 4.7 随机数生成实现
由于大整数的位数比较多，采用对随机数%2生成符号位，然后从高位到低位，每次4位，共25次的方式来生成100位的大整数。

## 4.8 大数实现
大数的数据结构采用字符串存储数值的绝对值部分，同时使用布尔值存储数值的正负性。
考虑到实际运算中不应存在正0负0，0在存储时正负性永远视为正。

并实现大数间的比较、重载大数输入输出、基于大数生成随机数等操作。部分比较逻辑如下：

```c++
bool operator == (const BigInteger& lhs, const BigInteger& rhs) {
    if (lhs.m_content == "0" && rhs.m_content == "0")
        return true;
    return lhs.m_content == rhs.m_content && lhs.isNegative() == rhs.isNegative();
}

bool operator < (const BigInteger& lhs, const BigInteger& rhs) {
    if (lhs == rhs) return false;
    if (lhs.m_content.size() == rhs.m_content.size()) {
        if (lhs.isNegative() && rhs.isNegative())
            return lhs.m_content > rhs.m_content;
        else if (!lhs.isNegative() && !rhs.isNegative())
            return lhs.m_content < rhs.m_content;
        return lhs.isNegative();
    } else if (lhs.isNegative() && rhs.isNegative()) {
        return lhs.m_content.size() > rhs.m_content.size();
    } else if (!lhs.isNegative() && !rhs.isNegative()) {
        return lhs.m_content.size() < rhs.m_content.size();
    } else {
        return lhs.isNegative();
    }
}

bool operator > (const BigInteger& lhs, const BigInteger& rhs) {
    return operator<(rhs, lhs);
}
```

## 4.9 多线程实现
<img src=./data/multi_thread.jpg width=50% />

多线程的实现基于分治，对待排序数组划分不同区域，每个区域使用一个线程排序，最终使用归并排序合并结果。

## 4.10 分布式实现
### 4.10.1 分布式结构
<img src=./data/distributed_architecture.jpg width=70% />

分布式部分使用Java语言实现。代码中使用了通信框架Netty来建立TCP连接传送文件。
### 4.10.2 程序执行流程
1、首先启动Master，Master节点会生成slave.amount份配置文件。然后启动slave.amount个TCP Server向slave发送文件。  
2、slave与master的相应端口建立连接，接收文件。  
3、slave调用命令行工具执行C++编译的多线程排序文件进行排序。  
4、slave将排好序的文件发送给master。  
5、master收到所有slave排序完成的文件后进行文件的merge，最终生成结果文件。  

### 4.10.3 程序结构
程序的运行基于配置文件run.properties，master配置文件如下：
```
mode=master
master.ip=127.0.0.1
master.slave0.port=8881
master.slave1.port=8882
data.generate.process=./generate
data.generate.rows=10000
data.send.path=./data/send/
data.receive.path=./data/receive/
data.sort.process=./Runner
data.sort.type=QuickSort
data.merge.file=./data/result.txt

slave.amount=2
slave.name=slave1
slave.thread.amount=3

slave0.ip=127.0.0.1
slave0.port=8081
slave0.receive.file=./data/receive/file0.txt
slave0.send.file=./data/send/slave0.txt

slave1.ip=127.0.0.1
slave1.port=8082
slave1.receive.file=./data/receive/file1.txt
slave1.send.file=./data/send/slave1.txt
```

目录结构
```
./
├── Runner
├── cluster.jar
├── data
│   ├── receive
│   │   ├── slave0.txt
│   │   └── slave1.txt
│   ├── result.txt
│   └── send
│       ├── file0.txt
│       └── file1.txt
├── generate
└── run.properties
```
