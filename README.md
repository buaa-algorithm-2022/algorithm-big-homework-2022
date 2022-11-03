# algorithm-big-homework-2022

算法大作业的代码仓库。

## 作业要求
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
**由于校庆停课一次，最终时间应该为11月21日**

### 说明
排序算法中的要求（1）需要所有排序算法全部实现。要求（2）分布式尽量实现。  
提醒一下，这两个要求不需要同时满足，分类讨论即可。  
![image](https://user-images.githubusercontent.com/28506614/199456658-b3dc2e5e-42e0-42c9-9b84-3165d1bc8a60.png)


## 备选题目
1、排序算法  
2、随机森林 https://www.jianshu.com/p/fdcda700d135  
3、卷积神经网络  

## 时间安排
调研选题：2022年11月3日  
代码开发：2022年11月4日\~2022年11月14日，11天  
ppt准备：2022年11月15日\~2022年11月20日，6天  
课程答辩

# 作业选题调研
## 1、排序算法分析
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

#### 优点：1）有现成代码（python底层源码），但是不确定需不需要进行修改，直接使用容易撞车；2）python有很多封装好的包，可以使用，可以写的很简单，也可以很复杂
#### 难点：1）算法原理细节需要搞懂，涉及到数学知识；2）需要进行算法分析

## 具体源码

随机森林 https://github.com/scikit-learn/scikit-learn/blob/main/sklearn/ensemble/_forest.py

决策树 （随机森林是由决策树集成）https://github.com/scikit-learn/scikit-learn/blob/main/sklearn/tree/_classes.py

## 源码参数解读：
https://blog.csdn.net/ys676623/article/details/78111196




# 3、git说明
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
