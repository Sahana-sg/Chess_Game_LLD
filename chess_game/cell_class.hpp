class Piece;

class Cell{
    private:
        int x,y;
        Piece* piece;

    public:
        Cell(int x, int y, Piece* p): x(x), y(y), piece(p){}

        Piece* getPiece(){
            return this->piece;
        }

        void setPiece(Piece* p){
            piece = p;
        }

        int getX(){ return this->x;}

        int getY(){ return this->y;}
};