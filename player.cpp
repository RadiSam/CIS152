#include<player.h>
#include <iostream>
using namespace std;

//constructors&destructor
Player::Player() {
    name = "N/A";
    pocket = 0;
    chances = 0;
}
//sets player info and checks valid money amount entered
Player::Player(string person, int money) {
    name = person;
    pocket = money;
    if (pocket <= 0) {
        cout << "Invalid amount entered. You'll start with $100." << endl;
        pocket = 100;
    }
    if (pocket > 10000) {
        cout << "Let's not gamble all of that money away. You'll start with $10000." << endl;
        pocket = 10000;
    }
    chances = 0;
}
Player::~Player() {}

//setters
void Player::setPocket(int money) {
    pocket = money;
}
void Player::setChances(int amount) {
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
//checks for valid input for chance input
int Player::validChanceInput(int userInput) {
    string userRes = "";
    int newUseInput;
    //input less than 0
    if (userInput < 0) {
        cout << "Invalid input. Please enter a value greater than or equal to zero." << endl;
    }
    // input greater than chances held
    else if (0 > (chances - userInput)) {
        cout << "Invalid input. Please enter a chance amount available to you." << endl;
    }
    // input is valid
    else {
        return userInput;
    }
    // recursive branch when input invalid
    cout << "Would you like to enter a new amount yes or no?" << endl;
    cin >> userRes;
    if (userRes == "yes") {
        cout << "How many chances would you like to enter?" << endl;
        cin >> newUseInput;
        return validChanceInput(newUseInput);
    }
    else {
        cout << "Alright, see you next time!" << endl;
        return 0;
    }
}
