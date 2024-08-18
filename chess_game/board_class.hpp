#include "pieces_class.hpp"

class Board{
    private:
        Cell* cells[8][8];
    public:
        Board();
        void displayBoard();
        void resetBoard();
        Cell* getCell(int x, int y);
        bool isValidCell(Cell* cell);
};