#include <stdio.h>

struct video{
char title[100];
char formate[200];
};

int main(){
    //printing the size of data type
    printf("size of (int) = %d\n",sizeof(int));
    printf("size of (double) = %d\n",sizeof(double));
    printf("size of (struct) = %d\n\n",sizeof(struct video));
    
    //Now Printing the size of Pointer::

    printf("size of (int) = %d\n",sizeof(int *));
    printf("size of (double) = %d\n",sizeof(double *));
    printf("size of (struct) = %d\n\n",sizeof(struct video *));

    //Printing the size of Void Pointer::

    printf("size of (void Pointer) = %d\n\n",sizeof(void *));

    //creating some variables
    int count = 99;
    struct video volume1= {"Learning C","AV1"};
    //creating a generic pointer::
    void *generic_pointer = NULL;

    //using generic pointer to point the Count::
    generic_pointer = &count;
    printf("count = %d\n\n",*((int *)generic_pointer));
    
    //Now Generic pointer point to struct video adress::

    generic_pointer = &volume1;
    printf("Volume1 = %d\n\n",((struct video *)generic_pointer)->formate);

    

return 0;
}