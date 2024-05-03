#include <stdio.h>
int main()
{
    int i,n=2,count;
    while (1){
        int t = 0;
        for(int i = 1;i<=n;i++){
            if(n%i==0){
                t++;
            }
        }
        if(t==2){
            printf("%d \n",n);
            count++;
        }
        n++;
        if(count== 50){
            break;
        }
        
    }
return 0;
}