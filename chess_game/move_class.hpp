class Player;
class Piece;
class Cell;

class Move{
    private:
        Player* player;
        Piece* piece;
        Cell* start;
        Cell* end;
    public:
        Move(Player* pl, Piece* p, Cell* s, Cell* e): player(pl), piece(p), start(s), end(e) {}

        Player* getplayer(){
            return player;
        }

        Piece* getPiece(){
            return piece;
        }

        Cell* getStartCell(){
            return start;
        }

        Cell* getEndCell(){
            return end;
        }
};