#include "board_class.hpp"

Board::Board(){
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            cells[i][j] = nullptr;
        }
    }
    resetBoard();
    displayBoard();
}

Cell* Board::getCell(int x, int y){
    return cells[x][y];
}

void Board::resetBoard(){

    // white pieces
    cells[0][0] = new Cell(0, 0, new Rook(COLOR::WHITE));
    cells[0][1] = new Cell(0, 1, new Knight(COLOR::WHITE));
    cells[0][2] = new Cell(0, 2, new Bishop(COLOR::WHITE));
    cells[0][3] = new Cell(0, 3, new Queen(COLOR::WHITE));
    cells[0][4] = new Cell(0, 4, new King(COLOR::WHITE));
    cells[0][5] = new Cell(0, 5, new Bishop(COLOR::WHITE));
    cells[0][6] = new Cell(0, 6, new Knight(COLOR::WHITE));
    cells[0][7] = new Cell(0, 7, new Rook(COLOR::WHITE));

    for(int i = 0; i<8; i++){
        cells[1][i] = new Cell(1, i, new Pawn(COLOR::WHITE));
    }

    // Black pieces
    cells[7][0] = new Cell(7, 0, new Rook(COLOR::BLACK));
    cells[7][1] = new Cell(7, 1, new Knight(COLOR::BLACK));
    cells[7][2] = new Cell(7, 2, new Bishop(COLOR::BLACK));
    cells[7][3] = new Cell(7, 3, new Queen(COLOR::BLACK));
    cells[7][4] = new Cell(7, 4, new King(COLOR::BLACK));
    cells[7][5] = new Cell(7, 5, new Bishop(COLOR::BLACK));
    cells[7][6] = new Cell(7, 6, new Knight(COLOR::BLACK));
    cells[7][7] = new Cell(7, 7, new Rook(COLOR::BLACK));

    for(int i = 0; i<8; i++){
        cells[6][i] = new Cell(6, i, new Pawn(COLOR::BLACK));
    }

    // remaining with null piece

    for(int i = 2; i<6; i++){
        for(int j = 0; j<8; j++){
            cells[i][j] = new Cell(i, j, nullptr);
        }
    }
}

void Board::displayBoard(){

    for(int i = 0; i<8; i++){
        cout<<"\t\t";
        for(int j = 0; j<8; j++){
            if(cells[i][j]->getPiece() == nullptr){
                cout<<".\t";
            }
            else {
                Piece* curr = cells[i][j]->getPiece();
                if(curr->getColor() == COLOR::BLACK) {
                    cout<<" B";
                }
                else cout<<" W";

                cout<<curr->getName()<<" ";
            }
        }
        cout<<"\n";
    }
}

bool Board::isValidCell(Cell* cell){
    int x = cell->getX();
    int y = cell->getY();

    if(x>=0 && x<=7 && y>=0 && y<=7) return true;
    return false;
}