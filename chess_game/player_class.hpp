#include<string>
using namespace std;

enum class COLOR;
class Player{
    private:
        string name;
        int score;
        COLOR color;
    public:
        Player(string n, int s, COLOR c): name(n), score(s), color(c){}

        string getName(){
            return this->name;
        }

        int getScore(){
            return this->score;
        }  

        void setScore(int scr){
            this->score = scr;
        }

        COLOR getColor(){
            return color;
        }   

};