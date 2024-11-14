/*
        MARK: OPERATOR OVERLOADING
        * Shortest Distance between two point or Local region ma chai (Distance Formula)
        TODO: make a class name point and add operator Overloading to find Euclidean Distance
        !!Formula for Euclidean distance = sqrt((x2-x1)^2 + (y2-y1)^2)
        @param myParam x(int) y(int)
*/
#include <iostream>
#include <cmath>
using namespace std;

class Point{
    public:
    int x,y;
    Point(){};
    Point ( int x , int y){
        this->x = x;
        this->y = y;
    }
    double operator - (Point& p){
    return sqrt( pow(x-p.x,2) + pow(y-p.y,2) );
    }

};

int main(){
    Point p1(2,3), p2(5,6);
    double p = p2-p1;
    cout<<"Distance Between P2 and P1 is: "<<p<<endl;
    return 0;
}