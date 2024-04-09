#ifndef PLINKO_H
#define PLINKO_H
#include<binarytree.h>
#include<ctime>
#include<cstdlib>
#include<player.h>

//plinko to scale players entire pocket
class Plinko {
private:
    binarytree course; // binarytree course
    int result; // holds result
public:
    //constructors&destructor
    Plinko();
    ~Plinko();
    //getters
    int getResult() const;
    binarytree getTree() const;
    //starts plinko with players money and returns it
    int startPlinko(Player p1);
    //makes plinko course
    binarytree makeCourse();
    //prints course
    string printCourse();
};

#endif // PLINKO_H
