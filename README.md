# Chess_Game_LLD
# Overview
This repository contains the low-level design and implementation of an online chess game. The code is structured around object-oriented principles, following a class diagram that models the key components of a chess game. The application allows two players to engage in a game of chess with a variety of features such as move validation, move history, undo functionality, and score tracking.

# Features
The chess game supports the following features:


- Players take turns to make moves. The game enforces the rules of chess to ensure that each move is valid.
  Move Pieces:

- Players can move pieces according to the rules of chess.

- Players can capture (kill) the opponent's pieces, following standard chess rules.

- Players can undo their last move. This is particularly useful for correcting mistakes or exploring different strategies. 

- The game maintains a complete history of all moves made during the game. Players can review this history to analyze their strategy and performance.

- The game calculates and displays the score of each player based on the value of the pieces they have captured.

- Players have the option to end the game at any time, regardless of the current state of play.

# Class Diagram
The code follows a detailed class diagram which includes the following primary classes:

Game: Manages the overall flow of the game, including starting and ending the game, tracking the current turn, and handling the move history.

Board: Represents the 8x8 chessboard and manages the placement of pieces.

Player: Represents a player in the game, including the player's name, color, and score.

Piece: An abstract base class for all chess pieces (e.g., King, Queen, Rook, Bishop, Knight, Pawn). Contains common attributes and methods for pieces.

Specific Piece Classes (King, Queen, Rook, etc.): These inherit from the Piece class and implement the specific movement rules for each type of piece.

Move: Represents a move in the game, including the piece moved, the starting and ending positions, and whether any piece was captured.
