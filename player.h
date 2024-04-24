#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

//player class to hold info for player
class Player {
private:
    string name; //player name through user input
    int pocket; //amount of money player has
    int chances; //amount of chances has

public:
    //constructors&destructor
    Player();
    Player(string person, int money);
    ~Player();
    //setters
    void setPocket(int money);
    void setChances(int amount);
    //getters
    string getName() const;
    int getPocket() const;
    int getChances() const;
    //prints player info
    string printTitle();
    //checks for valid number input for roulette chance input
    int validChanceInput(int userInput);
};

#endif // PLAYER_H
