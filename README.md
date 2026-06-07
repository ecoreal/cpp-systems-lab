# Dev_cpp

[English](README.en.md)

Dev_cpp 是一个用于记录和分享 C/C++ 学习过程的开源仓库。这里保留了从基础语法、数据结构练习到 CSAPP 相关实验代码的阶段性产出，目标不是提供一个完整框架，而是把真实学习路径、练习代码和复盘方法整理成可阅读、可运行、可持续补充的资料库。

## 项目定位

- 记录 C/C++ 学习过程中的代码练习、实验题和阶段性总结。
- 分享数据结构、算法基础、计算机系统基础等主题的实践片段。
- 保留原始练习痕迹，便于观察代码能力、工程习惯和问题理解方式的变化。
- 为后来学习者提供目录导航、运行方法和可改进方向。

## 当前内容

| 目录 | 内容 | 说明 |
| --- | --- | --- |
| `CSAPP/` | CSAPP 相关章节练习代码 | 覆盖位级运算、浮点表示、汇编/链接等基础主题。 |
| `Data_structure_normal/` | 数据结构日常练习 | 包含线性表、栈、队列、树、图、查找、排序等练习代码。 |
| `Data_structure_experiment/` | 数据结构实验代码 | 包含课程实验、输入输出样例和小型综合题。 |
| `docs/` | 项目说明文档 | 包含运行指南、学习路线和维护说明。 |

> 说明：仓库中的部分文件来自课程学习和个人练习场景，代码风格会保留一定阶段性差异。整理工作的重点是增强可读性和可维护性，而不是抹平学习过程中的所有痕迹。

## 快速开始

本仓库不依赖构建系统，单个 `.cpp` 文件通常可直接编译运行。

```bash
git clone git@github.com:ecoreal/Dev_cpp.git
cd Dev_cpp
g++ -std=c++17 CSAPP/CSAPP3e.2.59.cpp -o /tmp/csapp-2-59
/tmp/csapp-2-59
```

部分数据结构练习会读取当前工作目录下的 `in.txt`、`books.txt`，或输出到 `out.txt`、`ordered.txt`。运行这类文件时建议先进入对应目录：

```bash
cd Data_structure_experiment
g++ -std=c++17 books.cpp -o /tmp/books-demo
/tmp/books-demo
```

更多说明见 [docs/RUNNING.md](docs/RUNNING.md)。

## 推荐阅读路径

1. 先阅读 [docs/LEARNING_PATH.md](docs/LEARNING_PATH.md)，了解仓库内容的学习顺序。
2. 从 `Data_structure_normal/` 中较短的基础练习开始，熟悉 C++ 基本输入输出和数据结构实现。
3. 再阅读 `Data_structure_experiment/`，关注如何把多个知识点组合成可交互程序。
4. 最后阅读 `CSAPP/`，理解整数表示、浮点数、汇编和链接相关练习。

## 维护计划

- 为每个练习文件补充题目背景、输入输出说明和关键思路。
- 将可复用的数据结构实现拆分为更清晰的小模块。
- 增加可自动运行的编译检查脚本。
- 逐步补充学习笔记和踩坑记录。
- 保持原始练习代码可追溯，重大重构会在文档中说明。

## 贡献方式

欢迎提交 issue 或 pull request，适合贡献的内容包括：

- 修复明显的编译错误或未定义行为。
- 为已有练习补充注释、输入样例和复杂度分析。
- 改进 README、学习路线、目录索引等文档。
- 补充同主题的更清晰实现，并说明与原实现的差异。

提交前请阅读 [CONTRIBUTING.md](CONTRIBUTING.md) 和 [CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md)。

## 资料与版权说明

本仓库用于个人学习记录和经验分享。仓库内原创代码与文档采用 MIT License 开源；教材题目、课程材料、第三方资料、引用概念和外部链接仍归原作者或原版权方所有。请勿将本仓库内容直接作为课程作业提交。

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.
