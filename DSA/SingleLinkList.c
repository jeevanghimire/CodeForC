#include <stdio.h>

typedef struct
{
    void *next;
    int data;
} Node;


//add the node to the list
// delet the node from list

//insert the node in particular position eg insert (3,4) // insert value 4 in 3rd positional noode

//print the menu

int PrintMenu(){
    printf("1. Add Node\n");
    printf("2. Delete Node\n");
    printf("3. Insert Node\n");
    printf("4. Print List\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    return choice;
}





int main()
{
    PrintMenu();
    return 0;
}