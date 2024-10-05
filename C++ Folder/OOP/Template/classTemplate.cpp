#include <bits/stdc++.h>
using namespace std;
template <class T>
class something
{
private:
    T x;

public:
    something(T x) : x(x) {}
    void Show()
    {
        cout << x << endl;
    }
};
int main()
{
    something <int> s1(23);
    s1.Show();
    something <double> s2(23.333);
    s2.Show();
    return 0;
}