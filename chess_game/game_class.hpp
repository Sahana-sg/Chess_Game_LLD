#include "player_class.hpp"
#include "board_class.hpp"
#include "move_class.hpp"
#include <vector>

class Game {
    private:
        Player* players[2];
        Board* board;
        vector<Move* > moveHistory;

    public:
        Game(Player* p1, Player* p2);
        void displayBoard();
        bool processMove(string start, string end, Player* player);
        bool move(Cell* startCell, Cell* endCell, Player* player);
        bool checkValidMove(Piece* piece, Player* player, Cell* startCell, Cell* endCell);
        pair<int, int> getPositions(string point);
        void undo();
        void showHistory(); 
};