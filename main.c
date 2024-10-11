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

void player_move(char board[HEIGHT][WIDTH], int *player_x, int *player_y, int *caillou_x, int *caillou_y) {
    char input;

    printf("Choisissez un mouvement : Haut(z) Bas(s) Gauche(q) Droite(d) \n");
    input = getchar();
    getchar(); 

    int new_x = *player_x;
    int new_y = *player_y;

    switch (input) {
        case 'z': 
            new_y--;
            break;
        case 's': 
            new_y++;
            break;
        case 'q':
            new_x--;
            break;
        case 'd': 
            new_x++;
            break;
    }

    if (new_x == *caillou_x && new_y == *caillou_y) {
        int new_caillou_x = *caillou_x + (new_x - *player_x);
        int new_caillou_y = *caillou_y + (new_y - *player_y);

        if (board[new_caillou_y][new_caillou_x] == ' ') {
            board[*caillou_y][*caillou_x] = ' ';
            *caillou_x = new_caillou_x;
            *caillou_y = new_caillou_y;
            board[*caillou_y][*caillou_x] = 'O';
        } else {
            return;
        }
    }

    if (board[new_y][new_x] == ' ') {
        board[*player_y][*player_x] = ' ';
        *player_x = new_x;
        *player_y = new_y;
        board[*player_y][*player_x] = '@';
    }
}

int check_victory(int caillou_x, int caillou_y, int trou_x, int trou_y) {
    return (caillou_x == trou_x && caillou_y == trou_y);
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
        player_move(board, &player_x, &player_y, &caillou_x, &caillou_y);
        
        if (check_victory(caillou_x, caillou_y, trou_x, trou_y)) {
            print_board(board);
            printf("Vous avez gagné !\n");
            break;
        }
    }

    return 0;
}

