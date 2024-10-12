#include <bits/stdc++.h>
using namespace std;
class mul2;
class mul1
{
private:
    int numb1;

public:
    mul1(int n)
    {
        this->numb1 = n;
    }
    // friend class
    friend class T1;
    friend void multiply(mul1 &obj1, mul2 &obj2);
};

class mul2
{
private:
    int numb2;

public:
    mul2(int n)
    {
        this->numb2 = n;
    }
    friend class T2;
    friend void multiply(mul1 &obj1, mul2 &obj2);
};
class T1
{
public:
    void display(mul1 &t1)
    {
        cout << "Numb1: " << t1.numb1 << " ";
    }
};
class T2
{
public:
    void display(mul2 &t2)
    {
        cout << "Numb2: " << t2.numb2 << endl;
    }
};
void multiply(mul1 &obj1, mul2 &obj2)
{
    int result;
    result = obj1.numb1 * obj2.numb2;
    cout << "Multiply of numb1 and numb2 is :" << result << endl;
}

int main()
{
    mul1 numb1(2);
    mul2 numb2(3);
    T1 t1;
    T2 t2;
    t1.display(numb1);
    t2.display(numb2);
    multiply(numb1, numb2);

    return 0;
}