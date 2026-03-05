#include "button.h"
#include "LPC17xx.h"
#include "GLCD/GLCD.h" 
#include "joystick/joystick.h"

//extern volatile int key1_debounce;
extern CurrentState;
extern volatile uint8_t joystick_enabled; 
extern volatile int gamestarted; 
extern new_shape;
extern volatile int bg_active;
void EINT0_IRQHandler (void)	  	/* INT0														 */
{

    LPC_SC->EXTINT |= (1 << 0); // Clear the interrupt flag for EINT0
}

volatile uint8_t key1_pressed = 0; // check if key1 is pressed 

extern volatile int isPaused; // 0 = Game running, 1 = Game paused


extern volatile int key1_debounce; // debouncing for key1


void EINT1_IRQHandler(void) {

	if (key1_debounce == 0) {
        
        key1_debounce = 10; 

        if (gamestarted == 0) {

						new_game();       
            gamestarted = 1;   
            isPaused = 0;      
            new_shape = 1;   
            bg_active = 1;
            

						GUI_Text(50, 10, (uint8_t *)"                    ", Black, Black); 
				} else {
            
            isPaused = !isPaused; // Toggle

            if (isPaused) { 
                GUI_Text(170, 10, (uint8_t *)"Pause ", Red, Black);
            } else { 
                GUI_Text(170, 10, (uint8_t *)"         ", Black, Black);
            }
        }
        
    }
    
    LPC_SC->EXTINT |= (1 << 1); // Clear pending interrupt
}

void EINT2_IRQHandler (void)	  	
{
	 volatile int i; 
   for (i = 0; i < 50000; i++);  //  delay
		
	
	if(gamestarted && !isPaused){
	
		while(allow_to_move_down()){ 
		move_down();
		}
	}
  LPC_SC->EXTINT &= (1 << 2);     /* clear pending interrupt         */  

}


