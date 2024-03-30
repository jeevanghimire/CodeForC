#include <stdio.h>

int main(){
  int x = 0, y = 1, z;
  while(1){

	do{
printf("%d\n",x);
	z = x+y;
	x = y;
	y = z;

		
	}while(x<255);		
  }	


  return 0;
}
