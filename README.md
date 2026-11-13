# Rainfall

Rainfall is a binary-exploitation training project from the 42 curriculum. It
contains a sequence of small vulnerable programs designed to be analyzed with
debuggers and binary-analysis tools. Each level introduces a different
programming or memory-safety mistake and provides a walkthrough of the
intended investigation.

## Project goals

The goals of this project are to:

- Develop a practical understanding of how C and C++ programs use memory.
- Learn to inspect binaries with tools such as `gdb`, `objdump`, and
  `readelf`.
- Recognize common vulnerabilities and understand their root causes.
- Practice tracing stack and heap layouts, calling conventions, and control
  flow.
- Learn how unsafe input handling can affect return addresses, function
  pointers, global data, and virtual tables.
- Build reliable, reproducible exploits in a controlled laboratory
  environment.
- Improve defensive programming by connecting each exploit to safer coding
  practices.

## Levels

The mandatory levels build on one another:

| Levels | Main concepts |
| --- | --- |
| `level0` | Integer parsing and conditional command execution |
| `level1` | Stack buffer overflow and redirecting execution |
| `level2` | Return-address checks and return-oriented control flow |
| `level3` | Format-string reads and `%n` writes |
| `level4` | Format-string writes to controlled global data |
| `level5` | Format-string overwrite of a GOT entry |
| `level6` | Heap overflow and function-pointer corruption |
| `level7` | Heap layout manipulation and GOT redirection |
| `level8` | Heap misuse, overflow, and stale/adjacent data |
| `level9` | C++ object layout, virtual dispatch, and vtable corruption |

The bonus levels extend the same themes with additional stack, integer,
environment, ret2libc, and input-validation challenges.

## Repository layout

Each level normally contains:

```text
levelN/
├── source       # Reconstructed or explanatory source
├── walkthrough  # Analysis and solution notes
└── flag         # Captured result for the exercise
```

`en.subject.pdf` contains the original project subject. The `bonus0` through
`bonus3` directories contain the optional challenges.

## Working on a level

Read the relevant `source` and `walkthrough` files first, then reproduce the
analysis in an isolated 32-bit Linux environment. Useful tools include:

- `gdb` for inspecting memory, registers, stack frames, and symbols
- `objdump` and `readelf` for disassembly and ELF metadata
- `strings` for locating useful embedded data
- Python or shell scripts for constructing test input

The exact addresses and offsets may vary with the compiler, operating system,
libraries, and security mitigations. Treat the walkthroughs as a guide to the
underlying technique, not as universally portable commands.

## Safety and ethics

These exercises are intended for authorized local practice only. Do not apply
the techniques demonstrated here to systems, binaries, or data without
permission. In production software, replace unsafe operations such as
unbounded string copying, `gets`, and uncontrolled format strings with
bounded input handling, constant format strings, and appropriate compiler and
runtime protections.
