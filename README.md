# XO Arena – Tic Tac Toe (C++ OS Project)

A small two-player, terminal-based Tic Tac Toe application built with C++.

## Features
- Two-player X/O gameplay on a 3×3 board
- Win detection and smart draw detection (a draw is declared as soon as no player can win)
- Input validation with recovery from invalid input
- Menu using `switch-case`
- `while` and `for` loops, `if-else`, `break`, and `continue`
- Persistent scoreboard using file handling (`scores.txt`)

## Requirements
- Git Bash / Unix-like terminal
- g++ compiler

## Compile and Run (Git Bash)
```bash
g++ main.cpp -o tic_tac_toe
./tic_tac_toe
```

## Unix Commands to Demonstrate
Run these in Git Bash from the project directory:
```bash
pwd                          # show current directory
ls                           # list project files
ls -l                        # list files with size and permissions
cat main.cpp                 # view the source code
g++ main.cpp -o tic_tac_toe  # compile
chmod +x tic_tac_toe         # make the program executable
./tic_tac_toe                # run the application
cat scores.txt               # view saved scores (after a game)
rm scores.txt                # reset the scoreboard
git add . && git commit -m "message" && git push   # upload to GitHub
```

## Project Files
- `main.cpp` – application source code
- `scores.txt` – created automatically to store X wins, O wins, and draws

## Concepts Demonstrated
- Conditional statements: `if`, `else`
- Selection: `switch`, `case`, `default`
- Loops: `while`, `for`
- Loop control: `break`, `continue`
- File handling: `ifstream`, `ofstream`
- Command-line compilation and execution using Git Bash

## Author
Siam Khan  
GitHub: https://github.com/siamkhan069
