/*
        MARK: OPERATOR OVERLOADING
        * Shortest Distance between two point or Local region ma chai (Distance Formula)
        TODO: make a class name point and add operator Overloading to find Euclidean Distance
        !!Formula for Euclidean distance = sqrt((x2-x1)^2 + (y2-y1)^2)
        @param myParam x(int) y(int)
*/


#include <bits/stdc++.h>
using namespace std;

class Point{
        int x,y;
    public:
        Point(int X = 0,int Y =0): x(X), y(Y) {}
        
        double operator - (Point& p){
            return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
        }
        
    };
int main()
{
    Point p1(2,3), p2(5,4);
    double distance = p1-p2;
    //print the statement 
    cout<<"The Euclidean Distance between two point is: "<<distance<<endl;

return 0;
}