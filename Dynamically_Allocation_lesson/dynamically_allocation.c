#include <stdio.h>
#include <stdlib.h>
int main(){
    int numb;
    printf("Enter the number:\n");
    scanf("%d",&numb);

    int *arr = (int *)calloc(numb,sizeof(int));

    if (arr==NULL){
        printf("The Allocation was UnSucessfull\n\n");
        return 1;
    }


    if (arr != NULL){
        free(arr);
    }
return 0;
}