# Running Guide

本项目主要由单文件 C++ 练习组成，不需要 CMake、Makefile 或包管理器即可开始运行。

## 环境要求

- Linux、macOS 或 Windows WSL。
- `g++` 或 `clang++`。
- 推荐 C++17 标准。

检查编译器：

```bash
g++ --version
```

## 编译单个文件

在仓库根目录执行：

```bash
g++ -std=c++17 CSAPP/CSAPP3e.2.59.cpp -o /tmp/csapp-2-59
/tmp/csapp-2-59
```

如果文件在运行时读取相对路径下的输入文件，建议进入对应目录后编译运行：

```bash
cd Data_structure_normal
g++ -std=c++17 DS7.1.cpp -o /tmp/ds-7-1
/tmp/ds-7-1
```

## 文件输入输出

一些练习使用如下文件名：

| 文件 | 用途 |
| --- | --- |
| `in.txt` | 常见输入数据。 |
| `out.txt` | 常见输出结果。 |
| `books.txt` | 图书管理练习的初始数据。 |
| `ordered.txt` | 图书管理练习生成的排序结果。 |

运行这类程序时，当前工作目录会影响文件能否被正确读取。通常应进入 `.cpp` 所在目录后运行。

## 批量编译检查

仓库暂时没有强制 CI。可以用下面的命令快速检查大部分文件是否能独立编译：

```bash
find CSAPP Data_structure_normal Data_structure_experiment -name '*.cpp' -print0 |
while IFS= read -r -d '' file; do
  output="/tmp/dev-cpp-$(basename "$file" .cpp)"
  echo "Compiling $file"
  g++ -std=c++17 "$file" -o "$output" || exit 1
done
```

注意：历史练习中可能存在实验环境专用写法、未完成草稿或需要特定输入文件的程序。批量编译结果应作为维护参考，而不是唯一质量标准。

## 常见问题

### 中文路径或特殊文件名

少量文件名包含中文标点。Linux/macOS 通常可以正常处理；如果命令行补全异常，可以使用引号包裹路径。

```bash
g++ -std=c++17 "CSAPP/CSAPP3e。7.10.cpp" -o /tmp/csapp-7-10
```

### 程序没有输出

检查程序是否在等待标准输入，或是否通过 `freopen` 读取 `in.txt`。

### 输出文件没有生成

确认是否从 `.cpp` 所在目录运行程序，以及程序是否有写入当前目录的权限。
