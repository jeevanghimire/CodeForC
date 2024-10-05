#include <bits/stdc++.h>
using namespace std;
    template <class T1, class T2>
    T1 average(T1 x, T2 y){
        return (x + y)/2;
    }
int main()
{
    int a = 5, b = 5;
    double a1 = 4.333, a2 = 5.3334;
    cout<<average<int, int>(a,b)<<endl;
    cout<<average<double , double>(a1,a2)<<endl;
return 0;
}