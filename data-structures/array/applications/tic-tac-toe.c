#include <stdio.h>

char board[3][3][4];

void displayBoard();
int* playTurn(int);
int isBoardFull();

int compStr(const char* str1, const char* str2) {
    while (*str1 != '\0' && (*str1 == *str2)) {
        str1++;
        str2++;
    }

    return (unsigned char)*str1 - (unsigned char)*str2;
}

char* copyStr(char* to, char* from) {
    char* start = to;
    while (*from != '\0') {
        *to = *from;
        to++;
        from++;
    }

    *to = '\0';

    return start;  // the pointer of the start of the string.
}

void initBoard() {
    printf("Starting game..\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            copyStr(board[i][j], "[ ]");
        }
    }

    displayBoard();
}

void displayBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%s", board[i][j]);
        }
        printf("\n");
    }
}

int* playTurn(int player) {
    printf("Choose a position in format (row col): ");
    int row, col;
    if (scanf("%d %d", &row, &col) != 2) {
        printf("Invalid input format!\n");
        while (getchar() != '\n');  // clear input buffer
        return playTurn(player);
    }

    if (row < 1 || row > 3 || col < 1 || col > 3) {
        printf("Invalid input! Rows and columns must be between 1 and 3.\n");
        return playTurn(player);
    }

    if (compStr(board[row - 1][col - 1], "[ ]") != 0) {
        printf("Cell already taken! Choose another.\n");
        return playTurn(player);
    }

    copyStr(board[row - 1][col - 1], player == 1 ? "[X]" : "[O]");

    static int positions[2];
    positions[0] = row;
    positions[1] = col;
    return positions;
}

int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (compStr(board[i][j], "[ ]") == 0) {
                return 0;
            }
        }
    }

    return 1;
}

char rowMatch() {
    for (int i = 0; i < 3; i++) {
        if (compStr(board[i][0], "[ ]") != 0 &&
            compStr(board[i][0], board[i][1]) == 0 &&
            compStr(board[i][1], board[i][2]) == 0) {
            return board[i][0][1];  // Returns the X or 0 character
        }
    }

    return '\0';
}

char colMatch() {
    for (int i = 0; i < 3; i++) {
        if (compStr(board[0][i], "[ ]") != 0 &&
            compStr(board[0][i], board[1][i]) == 0 &&
            compStr(board[1][i], board[2][i]) == 0) {
            return board[0][i][1];
        }
    }

    return '\0';
}

char diagMatch() {
    // main diagonal
    if (compStr(board[0][0], "[ ]") != 0 &&
        compStr(board[0][0], board[1][1]) == 0 &&
        compStr(board[1][1], board[2][2]) == 0) {
        return board[0][0][1];
    }

    // anti-diagonal
    if (compStr(board[0][2], "[ ]") != 0 &&
        compStr(board[0][2], board[1][1]) == 0 &&
        compStr(board[1][1], board[2][0]) == 0) {
        return board[0][2][1];
    }

    return '\0';
}

char checkWin() {
    char winner;

    if ((winner = rowMatch()) != '\0') return winner;
    if ((winner = colMatch()) != '\0') return winner;
    if ((winner = diagMatch()) != '\0') return winner;

    return '\0';  // No winner
}

int main() {
    initBoard();
    int cur_player = 0;
    char winner;
    while (!isBoardFull()) {
        cur_player = cur_player == 1 ? 2 : 1;
        char player_sym = cur_player == 1 ? 'X' : 'O';
        printf("Player %c turn: ", player_sym);

        int* pos = playTurn(cur_player);
        printf("Player %c chooses (%d,%d)\n", player_sym, pos[0], pos[1]);

        if ((winner = checkWin())) {
            printf("Game Over. Winner is: %c\n", winner);
            displayBoard();
            break;  // Exit the loop on win
        }
        displayBoard();
    }

    // Board is full with no winner.
    if (winner == '\0') {
        printf("Game over, result is draw.\n");
    }
    // int arr[3] = {1, 2, 3};

    // printf("%p %p %p\n", arr, &arr[1], &arr[2]);
    // printf("%p %p %p\n", arr, arr + 1, arr + 2);
    // printf("%d %d %d\n", *arr, arr[1], arr[2]);
    // printf("%d %d %d\n", *arr, *(arr + 1), *(arr + 2));

    return 0;
}