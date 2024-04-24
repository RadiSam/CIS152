#include<plinko.h>
#include<iostream>
using namespace std;
//constructor&destructor
Plinko::Plinko() {
    course = makeCourse();
}
Plinko::~Plinko() {}
//getters
int Plinko::getResult() const {
    return result;
}
binarytree Plinko::getTree() const {
    return course;
}
//starts plinko and returns players pocket
int Plinko::startPlinko(Player p1, ReportNodes* node) {
    srand(time(0));
    int playerMoney = p1.getPocket();
    int reportEarnings = playerMoney;
    double scaleNum;
    btnodes* temp = course.getRoot();
    //goes through the branches ending at the leaf nodes randomly
    for(int i = 0; i < 4; i++) {
        int randNum = (rand() % 10) + 1;
        if (randNum > 5 ) {
            temp = temp->getRight();
        }
        else {
            temp = temp->getLeft();
        }
    }
    scaleNum = (double)temp->getScaleNum();
    // gives feedback based on scaleNum received
    if (scaleNum == 3.0) {
        cout << "Woah, looks like you tripled your pocket!" << endl;
    }
    else if (scaleNum == 0.0) {
        cout << "OH NO! looks like you lost all your money!" << endl;
    }
    else if (scaleNum == 1.0) {
        cout << "Seems like nothing changed. " << endl;
    }
    else {
        cout << "Nice, you got some money." << endl;
    }
    //updates info
    playerMoney *=scaleNum;
    reportEarnings = playerMoney - reportEarnings;
    node->setMoneyEarned(node->getMoneyEarned() + reportEarnings);
    node->setPResult(to_string(scaleNum));
    return playerMoney;
}
//makes preset course
binarytree Plinko::makeCourse() {
    binarytree tree;
    btnodes* n1 = new btnodes(4);
    tree.insert(n1, 0);
    btnodes* n2 = new btnodes(1.9);
    btnodes* n3 = new btnodes(1.9);
    tree.insert(n2, 0);
    tree.insert(n3, 1);
    btnodes* n4 = new btnodes(1.4);
    btnodes* n5 = new btnodes(2.6);
    btnodes* n6 = new btnodes(2.6);
    btnodes* n7 = new btnodes(1.4);
    tree.insert(n4, 0);
    tree.insert(n5, 0);
    tree.insert(n6, 1);
    tree.insert(n7, 1);
    btnodes* n8 = new btnodes(0.5);
    btnodes* n9 = new btnodes(1.6);
    btnodes* n10 = new btnodes(2.2);
    btnodes* n11 = new btnodes(2.9);
    btnodes* n12 = new btnodes(2.9);
    btnodes* n13 = new btnodes(2.2);
    btnodes* n14 = new btnodes(1.6);
    btnodes* n15 = new btnodes(0.5);
    tree.insert(n8, 0);
    tree.insert(n9, 0);
    tree.insert(n10, 0);
    tree.insert(n11, 0);
    tree.insert(n12, 1);
    tree.insert(n13, 1);
    tree.insert(n14, 1);
    tree.insert(n15, 1);
    btnodes* n16 = new btnodes(0);
    btnodes* n17 = new btnodes(1);
    btnodes* n18 = new btnodes(1.5);
    btnodes* n19 = new btnodes(1.75);
    btnodes* n20 = new btnodes(2);
    btnodes* n21 = new btnodes(2.5);
    btnodes* n22 = new btnodes(2.75);
    btnodes* n23 = new btnodes(3);
    btnodes* n24 = new btnodes(3);
    btnodes* n25 = new btnodes(2.75);
    btnodes* n26 = new btnodes(2.5);
    btnodes* n27 = new btnodes(2);
    btnodes* n28 = new btnodes(1.75);
    btnodes* n29 = new btnodes(1.5);
    btnodes* n30 = new btnodes(1);
    btnodes* n31 = new btnodes(0);
    tree.insert(n16, 0);
    tree.insert(n17, 0);
    tree.insert(n18, 0);
    tree.insert(n19, 0);
    tree.insert(n20, 0);
    tree.insert(n21, 0);
    tree.insert(n22, 0);
    tree.insert(n23, 0);
    tree.insert(n24, 1);
    tree.insert(n25, 1);
    tree.insert(n26, 1);
    tree.insert(n27, 1);
    tree.insert(n28, 1);
    tree.insert(n29, 1);
    tree.insert(n30, 1);
    tree.insert(n31, 1);

    return tree;
}
// returns course inorder as string
string Plinko::printCourse() {
    string result = course.inorderPrint(course.getRoot());
    return result;
}

/* tree diagrams
                10                  :1
       10                10         :2
   10     10         10       10    :4
 10  10  10  10   10   10  10  10   :8
1 1 1 1  1 1 1 1  1 1 1 1 1 1  1 1  :16

                            4
             1.9                             1.9
     1.4            2.6           2.6              1.4
 0.5    1.6     2.2     2.9    2.9      2.2      1.6    0.5
0   1 1.5 1.75 2 2.5 2.75 3   3 2.75 2.5  2     1.75 1.5 1 0

0 0.5 1 1.4 1.5 1.6 1.75 2 2.1 2.2 2.5 2.6 2.75 2.9 3 4
*/
