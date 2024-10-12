// WAP that takes 3 numbers and displays its quadratic number ax^2 + bx + c
// b^2 - 4ac == +ve then roots are real and distinct
// b^2 - 4ac == 0 then roots are real and equal
// b^2 - 4ac == -ve then roots are imaginary

#include <bits/stdc++.h>
using namespace std;

class QuadraticInfoTaker
{
private:
    int a, b, c;
public:
    QuadraticInfoTaker(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    void PrintRoots()
    {
        int root1, root2;
        int d = ((b*b)-4*a*c);
        // checking whether the roots are real or not
        if (d >= 0)
        {
            cout << "the roots are real and can be calculated" << endl;
            root1 = (-b + sqrt(d)) / (2 * a);
            root2 = (-b - sqrt(d)) / (2 * a);
            cout << "root 1 = " << root1 << endl;
            cout << "root 2 = " << root2 << endl;
        }
        else
        {
            cout << "the roots are imaginary" << endl;
        }
    }
    ~QuadraticInfoTaker()
    {
        cout << "Destructor called" << endl;
    }
};

int main()
{
    int a, b, c;
    cout << "a:";
    cin >> a;
    cout << "b:";
    cin >> b;
    cout << "c: ";
    cin >> c;
    QuadraticInfoTaker Q1(a, b, c);
    Q1.PrintRoots();
    
    return 0;
}
