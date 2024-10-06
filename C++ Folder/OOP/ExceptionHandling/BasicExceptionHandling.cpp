#include <iostream>
using namespace std;
    
int main()
{
int age;
cout << "Enter your age: ";
cin >> age;
try{
    if(age <0 || age > 200)
    throw age;
}
catch(int age){
    cout << "Invalid age: " << age << endl;
}
catch(...){
    cout << "Something went wrong" << endl;
}
return 0;
}
