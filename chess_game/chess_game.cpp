#include<iostream>
#include"game_class.hpp"
using namespace std;

int main(){
    Player* player1 = new Player("Sahana", 0, COLOR::WHITE);
    Player* player2 = new Player("Chetan", 0, COLOR::BLACK);
    cout<<" WELCOME " <<player1->getName() << ", "<<player2->getName()<<endl;

    cout<<" To Continue type C \n";
    cout<<" To End type E \n";
    cout<<" To See Score type S \n";
    cout<<" To Undo type U \n";
    cout<<" To see History type H \n";

    Game* game = new Game(player1, player2);
    Player* currPlayer = player1;

    while(true){
        string input;
        cin>>input;
        if(input == "E") break;
        else if(input == "S") {
            cout<< player1->getName()<<" score : "<<player1->getScore();
            cout<< player2->getName()<<" score : "<<player2->getScore();
        }
        else if(input == "U") {
            game->undo();
        }
        else if(input == "H"){
            game->showHistory();
        }
        else if(input == "C"){
            string start, end;
            cout<<" Its "<<currPlayer->getName()<<"'s turn\n";
            cout<<" Please enter start and end point\n";
            cin>>start>>end;
            if(game->processMove(start, end, currPlayer)){
                if(currPlayer == player1){
                    currPlayer = player2;
                }else{
                    currPlayer = player1;
                }
            }
            else{
                cout<<" Try Again!\n";
            }
            
        }
        else {
            cout<<" Invalid Input!\n";
        }
    }       
}