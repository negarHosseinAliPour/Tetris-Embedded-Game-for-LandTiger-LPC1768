#include "joystick.h"
#include <stdio.h>
#define ROWS 20
#define COLUMNS 10
extern volatile int current_x;
extern volatile int current_y;
extern volatile int random_indx;
extern const uint16_t temtronomColor[7];

extern uint16_t placed_color[20][10];
uint16_t current_tetronomis[4][4];
extern const uint16_t tetronomis[7][4][4];

int allow_to_move_left(void) {
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (current_tetronomis[i][j] != 0) {
                int y = current_y + i;
                int x = current_x + j - 1; 

                if (x < 0) {
                    return 0;
								}
								
                if (y >= 0 && y < ROWS && placed_color[y][x] != 0) {
                    return 0;
                }
            }
        }
    }
    return 1; 
}

int allow_to_move_right(void) {
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (current_tetronomis[i][j] != 0) {
                int y = current_y + i;
                int x = current_x + j + 1;

                if (x >= COLUMNS) {
                    return 0;
                }
                if (y >= 0 && y < ROWS && placed_color[y][x] != 0) {
                    return 0;
                }
            }
        }
    }
    return 1; 
}

void move_left(void) {
    if (allow_to_move_left()) {
        draw_rotate_tetronomis(current_x, current_y, Black);
        current_x--;                                         
        draw_rotate_tetronomis(current_x, current_y, temtronomColor[random_indx]);
				play_rotate();
		}
}

void move_right(void) {
    if (allow_to_move_right()) {
        draw_rotate_tetronomis(current_x, current_y, Black); 
        
        current_x++; 
        
        draw_rotate_tetronomis(current_x, current_y, temtronomColor[random_indx]); 
				play_rotate();
    }
}

void move_down(void) {

    draw_rotate_tetronomis(current_x, current_y, Black);
    current_y += 1;
    draw_rotate_tetronomis(current_x, current_y, temtronomColor[random_indx]);
		play_rotate();
}

void move_up(void) {
    draw_rotate_tetronomis(current_x, current_y, Black);
    rotate_shape();
    draw_rotate_tetronomis(current_x, current_y, temtronomColor[random_indx]);
		play_rotate();
}

void copy_tetronomis(int random_indx) {
	int i, j;
    for (i=0; i<4; i++) {
        for(j=0; j<4; j++) {
            current_tetronomis[i][j] = tetronomis[random_indx][i][j];
        }
    }
}

