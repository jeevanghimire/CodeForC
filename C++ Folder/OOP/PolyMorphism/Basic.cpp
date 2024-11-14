#include <bits/stdc++.h>
using namespace std;
    

class base{
    public:
    void show(){
        cout<<"Base class"<<endl;
    }
};

class derived: public base{
    public:
    void show(){
        cout<<"Derived class"<<endl;
    }
};
int main()
{
    base *b;
    derived d;
    b = &d;
    b->show();
    d.show();
return 0;
}