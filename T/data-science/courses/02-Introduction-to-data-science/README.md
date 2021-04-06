## 数据科学入门

### 1.数据科学的定义

伯克利加州大学Joseph Gonzalez的定义是“The application of data-centric computational, and inferential thinking to understand the world and solve problems.” 数据科学家也是不同于数据工程师、统计员和商业分析师。

数据科学家不同于数据工程师的地方在于数据工程师会优化数据流，但数据科学家优化数据的处理，和数据工程师/商业分析师定义各种指标，创建数据收集方法并且和企业系统打交道。

数据科学家不同于统计员的地方在于数据工程师处理海量数据，会涉及到自动化的数据收集、清理的工作，甚至需要创建机器学习模型。而统计员则是做一些调查、投票、实验等传统的数据整理工作，并且涉及到优化现有简单统计模型以便于更好的整理数据。

数据科学家不同于商业分析师的地方在于商业分析师侧重在数据库设计和ROI评估，有的会涉及到财务规划、优化和风险管理。数据科学家可以帮助商业分析师加快数据提取和自动化产品报告。

当前世界产生的数据越来越多，所以需要更好的手段来利用这些数据进行预测。当前数据科学已经在下面几个方面有较大的影响：

- 客户服务
- 导航
- 推荐
- 语音文本转换
- 图像处理
- 谎言检测
- 机器人

### 2.数据科学的生命周期

数据科学家按照特定的流程去认识世界，它被称为“生命周期”，大致分为：提出问题、获取和清理数据、数据分析、用预测或推论得出结论。

### 3.数据设计

数据设计是收集数据的过程。概率抽样用来在收集数据时减少误差，包括简单随机抽样、群体抽样和分层抽样。

### 4.计算工具

Python和R语言是数据科学中常用的两种变成语言，它们的应用场合有如下区别：

- Python偏向于联合web应用的数据分析，R语言的数据分析常在单独的服务器上进行。
- Python偏向于效率和代码可读性，R偏向于数据分析和统计本身，以及图形建模。
- Python通常被程序员用来进行数据分析或统计，R多用于学术和研究中。
- Python语法简单，容易学习。R的学习曲线比较陡。

### 5.表格数据

数据可以通过多种方式组织起来，但大多数数据科学家都倾向于使用表格数据，因为它们便于操作。一种通用的用来存储表格数据的格式是“Comma-Separated Values(CSV)”，其中每项记录对应一行，每项记录里面的字段由逗号进行分割。CSV格式的数据可以使用pandas里面的`read_csv`方法来将它们读取到内存中。

pandas是Python里面专门用来处理数据的函数库，用pandas读取的数据存储在`DataFrame`类型的变量中，这种类型即是表格数据类型，行用`index`来标记，列用`column`来标记。比如如果我们要找到某表格数据里面第A列值为2014，同时第B列值最大的前5行记录：

```
us_2014 = us_df.loc[us_df['A'] == 2014, :]
us_2014_sorted = us_2014.sort_values('B', ascending = False)
us_2014_sorted.iloc[0:5]
```

### 6. 探索性数据分析（Exploratory Data Analysis, EDA）

在开始探索性数据分析之前需要知道要分析的数据类型，通常有三种类型的数据：Nominal data（名义数据）、Ordinal data（序数数据）、Numerical data（数值数据）：

- Nominal data
  - political party
  - computer operating system
  - gender
  - languages spoken
- Ordinal data
  - clothing size
  - level of education
  - yelp rating
- Numerical data
  - Height
  - Weight
  - Price
  - Distance
  - Blood pressure

### 7.数据清洗

数据清洗是检查并纠正数据集里面损坏或者不正确的记录，它可能比较耗时但很重要。其包括的项目可能包括丢失的值、格式、结构、复杂的值、单位转换、量度的解释。

在进行数据清洗之前需要了解数据集里面是否有丢失的值，这些丢失的值是否被填写过了，哪些数据是人输入的。检查丢失的值可以通过`df.isnull()`来查看整体情况，再用`df.isnull().any(axis = 1)`查看哪些行存在缺失数据，之后用`df[missing_rows]`可以查看有缺失数据所在行的所有数据。

### 8.数据可视化

Python里面进行数据可视化常用的函数库有matplotlib, seaborn。在展示定性数据的时候通常使用条形图，展示定量数据常用直方图、离散图。

### 9.推理

统计推理是使用数据分析得到潜在的概率分布，比如选举预测和测试分数预测。可能运用到的统计方法包括假设检验和置信区间。

数据收集往往不是很可靠，所以要先使用假设检验来判断数据是随机扰动还是反映了真实现象。之后进行替代假设分析、排列检验、引导置信区间。

### 10.分类

分类是一种重要的机器学习技术，它是针对分类好的数据来进行预测，用途包括天气预测、垃圾邮件过滤、病人患病预测、选举预测、歌曲/电影/真人秀类型预测、二人配对。

K近邻算法（K-NN）是一种常用的分类方法。