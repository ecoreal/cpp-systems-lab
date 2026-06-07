# Maintenance Notes

本文件记录 Dev_cpp 的整理原则，避免后续维护时把学习型仓库改得失去上下文。

## 整理原则

- 保留原始学习轨迹，优先通过文档解释，而不是直接删除历史代码。
- 对明显错误可以修复，但需要在提交说明中写清楚影响范围。
- 对同一题目的更优实现，可以新增文件或补充说明，不必强行覆盖原实现。
- 对第三方题目、教材内容和课程要求只做引用说明，不复制大段原文。
- 保持仓库可以被普通 C++ 初学者直接 clone、阅读和运行。

## 文件命名

现有文件名保留课程练习编号，例如 `DS3.1.cpp`、`CSAPP3e.2.59.cpp`。后续新增文件建议使用更清晰的命名：

```text
topic_problem_variant.cpp
```

示例：

```text
linked_list_insert_review.cpp
binary_tree_traversal_note.cpp
```

## 文档优先级

维护时优先补齐：

1. 根目录 README。
2. 各目录 README。
3. 单个练习的输入输出说明。
4. 编译和运行命令。
5. 易错点与复杂度。

## 质量检查

在提交前建议至少执行：

```bash
git status --short
find . -maxdepth 3 -name '*.md' -print
```

如果修改了 C++ 代码，至少编译相关文件：

```bash
g++ -std=c++17 path/to/file.cpp -o /tmp/dev-cpp-check
```

## 未来可改进项

- 引入轻量脚本批量编译可独立运行的文件。
- 为需要输入文件的练习标注运行目录。
- 为核心数据结构补充图示或伪代码。
- 将大型综合实验拆出更清晰的模块说明。
