#include <bits/stdc++.h>
using namespace std;
    class Shapes{
        public:
        virtual void line() = 0;
        virtual void area() = 0;
    };

    class Rectangle: public Shapes{
        public:
        void line(){
            cout<<"This is a rectangle\n";
        }
        //calculate area
        void area(){
            int length = 5; // example length
            int breadth = 10; // example breadth
            cout<<"Area of rectangle is: "<<length * breadth<<endl;
        }
    };

class Trangle: public Shapes{
    public:
    void line(){
        cout<<"This is a triangle\n";
    }
    void area(){
        int base = 5; // example base
        int height = 10; // example height
        cout<<"Area of Trangle is: "<<0.5 * base * height<<endl;
    }
};



int main()
{
    Shapes *s;
    Rectangle r;
    Trangle t;
    s = &r;
    s->line();
    s->area();
    s = &t;
    s->line();
    s->area();
return 0;
}