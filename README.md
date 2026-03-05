# Tetris-Embedded-Game-for-LandTiger-LPC1768
Tetris game implemented for the LandTiger LPC1768 board using C and Keil µVision, featuring tetrominoes, line clearing, power-ups, adjustable speed, and audio support.



Tetris – Embedded Game for LandTiger LPC1768
Project Overview

This project implements a Tetris game for the LandTiger LPC1768 development board using C and Keil µVision. It combines two stages of development into a single playable game and demonstrates key embedded systems programming concepts, including:

Hardware interaction via joystick and buttons

Real-time control using timers

LCD graphics rendering

Game state management

The game is fully playable on the LandTiger emulator, with additional features available on a physical board.

Gameplay

Tetris is a classic block-stacking game where geometric shapes called tetrominoes descend from the top of the playing field. Players move and rotate the pieces to form complete horizontal lines, which are cleared to score points. The game ends when new pieces cannot enter the field.

Mechanics implemented:

Tetromino movement and rotation

Soft drop and hard drop

Line clearing and multiple-line scoring (“Tetris”)

Score tracking and high-score saving

Game pause and resume

Features
Core Features

20 × 10 grid playing field

Seven tetromino shapes: I, O, T, J, L, S, Z

Score system based on piece placement and line clearing

Game starts paused; toggle with KEY1

Soft drop (holding joystick down doubles fall speed)

Hard drop (KEY2 instantly drops piece)

Line clearing with proper shifting of remaining blocks

High-score tracking

Advanced Features

Adjustable game speed using a potentiometer (1–5 squares/sec)

Power-ups triggered every few cleared lines:

Clear half lines

Slow down game for 15 seconds

Random malus lines every 10 cleared lines to increase difficulty

Audio output for sound effects and background music (physical board only)

Controls
Joystick

Left / Right: Move tetromino horizontally

Up: Rotate 90° clockwise

Down: Soft drop

Buttons

KEY1: Start / pause game

KEY2: Hard drop

Development Environment

Board: LandTiger LPC1768

IDE: Keil µVision

Debug Target: SW_Debug (emulator)

Language: C

Notes: Audio and potentiometer features require the physical board

Repository Structure
Tetris-LandTiger/
│
├── Source/               # Source code (.c and .h files)
├── KeilProject/          # Keil project files (.uvprojx, .uvoptx)
├── docs/                 # Optional documentation
└── README.md             # Project description

Note: Generated build folders (Objects, Listings, DebugConfig) are excluded for a clean repository.

How to Run

Open sample.uvprojx in Keil µVision

Select SW_Debug target for emulator testing

Build and run the project

Press KEY1 to start; the game begins in paused mode

Use joystick and KEY2 for gameplay

Author

Embedded Systems Project – University Assignment
Demonstrates C programming, embedded game development, and real-time hardware interaction.
