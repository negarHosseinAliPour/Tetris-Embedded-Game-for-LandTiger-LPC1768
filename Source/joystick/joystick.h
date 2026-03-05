/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           joystick.h
** Last modified Date:  2018-12-30
** Last Version:        V1.00
** Descriptions:        Prototypes of functions included in the lib_joystick, funct_joystick .c files
** Correlated files:    lib_joystick.c, funct_joystick.c
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/
#include "GLCD/GLCD.h"


/* lib_joystick */
void joystick_init(void);
void HandleJoystickInput(void);
int isJoystickClicked(void) ;
void enable_joystick(void) ;
void disable_joystick(void);
