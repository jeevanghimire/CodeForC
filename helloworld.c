#include <stdio.h>

int main()
{
    // nested for loops with break statement
    // at inner loop
    for (int i = 1; i <= 6; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            if (i <= 4)
            {
                printf("%d ", j);
            }
            else
            {
                // if i > 4 then this innermost loop will
                // break
                break;
            }
        }
        printf("\n");
    }
    return 0;
}