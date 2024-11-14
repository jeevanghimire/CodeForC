#include <bits/stdc++.h>
using namespace std;
    
class rupee{
    public:
    int paisa;
    rupee(){};//deafult constructor
    rupee(int x){
        paisa = x;
    }
    void show (){
        cout<<"Paisa Is: "<<paisa<<endl;
    }

};

class dollar{
    public:
    int dollarPaisa;
    dollar(int x){
        dollarPaisa = x;
    }
    operator rupee(){
            rupee temp;
            temp.paisa = dollarPaisa*134;
            return temp;
    }
    void show(){
        cout<<"Dollar ma Paisa chai yeti : "<<dollarPaisa<<endl;
    }
};


int main()
{
    dollar money(20);
    money.show();
    rupee money2 = money;
    money2.show();
return 0;
}