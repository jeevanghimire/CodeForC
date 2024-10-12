#include <bits/stdc++.h>
#include<string>
using namespace std;
class Animal
{
protected:
string Name;
int age;
string breed;
public:
Animal(string Name,int age,string breed){
    this->Name=Name;
    this->age=age;
    this->breed=breed;
}
void IntroAnimal(){
    cout<<"I am an animal"<<endl;
}
};
class Dog:public Animal{
public:
Dog(string Name,int age,string breed):Animal(Name,age,breed){
    this->Name=Name;
    this->age=age;
    this->breed=breed;
}
void IntroAnimal(){
    cout<<"I am an Dog"<<endl;
    cout<<"Name Of Animal: "<<Name<<endl;
    cout<<"Age Of Animal: "<<age<<endl;
    cout<<"Breed Of Animal: "<<breed<<endl;
}
};

int main()
{
    Animal myAnimal("German Shephard",5,"Dog");
    Dog myDog("German Shephard_2",8,"Dog_2");
    myAnimal.IntroAnimal();
    myDog.IntroAnimal();
    return 0;
}