#include "game_class.hpp"

Game::Game(Player* p1, Player* p2){
    players[0] = p1;
    players[1] = p2;
    board = new Board();
}

void Game::displayBoard(){
    board->displayBoard();
}

pair<int, int> Game::getPositions(string point){
    int f = (point[0]-'0') - 1;
    int s = (point[1]-'a');
    return make_pair(f, s);
}

bool Game::checkValidMove(Piece* piece, Player* player, Cell* startCell, Cell* endCell){
    if(piece != nullptr){
        if(piece->isValidMove(startCell, endCell)){
            return (piece->getColor() == player->getColor());
        }
        else {
            cout<<" Piece Can't move this way!!\n";
            return false;
        }
        
    }
    return false;
}

bool Game::processMove(string start, string end, Player* player){
    pair<int, int> st = getPositions(start);
    pair<int, int> en = getPositions(end);

    Cell* startCell = board->getCell(st.first, st.second);
    Cell* endCell = board->getCell(en.first, en.second);
    if(board->isValidCell(startCell) && board->isValidCell(endCell)){
        return move(startCell, endCell, player);
    }
    else{
        cout<<" Out Of Box!!";
        return false;
    }
}

bool Game::move(Cell* startCell, Cell* endCell, Player* player){
    Piece* cellPiece = startCell->getPiece();
    Move* currMove = new Move(player, cellPiece, startCell, endCell);

    if(endCell->getPiece() != nullptr){
        Piece* killed = endCell->getPiece();
        int currScore = player->getScore();
        player->setScore(currScore+1);
        cout<<endCell->getPiece()->getName()<<" is Killed by "<<player->getName()<<"\n";
    }

    if(checkValidMove(cellPiece, player, startCell, endCell)){
        cellPiece->move(endCell);
        endCell->setPiece(cellPiece);
        startCell->setPiece(nullptr);
        moveHistory.push_back(currMove);
        cout<<player->getName()<<" moved "<<cellPiece->getName()<<" from ["<<startCell->getX()<<", "<<startCell->getY()<<"]";
        cout<<" to ["<<endCell->getX()<<", "<<endCell->getY()<<"]\n";
    }
    else{
        cout<<" Invalid Move!!";
        return false;
    }
    board->displayBoard();
    return true;
}

void Game::undo()
{
    if(moveHistory.size() > 0){
        Move* lastmove = moveHistory.back();
        Cell* start = lastmove->getStartCell();
        Cell* end = lastmove->getEndCell();
        Player* lastplayer = lastmove->getplayer();
        bool mv = move(end, start, lastplayer);
        moveHistory.pop_back();
    }
    else {
        cout<<" NO HISTORY!!";
        return;
    }
}

void Game::showHistory(){
    int sz = moveHistory.size();

    if(sz > 0){
        for(int i = (sz-1); i>=0; i--){
            Move* lastmove = moveHistory[i];
            Cell* startCell = lastmove->getStartCell();
            Cell* endCell = lastmove->getEndCell();
            Player* lastplayer = lastmove->getplayer();
            Piece* cellPiece = lastmove->getPiece();
            
            cout<<lastplayer->getName()<<" moved "<<cellPiece->getName()<<" from ["<<startCell->getX()<<", "<<startCell->getY()<<"]";
            cout<<" to ["<<endCell->getX()<<", "<<endCell->getY()<<"]\n";
        }       
    }
    else {
        cout<<" NO HISTORY!!";
        return;
    }
}