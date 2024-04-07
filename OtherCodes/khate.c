#include <stdio.h>
int main()
{
  struct student
{
  char name[30];
  int rollno;
  float marks;
  char remarks;
};
  struct student n;
  printf("enter your name =\n");
  scanf("%s", n.name);
  printf(" \nenter your roll no: \n");
  scanf("%d", &n.rollno);
  printf("\nenter marks = \n");
  scanf("%f", &n.marks);
  printf("\n Enter the Remarks: \n");
  scanf(" %c", &n.remarks);
  printf("\n.......................................................................\n");
  printf("\nname\tRoll no \t marks\t remarks\n");
  printf("\n %s \t %d \t %f \t %c\n", n.name, n.rollno, n.marks, n.remarks);
  return 0;
}