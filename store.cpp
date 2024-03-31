#include <store.h>

//constructor&destructor
Store::Store() {
    chances = 0;
    bank = 0;
}
Store::~Store() {}

//getters
int Store::getBank() {
    return bank;
}
int Store::getChances() {
    return chances;
}

// gives the player a chance to buy chances for roulette
void Store::buyStuff(Player &name) {
    string response = "";
    int chancesWanted = 0;
    cout << "Welcome to the store where you can buy chances!" << endl;
    cout << "Would you like to purchase items? y or n" << endl;
    cin >> response;
    if (response != "y") {
        cout << "Okay, see you next time!" << endl;
    }
    else {
        cout << "The price of a chance at roulette is $25. Would you like to buy? y or n" << endl;
        cin >> response;
        if (response != "y") {
            cout << "Okay, see you next time!" << endl;
        }
        else if (name.getPocket() < 25){
            cout << "Sorry. Insufficient funds. Come back next time." << endl;
        }
        else {
            cout << "How many chances would you like?" << endl;
            cin >> chancesWanted;
            if (25*chancesWanted > name.getPocket()) {
                cout << "Sorry. Insufficient funds. Come back next time." << endl;
            }
            else {
                name.setPocket(name.getPocket()-(25*chancesWanted));
                name.setChances(name.getChances()+chancesWanted);
                cout << name.printTitle() << endl;
            }
        }
    }
}
