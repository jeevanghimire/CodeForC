/*
* Syntax of overloading operators in C++
! return_type operator symbol (list of parameters){ //code }
TODO addition operator overloading 
     * 2+3
     * car1 + car2;
     *
*/
#include <bits/stdc++.h>
using namespace std;
class point {
    private:
    int x,y;

    public:
    point(int X=0, int Y = 0): x(X), y(Y){}

    point operator + (point& P){
        P.x += x;
        P.y+= y;
        return P;
    }
    void display(){
        cout<< "x : "<<x <<endl<<"y : "<<y<<endl;
    }
};


int main() {

    point p1(2,3), p2(5,4);

    point product = p1 + p2;
    product.display();

    return 0;
}