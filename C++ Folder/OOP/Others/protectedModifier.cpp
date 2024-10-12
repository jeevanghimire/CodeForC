#include <iostream>
using namespace std;

class Base {
protected:
    int protectedValue;  // Protected member of Base class

public:
    Base(int value){
        this->protectedValue = value;
    }
    void modify(int value){
        this->protectedValue = value;
    }
    void showValue() const {
        cout << "private Value in Base: " << protectedValue << endl;
    }
};

class Derived : public Base {
public:
    Derived(int value): Base (value){}
    void modifyValue(int newValue) {
        protectedValue = newValue;
    }
    void showValueInDerived(){
        cout<<"Derived Class value: "<<protectedValue;
    }
};

int main() {
    Base obj2(20);
        obj2.showValue();
    Derived obj(10);
    obj.showValueInDerived();  
    obj.modifyValue(20);
    obj.showValueInDerived();  



    return 0;
}
