# Dev_cpp

[简体中文](README.md)

Dev_cpp is an open-source repository for recording and sharing a C/C++ learning journey. It keeps practice code from basic syntax, data structure exercises, and CSAPP-related experiments. The goal is not to provide a polished framework, but to make the learning path, practice code, and review notes easier to read, run, and improve over time.

## Project Purpose

- Record C/C++ exercises, experiments, and learning notes.
- Share practical examples for data structures, algorithms, and computer systems fundamentals.
- Preserve the original learning history so progress and tradeoffs remain visible.
- Provide navigation, run instructions, and improvement directions for future readers.

## Contents

| Directory | Content | Notes |
| --- | --- | --- |
| `CSAPP/` | CSAPP-related exercise code | Bit-level operations, floating point representation, assembly, linking, and related topics. |
| `Data_structure_normal/` | Regular data structure practice | Linear lists, stacks, queues, trees, graphs, search, sorting, and similar exercises. |
| `Data_structure_experiment/` | Data structure experiments | Course experiments, sample input/output files, and small integrated programs. |
| `docs/` | Project documentation | Running guide, learning path, and maintenance notes. |

> Note: some files were created for coursework and personal practice. The repository intentionally keeps parts of that learning history. The cleanup focuses on readability and maintainability without rewriting every original exercise.

## Quick Start

The repository does not require a build system. Most `.cpp` files can be compiled and run individually.

```bash
git clone git@github.com:ecoreal/Dev_cpp.git
cd Dev_cpp
g++ -std=c++17 CSAPP/CSAPP3e.2.59.cpp -o /tmp/csapp-2-59
/tmp/csapp-2-59
```

Some data structure exercises read `in.txt` or `books.txt` from the current working directory, or write `out.txt` and `ordered.txt`. For those files, run them from the corresponding directory:

```bash
cd Data_structure_experiment
g++ -std=c++17 books.cpp -o /tmp/books-demo
/tmp/books-demo
```

See [docs/RUNNING.md](docs/RUNNING.md) for more details.

## Suggested Reading Path

1. Read [docs/LEARNING_PATH.md](docs/LEARNING_PATH.md) to understand the learning order.
2. Start with shorter exercises in `Data_structure_normal/` to review C++ I/O and data structure basics.
3. Move to `Data_structure_experiment/` to see how multiple concepts are combined into interactive programs.
4. Read `CSAPP/` to review integer representation, floating point, assembly, and linking exercises.

## Maintenance Roadmap

- Add problem context, input/output notes, and key ideas to each exercise.
- Split reusable data structure implementations into clearer modules.
- Add a lightweight compile-check script.
- Add more learning notes and review summaries.
- Keep original practice code traceable; major refactors should be explained in documentation.

## Contributing

Issues and pull requests are welcome. Helpful contributions include:

- Fixing clear compilation errors or undefined behavior.
- Adding comments, input examples, and complexity analysis for existing exercises.
- Improving README files, learning paths, and directory indexes.
- Adding clearer implementations for the same topics with explanations.

Please read [CONTRIBUTING.md](CONTRIBUTING.md) and [CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md) before contributing.

## Data and Copyright Notes

This repository is intended for personal learning records and knowledge sharing. Original code and documentation in this repository are released under the MIT License. Textbook problems, course materials, third-party references, cited concepts, and external links remain owned by their original authors or copyright holders. Do not submit this repository directly as coursework.

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.
