#include<btnodes.h>

// constructors&destructor
btnodes::btnodes() {
    scalingNum = 0;
    left = nullptr;
    right = nullptr;
}
btnodes::btnodes(double scale) {
    scalingNum = scale;
    left = nullptr;
    right = nullptr;
}
btnodes::~btnodes() {}
//getters
double btnodes::getScaleNum() const {
    return scalingNum;
}
btnodes* btnodes::getLeft() const {
    return left;
}
btnodes* btnodes::getRight() const {
    return right;
}
//setters
void btnodes::setLeft(btnodes* value) {
    left = value;
}
void btnodes::setRight(btnodes* value) {
    right = value;
}
