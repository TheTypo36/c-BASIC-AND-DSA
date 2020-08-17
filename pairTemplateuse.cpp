#include <iostream>
using namespace std;
#include "Pair.cpp"


int main(){

    Pair<Pair<int,int>,int> p;

    Pair<int,int> p2 ;
    p2.setX(15);
    p2.setY(16);
    p.setX(p2);
    p.setY(20);
    cout << p.getX().getX() << " " << p.getX().getY() << " " << p.getY() << endl;

}