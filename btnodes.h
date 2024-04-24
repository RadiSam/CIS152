#ifndef BTNODES_H
#define BTNODES_H
#include<string>
using namespace std;

//Node Class that holds child directions and double
class btnodes {
private:
    double scalingNum;
    btnodes* left;
    btnodes* right;
public:
    //constructors&destructor
    btnodes();
    btnodes(double scale);
    ~btnodes();
    //getters
    double getScaleNum() const;
    btnodes* getLeft() const;
    btnodes* getRight() const;
    //setters
    void setLeft(btnodes* value);
    void setRight(btnodes* value);
};

#endif // BTNODES_H
