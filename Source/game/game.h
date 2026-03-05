#ifndef GAME_H
#define GAME_H

void spawn_powerup(void);
void check_powerups(void);
void half_clear_powerup(void);
void slowdown_powerup(void);
void spawn_malus_line(void);  // spec3
void play_line_clear(void);  // Call from freeze_shape()
void play_rotate(void);      // Call from rotate_piece()

#endif