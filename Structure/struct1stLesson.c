// personal Info struct first name last name age gender 


#include <stdio.h>

struct PersonalInfo{
  char FirstName[50],SureName[50];
  int age;
  char gender[10];

};

int ReturnStruct(struct PersonalInfo a[]){
  return 1;
}


int main(){
struct PersonalInfo Momentum[50];
for(int i =0;i<50;i++){
scanf("%s",Momentum[i].FirstName);
scanf("%s",Momentum.SureName);
scanf("%s",Momentum.gender);
scanf("%d",&Momentum.age);

}

printf("%s\n",Momentum.FirstName);
printf("%s\n",Momentum.SureName);
printf("%s\n",Momentum.gender);
printf("%d\n",Momentum.age);



















  // for(int i =0;i<n;i++){
  //   printf("Enter your First Name:\n");
  //   scanf("%s",Person[i].FirstName);
  //   printf("Enter your Sure Name:\n");
  //   scanf("%s",Person[i].SureName);
  //   printf("Enter your Age\n");
  //   scanf("%d",&Person[i].age);
  //   printf("Enter your Gender\n");
  //   scanf("%s",Person[i].gender);
  // }

  // for(int i =0;i<n;i++){
  //   printf("**********************************************\n");
  //   printf("First Name: %s\n",Person[i].FirstName);
  //   printf("Sure Name: %s\n",Person[i].SureName);
  //   printf("Age: %d\n",Person[i].age);
  //   printf("Gender: %s \n",Person[i].gender);
  //   printf("**********************************************\n");

  // }


  return 0;
}