//basic of file handling in c++

#include <iostream>
#include <fstream>
using namespace std;
int main()
{

    fstream file;
    file.open("file.txt", ios::out);
    if(!file){
        cout<<"Error in opening file"<<endl;
    }
    else {
        cout<<"File opened successfully"<<endl;
        file<<"Hello World"<<endl;
        cout<<"Data written to file"<<endl;
    }
    file.close();
    fstream file2;
    file2.open("file.txt", ios::in);
    if(!file2){
        cout<<"Error in opening file"<<endl;
    }
    else {
        cout<<"File opened successfully"<<endl;
        cout<<"+---------------------------------+"<<endl;
        string line;
        while(file2){
            getline(file2, line);
            cout<<line<<endl;
        
        }
        cout<<"+---------------------------------+"<<endl;
    }
    file2.close();
    return 0;
}