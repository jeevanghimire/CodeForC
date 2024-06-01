#include <iostream>
using namespace std;


class House{
    int rooms;
    double lenght , width, area;
    string color;
    public:
    double speicific(){
        cout<<"Enter lenght and breath:\n";
        cin>>lenght>>width;
        return lenght*width;
    }
};

int main(){
    House house1;
    cout<<"Area is \n:{ "<<house1.speicific()<<" }\n";
    return 0;
}