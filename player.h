#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

class Player {
private:
    string name; //player name through user input
    int pocket; //amount of money player has
    int chances; //amount of chances has

public:
    Player();
    Player(string person, int money);
    ~Player();
    //setter
    void setPocket(int money);
    void setChances(int amount);
    //getters
    string getName() const;
    int getPocket() const;
    int getChances() const;

    string printTitle();
};

#endif // PLAYER_H
