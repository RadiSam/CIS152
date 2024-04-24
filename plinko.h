#ifndef PLINKO_H
#define PLINKO_H
#include<binarytree.h>
#include<ctime>
#include<cstdlib>
#include<player.h>
#include<reportnodes.h>

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
    //takes player pocket to scale randomly and report node to update info
    int startPlinko(Player p1, ReportNodes* node);
    //makes plinko course
    binarytree makeCourse();
    //prints course inorder
    string printCourse();
};

#endif // PLINKO_H
