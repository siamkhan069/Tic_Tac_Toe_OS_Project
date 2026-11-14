# TIC TAC TOE – Operating Systems Project

A simple two-player console Tic Tac Toe game written in C++.

## Features
- Two-player mode (X and O)
- Win and draw detection
- Input validation
- Scoreboard
- Saves scores in `scores.txt` using file handling
- Runs from Git Bash with g++

## Requirements
- Windows with Git Bash
- A C++ compiler (`g++`) available in PATH

## Compile
```bash
g++ main.cpp -o tic_tac_toe
```

## Run
```bash
./tic_tac_toe
```

If `g++` is not found, install a MinGW-w64/MSYS2 C++ compiler and add its `bin` folder to PATH.

## Files
- `main.cpp` – complete game source code
- `scores.txt` – created automatically after a game; stores X wins, O wins, and draws

## OS concepts demonstrated
- File handling: persistent scoreboard stored on the file system
- Console input/output
- Program execution from a command-line shell
- Input validation and control flow
