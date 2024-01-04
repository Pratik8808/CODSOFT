#include <iostream>

using namespace std;

char gameGrid[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
char activePlayer = 'X';

void renderGameboard() {
    system("cls");  // Clear the screen (Windows-specific)
    cout << "Tic-Tac-Toe\n\n";

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            cout << gameGrid[row][col] << " ";
            if (col < 2) {
                cout << "| ";  // Add spaces for better readability
            }
        }
        cout << endl;
        if (row < 2) {
            cout << "-----------" << endl;
        }
    }
}

bool checkForVictory() {
    for (int i = 0; i < 3; i++) {
        if (gameGrid[i][0] == gameGrid[i][1] && gameGrid[i][1] == gameGrid[i][2] && gameGrid[i][0] != ' ') {
            return true;
        }
        if (gameGrid[0][i] == gameGrid[1][i] && gameGrid[1][i] == gameGrid[2][i] && gameGrid[0][i] != ' ') {
            return true;
        }
    }
    if (gameGrid[0][0] == gameGrid[1][1] && gameGrid[1][1] == gameGrid[2][2] && gameGrid[0][0] != ' ') {
        return true;
    }
    if (gameGrid[0][2] == gameGrid[1][1] && gameGrid[1][1] == gameGrid[2][0] && gameGrid[0][2] != ' ') {
        return true;
    }
    return false;
}

bool checkForStalemate() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (gameGrid[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer() {
    activePlayer = (activePlayer == 'X') ? 'O' : 'X';
}

void resetGame() {
    // Reset the game board and active player
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            gameGrid[i][j] = ' ';
        }
    }
    activePlayer = 'X';
}

int main() {
    bool gameOver = false;

    while (!gameOver) {
        renderGameboard();

        int row, col;
        cout << activePlayer << "'s turn. Enter row and column (1-3): ";
        cin >> row >> col;

        row--;  // Adjust for 0-based indexing
        col--;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && gameGrid[row][col] == ' ') {
            gameGrid[row][col] = activePlayer;

            if (checkForVictory()) {
                renderGameboard();
                cout << activePlayer << " wins!\n";
                gameOver = true;
            } else if (checkForStalemate()) {
                cout << "It's a draw!\n";
                gameOver = true;
            } else {
                switchPlayer();
            }
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }

    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        resetGame();  // Reset the game state
    }

    return 0;
}
