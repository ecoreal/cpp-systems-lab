# Data_structure_experiment

本目录收录数据结构课程实验和小型综合练习，重点是把基础数据结构、文件输入输出和交互流程组合起来。

## 内容范围

| 文件 | 说明 |
| --- | --- |
| `books.cpp` | 图书信息管理练习，包含读取、插入、查询、删除和排序输出。 |
| `books.txt` | `books.cpp` 的初始数据文件。 |
| `ordered.txt` | `books.cpp` 生成的排序输出示例。 |
| `experiment0.*.cpp` | 实验 0 系列练习。 |
| `experiment1.*.cpp` | 实验 1 系列练习。 |
| `experiment2.*.cpp` | 实验 2 系列练习。 |
| `get_bacteria.cpp`、`gets.cpp`、`test_;.cpp` | 辅助验证或临时练习代码。 |
| `in.txt` | 部分实验使用的输入样例。 |

## 运行示例

```bash
cd Data_structure_experiment
g++ -std=c++17 books.cpp -o /tmp/books-demo
/tmp/books-demo
```

`books.cpp` 的交互命令：

| 命令 | 行为 |
| --- | --- |
| `1` | 插入一本书。 |
| `2` | 按标题关键词查询。 |
| `3` | 按标题关键词删除。 |
| `0` | 保存并退出。 |

## 阅读建议

- 先确认实验需要的输入文件。
- 将结构体、全局数据、核心函数和 `main()` 流程分开阅读。
- 对每个实验补充“目标、输入、输出、核心思路、易错点”会显著提升复盘价值。
