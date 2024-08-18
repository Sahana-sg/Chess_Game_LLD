#include "common_class.hpp"
#include "cell_class.hpp"
#include <string>
#include<iostream>
#include <cmath>
using namespace std;
 
class Piece{
    protected:
        COLOR color;
    public:
        Piece(COLOR c): color(c){}
        virtual bool isValidMove(Cell* start, Cell* end) = 0;
        virtual void move(Cell* destination) = 0;
        virtual string getName() = 0;
        COLOR getColor(){
            return color;
        }
};

class King:public Piece{
    public:
        King(COLOR c): Piece(c){}
        bool isValidMove(Cell* start, Cell* end){
            int startx = start->getX();
            int starty = start->getY();

            int endx = end->getX();
            int endy = end->getY();

            int dx = abs(endx - startx);
            int dy = abs(endy - starty);

            // The king can move one square in any direction
            if (dx <= 1 && dy <= 1) {
                return true;
            }
            return false;
        }
        string getName(){
            return "King";
        }
        void move(Cell* destination){
            cout<< getName()<<" MOVED TO ["<<destination->getX()<<", "<<destination->getY()<<"]\n";
        }
};

class Queen:public Piece{
    public:
        Queen(COLOR c): Piece(c){}
        bool isValidMove(Cell* start, Cell* end){
            int startx = start->getX();
            int starty = start->getY();

            int endx = end->getX();
            int endy = end->getY();

            // Check if the move is along the same row or same column
            if (startx == endx || starty == endy) {
                return true;
            }
            // Check if the move is along a diagonal
            else if (abs(endx - startx) == abs(endy - starty)) {
                return true;
            }
            return false;
        }

        string getName(){
            return "Queen";
        }
        void move(Cell* destination){
            cout<< getName()<<" MOVED TO ["<<destination->getX()<<", "<<destination->getY()<<"]\n";
        }
};

class Bishop:public Piece{
    public:
        Bishop(COLOR c): Piece(c){}
        bool isValidMove(Cell* start, Cell* end){

            int startx = start->getX();
            int starty = start->getY();
            int endx = end->getX();
            int endy = end->getY();

            if (abs(endx - startx) == abs(endy - starty)) {
                return true;
            }
            return false;
        }
        string getName(){
            return "Bishop";
        }
        void move(Cell* destination){
            cout<< getName()<<" MOVED TO ["<<destination->getX()<<", "<<destination->getY()<<"]\n";
        }
};

class Rook:public Piece{
    public:
        Rook(COLOR c): Piece(c){}
        bool isValidMove(Cell* start, Cell* end){
            int startx = start->getX();
            int starty = start->getY();
            int endx = end->getX();
            int endy = end->getY();

            if (startx == endx || starty == endy) {
                return true;
            }
            return false;
        }
        string getName(){
            return "Rook";
        }
        void move(Cell* destination){
            cout<< getName()<<" MOVED TO ["<<destination->getX()<<", "<<destination->getY()<<"]\n";
        }
};

class Knight:public Piece{
    public:
        Knight(COLOR c): Piece(c){}
        bool isValidMove(Cell* start, Cell* end){
            int startx = start->getX();
            int starty = start->getY();
            int endx = end->getX();
            int endy = end->getY();

            int dx = abs(endx - startx);
            int dy = abs(endy - starty);

            // Check for the "L" shape move: (2, 1) or (1, 2)
            if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) {
                return true;
            }
            return false;
        }
        string getName(){
            return "Knight";
        }
        void move(Cell* destination){
            cout<< getName()<<" MOVED TO ["<<destination->getX()<<", "<<destination->getY()<<"]\n";
        }
};

class Pawn:public Piece{
    public:
        Pawn(COLOR c): Piece(c){}
        bool isValidMove(Cell* start, Cell* end){
            // logic here
            return true;
        }
        string getName(){
            return "Pawn";
        }
        void move(Cell* destination){
            cout<< getName()<<" MOVED TO ["<<destination->getX()<<", "<<destination->getY()<<"]\n";
        }
};