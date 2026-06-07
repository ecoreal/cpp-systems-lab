# Learning Path

这份学习路线用于帮助读者按主题阅读 Dev_cpp，而不是机械地按文件名顺序浏览。

## 1. C++ 基础语法与输入输出

建议从 `Data_structure_normal/` 中较短的文件开始，重点观察：

- 标准输入输出。
- 数组、指针、结构体和类。
- 函数拆分与基础控制流。
- 文件输入输出。

可以优先阅读：

- `Data_structure_normal/fileDemo.cpp`
- `Data_structure_normal/get.cpp`
- `Data_structure_normal/test.cpp`

## 2. 线性结构

线性表、栈和队列是后续树、图和算法题的基础。阅读时重点关注：

- 顺序存储与链式存储的差异。
- 插入、删除、查找的边界条件。
- 内存管理和指针更新顺序。
- 输入输出格式如何影响程序结构。

对应内容主要位于：

- `Data_structure_normal/DS3.*.cpp`
- `Data_structure_normal/DS4.*.cpp`
- `Data_structure_normal/DS5.*.cpp`

## 3. 树、图、查找和排序

进入这一阶段后，建议在阅读代码前先画出数据结构变化过程：

- 树的构建、遍历和递归边界。
- 图的存储结构、遍历和路径问题。
- 查找结构的性能差异。
- 排序算法的稳定性、时间复杂度和空间复杂度。

对应内容主要位于：

- `Data_structure_normal/DS6.*.cpp`
- `Data_structure_normal/DS7.*.cpp`
- `Data_structure_normal/DS8.*.cpp`
- `Data_structure_normal/DS9.*.cpp`
- `Data_structure_normal/DS10.*.cpp`
- `Data_structure_normal/DS11.*.cpp`
- `Data_structure_normal/DS12.*.cpp`
- `Data_structure_normal/DS13.*.cpp`
- `Data_structure_normal/DS14.*.cpp`

## 4. 综合实验

`Data_structure_experiment/` 更适合用来复盘“如何把知识点连起来”：

- 如何设计菜单或交互流程。
- 如何组织结构体、类和辅助函数。
- 如何从文件读入数据并输出结果。
- 如何在已有代码基础上持续修改。

推荐阅读：

- `Data_structure_experiment/books.cpp`
- `Data_structure_experiment/experiment0.*.cpp`
- `Data_structure_experiment/experiment1.*.cpp`
- `Data_structure_experiment/experiment2.*.cpp`

## 5. CSAPP 与计算机系统基础

`CSAPP/` 目录更偏向底层表示和系统理解。阅读时建议结合教材章节和调试器：

- 整数的位级表示与移位。
- 浮点数编码和精度问题。
- 汇编层面的函数调用和数据布局。
- 链接、符号和目标文件概念。

推荐先读：

- `CSAPP/CSAPP3e.2.*.cpp`
- `CSAPP/CSAPP_float_half.cpp`
- `CSAPP/CSAPP3e.3.*.cpp`
- `CSAPP/CSAPP3e.7.*.cpp`

## 复盘模板

为每个练习补充笔记时，可以使用这个结构：

```markdown
## 题目目标

## 输入输出

## 核心思路

## 易错点

## 复杂度

## 可改进方向
```

这个仓库后续会逐步按该模板补充更多学习笔记。
