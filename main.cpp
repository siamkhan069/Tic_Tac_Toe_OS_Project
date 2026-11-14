#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

char board[9];
int xWins = 0, oWins = 0, draws = 0;

void loadScores() {
    ifstream file("scores.txt");
    if (file) file >> xWins >> oWins >> draws;
}

void saveScores() {
    ofstream file("scores.txt");
    if (file) file << xWins << " " << oWins << " " << draws;
}

void resetBoard() {
    for (int i = 0; i < 9; i++) board[i] = char('1' + i);
}

void showBoard() {
    cout << "\n       TIC TAC TOE\n\n";
    for (int i = 0; i < 9; i++) {
        cout << "  " << board[i] << "  ";
        if (i % 3 != 2) cout << "|";
        if (i % 3 == 2 && i != 8) cout << "\n-----+-----+-----\n";
    }
    cout << "\n\n";
}

bool checkWin(char mark) {
    const int lines[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},
        {0,3,6}, {1,4,7}, {2,5,8},
        {0,4,8}, {2,4,6}
    };
    for (int i = 0; i < 8; i++) {
        if (board[lines[i][0]] == mark &&
            board[lines[i][1]] == mark &&
            board[lines[i][2]] == mark) return true;
    }
    return false;
}

// A player can still win if some line has no opponent mark in it
bool canStillWin(char player) {
    const int lines[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},
        {0,3,6}, {1,4,7}, {2,5,8},
        {0,4,8}, {2,4,6}
    };
    char opponent = (player == 'X') ? 'O' : 'X';
    for (int i = 0; i < 8; i++) {
        if (board[lines[i][0]] != opponent &&
            board[lines[i][1]] != opponent &&
            board[lines[i][2]] != opponent) return true;
    }
    return false;
}

// Smart draw: nobody can win anymore (even before the board is full)
bool isDraw() {
    return !canStillWin('X') && !canStillWin('O');
}

void playGame() {
    resetBoard();
    char player = 'X';
    int position;

    while (true) {
        showBoard();
        cout << "Player " << player << ", choose (1-9): ";

        if (!(cin >> position)) {
            cout << "Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (position < 1 || position > 9) {
            cout << "Choose a position from 1 to 9.\n";
            continue;
        }

        if (board[position - 1] == 'X' || board[position - 1] == 'O') {
            cout << "Position already taken. Try again.\n";
            continue;
        }

        board[position - 1] = player;

        if (checkWin(player)) {
            showBoard();
            cout << "Player " << player << " wins!\n";
            if (player == 'X') xWins++;
            else oWins++;
            break;
        }

        if (isDraw()) {
            showBoard();
            cout << "Match Draw! No player can win anymore.\n";
            draws++;
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }
    saveScores();
}

void showScores() {
    cout << "\n--- SCOREBOARD ---\n";
    cout << "X Wins: " << xWins << "\n";
    cout << "O Wins: " << oWins << "\n";
    cout << "Draws : " << draws << "\n";
}

int main() {
    loadScores();
    int choice;

    while (true) {
        cout << "\n===== TIC TAC TOE =====\n";
        cout << "1. Start Game\n";
        cout << "2. View Scoreboard\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Enter 1, 2, or 3.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                playGame();
                break;
            case 2:
                showScores();
                break;
            case 3:
                saveScores();
                cout << "Thanks for playing!\n";
                return 0;
            default:
                cout << "Invalid choice. Select 1, 2, or 3.\n";
        }
    }
}
