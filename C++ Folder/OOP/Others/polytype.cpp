#include <bits/stdc++.h>
using namespace std;

class base{
    protected:
        int salary;
        string name,adress;
        public:
        base(int salary = 0, string name = "", string adress = ""){
            this->name = name;
            this->adress= adress;
            this->salary = salary;
        }
        ~base(){

        }
        void print(){
            cout<<"Name: "<<name<<endl;
            cout<<"Adress: "<<adress<<endl;
            cout<<"Salary: "<<salary<<endl;
        }
};
class derived:public base{
    public:
    derived(){
        
    }
    derived():base(salary,name,adress){
        this->name = name;
        this->adress= adress;
        this->salary = salary;
    }
    void print(){
        cout<<"Name: "<<name<<endl;
        cout<<"Adress: "<<adress<<endl;
        cout<<"Salary: "<<salary<<endl;
    }
};
    
int main()
{
    base *bptr;
    derived d1;
    bptr = &d1;
    bptr->print();//function print will be binded to the bptr at runtime;
return 0;
}