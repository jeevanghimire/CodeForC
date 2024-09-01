#include <bits/stdc++.h>
using namespace std;

class Animal
{
public:
    virtual void sound()
    {
        cout << "sound of an animal" << "\n";
    }
};
class Dog : public Animal
{
public:
    void sound() override
    {
        cout << "Bark" << "\n";
    }
};

int main()
{
    Animal* animalPtr;
    Dog puppy;
    animalPtr = &puppy;
    animalPtr->sound();
    puppy.sound();
    
    
    return 0;
}