#include <bits/stdc++.h>
using namespace std;
    
class Shape{
    public:
    virtual void show() = 0;//Pure Virtual Function
};

class Circle : public Shape {
    public:
    void show(){
        cout<<"Circle"<<endl;
    }
};

class Rectangle : public Shape {
    public:
    void show(){
        cout<<"Rectangle"<<endl;
    }
};


int main()
{
    Shape *s;
    Circle c;
    Rectangle r;
    s = &c;
    s->show();
    s = &r;
    s->show();
return 0;
}