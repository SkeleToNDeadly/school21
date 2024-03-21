#include <stdio.h>

void function_rocket(void);
int game(int rocket_left, int rocket_right, int ball_y, int ball_x, int left_goal, int right_goal);
int function_ball_y(int ball_y, int ball_vect_y);
int function_ball_x(int ball_y, int ball_x, int ball_vect_x, int rocket_left, int rocket_right);
int win_players(int left_goal, int right_goal);
void clearScreen(void);

int main() {
    int rocket_left = 12;
    int rocket_right = 12;
    int ball_vect_y = 1;
    int ball_vect_x = 1;
    int left_goal = 0;
    int right_goal = 0;
    clearScreen();
    while (right_goal != 21 && left_goal != 21) {
        int ball_x = 40;
        int ball_y = 25 / 2;
        while (ball_x >= 1 && ball_x <= 79) {
            game(rocket_left, rocket_right, ball_y, ball_x, left_goal, right_goal);
            switch (getchar()) {
                case 'a':
                    if (rocket_left - 2 != 0) rocket_left--;
                    break;
                case 'z':
                    if (rocket_left + 2 != 25 - 1) rocket_left++;
                    break;
                case 'k':
                    if (rocket_right - 2 != 0) rocket_right--;
                    break;
                case 'm':
                    if (rocket_right + 2 != 25 - 1) rocket_right++;
                    break;
                case ' ':
                    break;
                default:
                    continue;
            }
            ball_vect_y = function_ball_y(ball_y, ball_vect_y);
            ball_y += ball_vect_y;
            ball_vect_x = function_ball_x(ball_y, ball_x, ball_vect_x, rocket_left, rocket_right);
            ball_x += ball_vect_x;
            if (ball_x == 1) {
                right_goal += 1;
            } else if (ball_x == 80) {
                left_goal += 1;
            }
            while (getchar() != '\n')
                ;
            clearScreen();
        }
    }
    win_players(left_goal, right_goal);
    return 0;
}
void clearScreen(void) { printf("\33[H\33[2J"); }
int win_players(int left_goal, int right_goal) {
    if (left_goal < right_goal) {
        printf("WIN LEFT PLAYER");
    } else {
        printf("WIN RIGHT PLAYER");
    }
    return 0;
}
int function_ball_y(int ball_y, int ball_vect_y) {
    if (ball_y == 1 || ball_y == 25 - 2) {
        ball_vect_y = -(ball_vect_y);
    }
    return ball_vect_y;
}
int function_ball_x(int ball_y, int ball_x, int ball_vect_x, int rocket_left, int rocket_right) {
    if (ball_x == 2 &&
        ((ball_y == rocket_left - 1) || (ball_y == rocket_left + 1) || (ball_y == rocket_left))) {
        ball_vect_x = -(ball_vect_x);
    }
    if (ball_x == 80 - 2 &&
        ((ball_y == rocket_right - 1) || (ball_y == rocket_right + 1) || (ball_y == rocket_right))) {
        ball_vect_x = -(ball_vect_x);
    }
    return ball_vect_x;
}
int game(int rocket_left, int rocket_right, int ball_y, int ball_x, int left_goal, int right_goal) {
    for (int i = -1; i < 25; i++) {
        for (int j = 0; j < 80 + 1; j++) {
            if (ball_y == i && ball_x == j) {
                printf("o");
                continue;
            }
            if (i == -1 && j == 10) {
                printf("Players one score: %d", left_goal);
                continue;
            }
            if (i == -1 && j == 35) {
                printf("Players two score: %d", right_goal);
                continue;
            }
            if ((i == 0 || i == 25 - 1)) {
                printf("-");
                continue;
            }
            if ((j == 0 || j == 80) && i >= 0) {
                printf("|");
                continue;
            }
            if ((j == 1 && ((i == (rocket_left - 1) || i == (rocket_left + 1)) || i == rocket_left))) {
                printf("]");
                continue;
            }
            if ((j == 80 - 1 &&
                 ((i == (rocket_right - 1) || i == (rocket_right + 1)) || i == rocket_right))) {
                printf("[");
                continue;
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
