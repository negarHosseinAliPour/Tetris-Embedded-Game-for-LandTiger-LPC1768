#include "LPC17xx.h"
#include "GLCD/GLCD.h"
#include "game.h"
#include <stdlib.h>

// Declare variables from main.c
extern uint16_t placed_color[20][10];
extern uint8_t placed_powerup[20][10];
extern volatile int powerup_counter;
extern volatile uint8_t slowdown_active;
extern volatile int current_x, current_y;
extern uint16_t current_tetronomis[4][4];


extern volatile int Score;
extern volatile int highest_Score;
extern volatile int clearedline;
extern volatile int update_score;

extern int ROWS;
extern int COLUMNS;

void spawn_powerup(void) {
		GUI_Text(10, 30, (uint8_t *)"POWERUP SPAWNED", Cyan, Black);

    int row, col;
    int tries = 0;

    while (tries < 200) {   
        row = rand() % 20;
        col = rand() % 10;

        if (placed_color[row][col] != 0 &&
            placed_powerup[row][col] == 0) {

            placed_powerup[row][col] = (rand() % 2) + 1;

            LCD_DrawSquare(col, row, placed_color[row][col]);

            return;   
        }
        tries++;
    }
}


void half_clear_powerup(void) {
    int i,j;
    int line_count = 0;
    int k, row;
    for(i=19; i>=10; i--) {
        int full_line = 1;
        
        // Check if this line is full
        for(j=0; j<10; j++) {
            if(placed_color[i][j] == 0) {
                full_line = 0;  // Not full
                break;
            }
        }
        
        // Clear full line
        if(full_line == 1) {
            // Move lines above down
            for(k=i; k>0; k--) {
                for(j=0; j<10; j++) {
                    placed_color[k][j] = placed_color[k-1][j];
                }
            }
            // Clear top row
            for(j=0; j<10; j++) {
                placed_color[0][j] = 0;
            }
            line_count++;
            
            // Redraw board
            for(row=0; row<20; row++) {
                for(j=0; j<10; j++) {
                    if(placed_color[row][j] != 0) {
                        LCD_DrawSquare(j, row, placed_color[row][j]);
                    } else {
                        LCD_DrawSquare(j, row, Black);
                    }
                }
            }
        }
    }
    
    
		if (line_count > 0) {
				int groups = line_count / 4;
				int remainder = line_count % 4;

				Score += groups * 600;
				Score += remainder * 100;
				update_score = 1;
		}
				play_line_clear();

}

//slow down
void slowdown_powerup(void) {
    slowdown_active = 1;
}


void spawn_malus_line(void)
{
    int i, j;


    for (j = 0; j < COLUMNS; j++) {
        if (placed_color[0][j] != 0) {
            gameover();
            return;
        }
    }

    //Shift everything UP by one row 
    for (i = 0; i < ROWS - 1; i++) {
        for (j = 0; j < COLUMNS; j++) {
            placed_color[i][j]   = placed_color[i + 1][j];
            placed_powerup[i][j] = placed_powerup[i + 1][j];
        }
    }

    //Clear bottom row
    for (j = 0; j < COLUMNS; j++) {
        placed_color[ROWS - 1][j] = 0;
        placed_powerup[ROWS - 1][j] = 0;
    }

    //Add random blocks to the last row
    int count = 0;
    while (count < 7) {
        j = rand() % COLUMNS;
        if (placed_color[ROWS - 1][j] == 0) {
            placed_color[ROWS - 1][j] = Yellow;
            count++;
        }
    }

    
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            if (placed_color[i][j] != 0) {
                LCD_DrawSquare(j, i, placed_color[i][j]);
            } else {
                LCD_DrawSquare(j, i, Black);
            }
        }
    }
		GUI_Text(140, 270, (uint8_t*)"MALUS LINE!", Red, Black);
    //play_drop();   // sound feedback
}



