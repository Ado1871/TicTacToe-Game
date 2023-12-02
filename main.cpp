#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

class TicTacToe {
private:
    char board[3][3];	// The game board
    int choice;			// Player choice for a move
    int row, column;	// Coordinates for the chosen move
    char turn;			// Current player turn ('X' or 'O')
    bool draw;			// Flag for a draw game
    bool againstBot;	// Flag for playing against bot

public:
	// Constructor to initialize the game
    TicTacToe() : turn('X'), draw(false), againstBot(false) {
        resetBoard();
    }
    
    // Resets the game board to its initial state
    void resetBoard() {
        char counter = '1';
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = counter++;
            }
        }
	}

	// Prompts the player to choose the game mode
    void chooseGameMode() {
    	system("cls");
        cout << "Choose game mode:\n";
        cout << "1. Player vs Player\n";
        cout << "2. Player vs Bot\n\n";
        cout << "Enter your choice (1 or 2): ";
        int gameMode;
        while (!(cin >> gameMode) || (gameMode != 1 && gameMode != 2)) {
            cout << "Invalid input! Please enter 1 or 2: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        againstBot = (gameMode == 2);
    }
	// Displays the current state of the game board
    void displayBoard() {
        system("cls");
        cout << "     Tic Tac Toe     \n";
        cout << "Player1 [X]  Player2 [O]\n\n";
        for (int i = 0; i < 3; ++i) {
            cout << "     |     |     \n";
            for (int j = 0; j < 3; ++j) {
                cout << "  " << board[i][j] << "  ";
                if (j < 2) cout << "|";
            }
            if (i < 2) cout << "\n_____|_____|_____\n";
        }
        cout << "\n     |     |     \n\n";
    }

	// Handles the player's turn
    void playerTurn() {
        bool validInput = false;
        while (!validInput) {
            if (turn == 'X') {
                cout << "Player1 [X] turn: ";
            } else if (againstBot) {
                botTurn();
                return;
            } else {
                cout << "Player2 [O] turn: ";
            }

            while (!(cin >> choice) || choice < 1 || choice > 9) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number between 1 and 9.\n";
                cout << (turn == 'X' ? "Player1 [X] turn: " : "Player2 [O] turn: ");
            }

            row = (choice - 1) / 3;
            column = (choice - 1) % 3;

            if (board[row][column] != 'X' && board[row][column] != 'O') {
                board[row][column] = turn;
                turn = (turn == 'X') ? 'O' : 'X';
                validInput = true;
            } else {
                cout << "Box already filled! Please choose another!!\n\n";
            }
        }
    }

	// Handles the bot's turn (random move)
    void botTurn() {
        srand(time(0)); 
        bool validMove = false;
        while (!validMove) {
            choice = rand() % 9 + 1; 
            row = (choice - 1) / 3;
            column = (choice - 1) % 3;

            if (board[row][column] != 'X' && board[row][column] != 'O') {
                board[row][column] = 'O';
                cout << "Player2 [O] (Bot) has made a move " << choice << endl;
                turn = 'X';
                validMove = true;
            }
        }
    }

    // Checks if the game is over (win or draw)
	bool gameover() {
	    // Check for win
	    for (int i = 0; i < 3; i++) {
	        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return false;
	        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return false;
	    }
	
	    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return false;
	    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return false;
	
	    // Check for draw
	    draw = true;
	    for (int i = 0; i < 3; i++) {
	        for (int j = 0; j < 3; j++) {
	            if (board[i][j] != 'X' && board[i][j] != 'O') {
	                draw = false;
	                return true;
	            }
	        }
	    }
	
	    return false; // Game is a draw
	}

	// Starts and manages the game loop
    void startGame() {
        while (gameover()) {
            displayBoard();
            playerTurn();
            gameover();
        }

        displayBoard();
        if (turn == 'X' && !draw) {
            cout << "Player2 [O] Wins!! Congratulations\n";
        } else if (turn == 'O' && !draw) {
            cout << "Player1 [X] Wins!! Congratulations\n";
        } else {
            cout << "Game Draw!!\n";
        }
    }
};

// Shows Main Menu
int showMainMenu() {
	system("cls");
    cout << "Tic Tac Toe Game\n";
    cout << "1. Start new game\n";
    cout << "2. Exit\n\n";
    cout << "Enter your choice (1 or 2): ";

    int choice;
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        cout << "Invalid input! Please enter 1 or 2: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return choice;
}

// Main Function
int main() {
    while (true) {
        int choice = showMainMenu();
        if (choice == 2) break; // Exit the game

        TicTacToe game;
        game.chooseGameMode();
        game.startGame();
    }

    cout << "Thank you for playing Tic Tac Toe!" << endl;
    return 0;
}
