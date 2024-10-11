#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

void init_board(char board[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (y == 0 || y == HEIGHT - 1 || x == 0 || x == WIDTH - 1) {
                board[y][x] = '#'; 
            } else {
                board[y][x] = ' '; 
            }
        }
    }
}

void print_board(char board[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", board[y][x]);
        }
        printf("\n");
    }
}


void player_move(char board[HEIGHT][WIDTH], int *x, int *y) {
    char input;

    printf("Choisissez un mouvement : Haut(z) Bas(s) Gauche(q) Droite(d) \n");
    input = getchar();
    getchar(); 

    board[*y][*x] = ' ';

    switch (input) {
        case 'z': 
            if (*y > 1) (*y)--;
            break;
        case 's': 
            if (*y < HEIGHT - 2) (*y)++;
            break;
        case 'q':
            if (*x > 1) (*x)--;
            break;
        case 'd': 
            if (*x < WIDTH - 2) (*x)++;
            break;
    }

    board[*y][*x] = '@';
}

void caillou(char board[HEIGHT][WIDTH], int *x, int *y) {
    char input;
    board[*y][*x] = 'O';
}

void trou(char board[HEIGHT][WIDTH], int *x, int *y) {
    char input;
    board[*y][*x] = '.';
}


int main() {
    char board[HEIGHT][WIDTH];
    int player_x = 5, player_y = 5;
    int trou_x = 8, trou_y = 2;
    int caillou_x = 2, caillou_y = 7;

    init_board(board);
    board[player_y][player_x] = '@'; 
    board[trou_y][trou_x] = '.';
    board[caillou_y][caillou_x] = 'O';
    
    while (1) {
        print_board(board); 
        player_move(board, &player_x, &player_y);
        trou(board, &trou_x, &trou_y);
        caillou(board, &caillou_x, &caillou_y);
    }

    return 0;
}


