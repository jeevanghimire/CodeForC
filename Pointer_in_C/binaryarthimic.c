int addition(int a,int b)
{
    int c;
    while(b!=0)
    {
        c=(a&b)<<1;
        a=a^b;
        b=c;
    }
    return a;
}
int subtraction(int a,int b)
{
    int carry;
    b=addition(~b,1);
    while(b!=0)
    {
    carry=(a&b)<<1;
    a=a^b;
    b=carry;
    }
    return a;
}
int main()
{
    int n1,n2;
    int binAdd,binSub;
    printf("Input first integer value:");
    scanf("%d",&n1);
    printf("Input second integer value:");
    scanf("%d",&n2);
    binAdd=addition(n1,n2);
    binSub=subtraction(n1,n2);
    printf("Binary addition:%d\n",binAdd);
    printf("Binary Subtraction:%d\n",binSub);
    return 0;
}