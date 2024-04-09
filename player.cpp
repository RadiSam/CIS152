#include<player.h>
#include <iostream>
using namespace std;

//constructor&destructor
Player::Player() {
    name = "N/A";
    pocket = 0;
}
//sets player info and checks valid money amount entered
Player::Player(string person, int money) {
    name = person;
    pocket = money;
    if(pocket <= 0) {
        cout << "Invalid amount entered. You'll start with $100." << endl;
        pocket = 100;
    }

}

Player::~Player() {}

//setters
void Player::setPocket(int money) {
    pocket = money;
}
void Player::setChances(int amount) {
    if (amount < 0) {
        cout << "Invalid input. Transaction cancelled" << endl;
        return;
    }
    chances = amount;
}
//getters
string Player::getName() const {
    return name;
}
int Player::getPocket() const {
    return pocket;
}
int Player::getChances() const {
    return chances;
}
//returns string of player info as report
string Player::printTitle() {
    string title = "Name: ";
    title.append(name);
    title.append("\nCurrency held: $" + to_string(pocket));
    title.append("\nChances held: " + to_string(chances));
    return title;
}
