#include <iostream>
#include <vector>

const int ROWS = 6;
const int COLUMNS = 7;
const char EMPTY = ' ';
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

class Power4 {
private:
    std::vector<std::vector<char> > board;
    char currentPlayer;

public:
    Power4() {
        board = std::vector<std::vector<char> >(ROWS, std::vector<char>(COLUMNS, EMPTY));
        currentPlayer = PLAYER1;
    }

    void printBoard() {
        std::cout << " 1 2 3 4 5 6 7" << std::endl;
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLUMNS; ++j) {
                std::cout << "|";
                std::cout << board[i][j];
            }
            std::cout << "|" << std::endl;
        }
    }

    bool isColumnFull(int col) {
        return board[0][col] != EMPTY;
    }

    void dropDisc(int col) {
        for (int i = ROWS - 1; i >= 0; --i) {
            if (board[i][col] == EMPTY) {
                board[i][col] = currentPlayer;
                break;
            }
        }
    }

    bool checkWin() {
        // Check for a horizontal win.
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j <= COLUMNS - 4; ++j) {
                if (board[i][j] == currentPlayer &&
                    board[i][j + 1] == currentPlayer &&
                    board[i][j + 2] == currentPlayer &&
                    board[i][j + 3] == currentPlayer) {
                    return true;
                }
            }
        }

        // Check for a vertical win.
        for (int i = 0; i <= ROWS - 4; ++i) {
            for (int j = 0; j < COLUMNS; ++j) {
                if (board[i][j] == currentPlayer &&
                    board[i + 1][j] == currentPlayer &&
                    board[i + 2][j] == currentPlayer &&
                    board[i + 3][j] == currentPlayer) {
                    return true;
                }
            }
        }

        // Check for a diagonal win (left-top to right-bottom).
        for (int i = 0; i <= ROWS - 4; ++i) {
            for (int j = 0; j <= COLUMNS - 4; ++j) {
                if (board[i][j] == currentPlayer &&
                    board[i + 1][j + 1] == currentPlayer &&
                    board[i + 2][j + 2] == currentPlayer &&
                    board[i + 3][j + 3] == currentPlayer) {
                    return true;
                }
            }
        }

        // Check for a diagonal win (right-top to left-bottom).
        for (int i = 0; i <= ROWS - 4; ++i) {
            for (int j = 3; j < COLUMNS; ++j) {
                if (board[i][j] == currentPlayer &&
                    board[i + 1][j - 1] == currentPlayer &&
                    board[i + 2][j - 2] == currentPlayer &&
                    board[i + 3][j - 3] == currentPlayer) {
                    return true;
                }
            }
        }

        return false;
    }

    bool isBoardFull() {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLUMNS; ++j) {
                if (board[i][j] == EMPTY) {
                    return false;
                }
            }
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1;
    }

    char getCurrentPlayer() {
        return currentPlayer;
    }
};

int main() {
    Power4 game;

    std::cout << "Welcome to Power4 Game!" << std::endl;
    std::cout << "Player 1: X, Player 2: O" << std::endl;

    int column;
    bool win = false;
    bool draw = false;

    while (!win && !draw) {
        game.printBoard();
        std::cout << "Player " << game.getCurrentPlayer() << ", enter column (1-7): ";
        std::cin >> column;
        column--; // Convert to 0-based index.

        if (column < 0 || column >= COLUMNS || game.isColumnFull(column)) {
            std::cout << "Invalid move. Try again!" << std::endl;
            continue;
        }

        game.dropDisc(column);
        win = game.checkWin();

        if (!win) {
            draw = game.isBoardFull();
            if (!draw) {
                game.switchPlayer();
            }
        }
    }

    game.printBoard();

    if (win) {
        std::cout << "Congratulations! Player " << game.getCurrentPlayer() << " wins!" << std::endl;
    } else {
        std::cout << "It's a draw!" << std::endl;
    }

    return 0;
}

