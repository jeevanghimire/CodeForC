#include <iostream>
#include <cmath>
using namespace std;
int funcfloor(double num)
{
    return static_cast<int>(floor(num));
}

int celifunc(double num)
{
    return static_cast<int>(ceil(num));
}

int main()
{
    using namespace std;
    double a = 5.3, b = 6.7, c = 8.3;
    cout << "Floor function " << a << " = " << funcfloor(a) << endl;
    cout << "Floor function " << b << " = " << funcfloor(b) << endl;
    cout << "Floor function " << c << " = " << funcfloor(c) << endl;
    cout << "Ceiling function " << a << " = " << celifunc(a) << endl;
    cout << "Ceiling function " << b << " = " << celifunc(b) << endl;
    cout << "Ceiling function " << c << " = " << celifunc(c) << endl;
    return 0;
}
