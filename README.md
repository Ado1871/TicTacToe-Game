# Tic Tac Toe Game in C++

This project is a simple implementation of the classic Tic Tac Toe game in C++. It is a console application where two players can play against each other, or a single player can play against a basic AI (bot).

## Features

- **Player vs Player Mode:** Two players can play the game taking turns.
- **Player vs Bot Mode:** A single player can choose to play against a computer-controlled bot.
- **Replayability:** After a game is over, players are prompted to play again or exit the game.
- **Input Validation:** The game validates user input for selecting options and making moves on the game board.

## Requirements

- **Compiler**: The game was developed and tested with the GCC C++ compiler version 4.9.2. It should be compatible with most C++11 compliant compilers.

## How to Play

1. **Start the Game:** Run the compiled executable to start the game.
2. **Choose Game Mode:** Choose between 'Player vs Player' or 'Player vs Bot'.
3. **Playing the Game:**
   - The game board is a 3x3 grid, numbered from 1 to 9.
   - Players take turns to place their mark (X or O) in an empty spot on the board by entering the corresponding number.
   - The game continues until one of the players wins or the board is full (draw).
4. **Winning the Game:**
   - A player wins by placing three of their marks in a horizontal, vertical, or diagonal row.
   - If the board is filled without a winning condition, the game is a draw.
5. **Replay or Exit:**
   - After a game, you can choose to play again or exit the game.

## Compilation and Execution

To compile and run the game:

1. Ensure you have a C++ compiler installed.
2. Compile the source code.
3. Run the executable.

## License

This project is open-source. Feel free to modify and distribute as you see fit.
