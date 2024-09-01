#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file;
    file.open("primenumber.txt");
    if(!file){
        cout<<"Error in creating file.."<<endl;
        return 1;
    }
    cout<<"File created successfully.."<<endl;
    //MARK: Writing to file pirme numbers ranging form 1 to n;
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    for(int i=2; i<=n; i++){
        int flag = 0;
        for(int j=2; j<=i/2; j++){
            if(i%j==0){
                flag = 1;
                break;
            }
        }
        if(flag==0){
            file<<i<<" ";
        }
    }
    cout<<"Data written to file successfully.."<<endl;
    file.close();
    //MARK: Reading from file
    ifstream readfile;
    readfile.open("primenumber.txt");
    if(!readfile){
        cout<<"Error in opening file.."<<endl;
        return 1;
    }   
    cout<<"File opened successfully.."<<endl;
    string line;
    cout<<"Data from file: "<<endl;
    while(!readfile.eof()){
        getline(readfile, line);
        cout<<line<<endl;
    }
    file.close();
    return 0;
}