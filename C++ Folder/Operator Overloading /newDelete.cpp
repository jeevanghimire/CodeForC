#include <bits/stdc++.h>
using namespace std;
    
class NewDelet{
    int *p; 
    public:
    NewDelet(){
        cout<<"Constructor is called"<<endl;
        //allocate memory using new operator
        p = new int;
        cout<<"Memory is allocated"<<endl<<sizeof(p)<<endl;
    }
    //deallocate memory (in destructor)
    ~NewDelet(){
        cout<<"Destructor is called"<<endl;
        //deallocate memory using delete operator
        delete p;
        cout<<"Memory is deallocated"<<endl;
    }


};

int main()
{
    NewDelet obj;
return 0;
}
