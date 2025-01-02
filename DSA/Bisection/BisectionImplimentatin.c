// implement bisection method to find the root of the equation f(x)=x^3-2x-5

#include <stdio.h>

double f(double x)
{
    return x * x * x - 2 * x - 5;
}

void bisection(double a, double b)
{
    if (f(a) * f(b) >= 0)
    {
        printf("You have not assumed right a and b\n");
        return;
    }

    double c = a;
    for (; (b - a) >= 0.01;)
    {
        c = (a + b) / 2;
        if (f(c) == 0.0)
        {
            break;
        }
        else if (f(c) * f(a) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }
    printf("The value of root is : %lf\n", c);
}

int main()
{
    double a = 1, b = 3;
    bisection(a, b);
    return 0;
}