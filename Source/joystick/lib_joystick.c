/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           joystick.h
** Last modified Date:  2018-12-30
** Last Version:        V1.00
** Descriptions:        Atomic joystick init functions
** Correlated files:    lib_joystick.c, funct_joystick.c
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/

#include "LPC17xx.h"
#include "joystick.h"

/* Joystick pins on PORT1 */
#define JOYSTICK_UP_PIN      29
#define JOYSTICK_DOWN_PIN    26
#define JOYSTICK_LEFT_PIN    27
#define JOYSTICK_RIGHT_PIN   28
#define JOYSTICK_CENTER_PIN  25
extern int other_side_counter;

extern volatile uint8_t isPaused;
extern volatile uint8_t down_pressed;
extern volatile uint8_t press_right;
extern volatile uint8_t press_left;
extern volatile uint8_t press_up;

/*----------------------------------------------------------------------------
  Initialize joystick GPIOs + pull-up resistors
 *----------------------------------------------------------------------------*/
void joystick_init(void)
{
    /* GPIO function for P1.25 - P1.29 */
    LPC_PINCON->PINSEL3 &= ~(
        (3 << 18) |  // P1.25
        (3 << 20) |  // P1.26
        (3 << 22) |  // P1.27
        (3 << 24) |  // P1.28
        (3 << 26)    // P1.29
    );

    /* Set as input */
    LPC_GPIO1->FIODIR &= ~(
        (1 << JOYSTICK_UP_PIN) |
        (1 << JOYSTICK_DOWN_PIN) |
        (1 << JOYSTICK_LEFT_PIN) |
        (1 << JOYSTICK_RIGHT_PIN) |
        (1 << JOYSTICK_CENTER_PIN)
    );

    /* ENABLE PULL-UP (CRITICAL) */
    LPC_PINCON->PINMODE3 &= ~(
        (3 << 18) |  // P1.25
        (3 << 20) |  // P1.26
        (3 << 22) |  // P1.27
        (3 << 24) |  // P1.28
        (3 << 26)    // P1.29
    );
}

/*----------------------------------------------------------------------------
  Read joystick direction (active LOW)
 *----------------------------------------------------------------------------*/
uint8_t ReadJoystick(void)
{
    if ((LPC_GPIO1->FIOPIN & (1 << JOYSTICK_UP_PIN)) == 0)
        return 1;  // UP

    if ((LPC_GPIO1->FIOPIN & (1 << JOYSTICK_DOWN_PIN)) == 0)
        return 2;  // DOWN

    if ((LPC_GPIO1->FIOPIN & (1 << JOYSTICK_LEFT_PIN)) == 0)
        return 3;  // LEFT

    if ((LPC_GPIO1->FIOPIN & (1 << JOYSTICK_RIGHT_PIN)) == 0)
        return 4;  // RIGHT

    if ((LPC_GPIO1->FIOPIN & (1 << JOYSTICK_CENTER_PIN)) == 0)
        return 5;  // CENTER

    return 0;      // NONE
}

volatile uint8_t joystick_enabled = 1;  // Default: joystick is enabled

void disable_joystick(void) {
    joystick_enabled = 0;  // Disable joystick
}

void enable_joystick(void) {
    joystick_enabled = 1;  // Enable joystick
}
		
void HandleJoystickInput(void) {

    press_up    = !(LPC_GPIO1->FIOPIN & (1 << 29)); // UP
    down_pressed = !(LPC_GPIO1->FIOPIN & (1 << 26)); // DOWN
    press_left  = !(LPC_GPIO1->FIOPIN & (1 << 27)); // LEFT
    press_right = !(LPC_GPIO1->FIOPIN & (1 << 28)); // RIGHT
}
		
int isJoystickClicked(void) {

    if ((LPC_GPIO1->FIOPIN & (1 << JOYSTICK_CENTER_PIN)) == 0) {
        return 1;  // Center button clicked
    }
    return 0;  // Center button not clicked
}
