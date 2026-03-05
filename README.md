# Tetris – Embedded Game for LandTiger LPC1768

## Project Overview
This project implements **Tetris** for the **LandTiger LPC1768** using **C** and **Keil µVision**.  
It demonstrates key embedded systems concepts:

- Hardware interaction via joystick and buttons  
- Real-time control using timers  
- LCD graphics rendering  
- Game state management  

The game is fully playable on the **LandTiger emulator**, with extra features available on a physical board.

---

## Gameplay
Tetris is a classic block-stacking game where **tetrominoes** fall from the top. Players move and rotate them to form complete horizontal lines, which are cleared to score points. The game ends when new pieces cannot enter the field.

**Mechanics implemented:**

- Tetromino movement and rotation  
- Soft drop and hard drop  
- Line clearing and multiple-line scoring (“Tetris”)  
- Score tracking and high-score saving  
- Game pause and resume  

---

## Features

### Core Features
- 20 × 10 grid playing field  
- Seven tetromino shapes: I, O, T, J, L, S, Z  
- Score system based on piece placement and line clearing  
- Game starts paused; toggle with **KEY1**  
- Soft drop (holding joystick down doubles fall speed)  
- Hard drop (**KEY2**) instantly drops piece  
- Line clearing with proper shifting of remaining blocks  
- High-score tracking  

### Advanced Features
- Adjustable game speed using a potentiometer (1–5 squares/sec)  
- Power-ups triggered every few cleared lines:
  - Clear half lines  
  - Slow down game for 15 seconds  
  - Random malus lines every 10 cleared lines  
- Audio output for sound effects and background music (physical board only)  

---

## Controls

**Joystick**  
- Left / Right: Move tetromino horizontally  
- Up: Rotate 90° clockwise  
- Down: Soft drop  

**Buttons**  
- **KEY1**: Start / pause game  
- **KEY2**: Hard drop  

---

## Development Environment
- **Board:** LandTiger LPC1768  
- **IDE:** Keil µVision  
- **Debug Target:** SW_Debug (emulator)  
- **Language:** C  
- **Note:** Audio and potentiometer features require the physical board  

---

## Repository Structure
Tetris-LandTiger/
│
├── Source/ # Source code (.c and .h files)
├── KeilProject/ # Keil project files (.uvprojx, .uvoptx)
├── docs/ # Optional documentation
└── README.md # Project description


*Generated build folders (Objects, Listings, DebugConfig) are excluded for a clean repository.*

---

## How to Run
1. Open `sample.uvprojx` in Keil µVision  
2. Select **SW_Debug** target for emulator testing  
3. Build and run the project  
4. Press **KEY1** to start; the game begins in paused mode  
5. Use joystick and **KEY2** for gameplay  

---

## Author
**Embedded Systems Project – University Assignment**  

Demonstrates **C programming**, **embedded game development**, and **real-time hardware interaction**.


