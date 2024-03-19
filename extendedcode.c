#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_MENU_ITEMS 10
#define NEW_LINE printf("\n");

typedef struct {
  char name[50];
  float price;
} MenuItem;

typedef struct{
  char name[100];
  int age;
  char adress[100];
  int phone;
}Users;
//Function for royalCustomers and their perks
void NewRoyalCustomer();
int TableNumber(){
  int choice;
  char Decision;
  printf("Are you a royal customer?\n");
  printf("1. Yes\n");
  printf("2. No\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);
  int discount = 0;
    //why the program doesn't take any input after this line?
    if (choice == 1) {
      printf("Welcome Royal Customer!\n");
      printf("You have a 10%% discount on your bill!\n");
      NEW_LINE
      NEW_LINE 
      discount = 1;
      return discount;
    }
    if (choice == 2) {
      
      printf("Do you want to be a royal customer?(Y/N)\n");
      scanf(" %c", &Decision); // Add a space before %c to consume the newline character
      if (Decision == 'y' || Decision == 'Y') {
        NewRoyalCustomer();
      }
    }
    scanf("%c", &Decision);
    if(Decision == 'y' || Decision == 'Y')
    {
    NewRoyalCustomer();
    }
    else{  
      printf("Welcome!\n");
      NEW_LINE
      NEW_LINE 
  }
  return 0;
  }


//Incase of new membership of royal customer Take their details
void NewRoyalCustomer(){
  Users users;
   FILE *fptr;
  fptr = fopen("data.txt", "w");
  if (fptr == NULL) {
    printf("Error!");
    exit(1);
  }
  printf("Enter your name: ");
  scanf("%s", users.name);
  fprintf(fptr, "Name: %s\n", users.name);
  printf("Enter your age: ");
  scanf("%d", &users.age);
  fprintf(fptr, "Age: %d\n", users.age);  
  printf("Enter your adress: ");
  scanf("%s", users.adress);
  fprintf(fptr, "Adress: %s\n", users.adress);
  printf("Enter your phone number: ");
  scanf("%d", &users.phone);
  fprintf(fptr, "Phone: %d\n", users.phone);
  printf("Thank you for joining our royal customer program!\n");
}

void inputMenuItems(MenuItem menu[], int numItems) {
  for (int i = 0; i < numItems; i++) {
    printf("Enter the name of menu item %d: \n", i + 1);
    scanf("%s", menu[i].name);
    printf("Enter the price of menu item %d: \n", i + 1);
    scanf("%f", &menu[i].price);
  }
}

void generateBill(MenuItem menu[], int numItems, float *totalBill)
{
  int numOrders;
  printf("\nEnter the number of orders: ");
  scanf("%d", &numOrders);

  for (int i = 0; i < numOrders; i++)
  {
    int orderNumber;
    printf("\nEnter the order number for order %d: ", i + 1);
    scanf("%d", &orderNumber);

    if (orderNumber >= 1 && orderNumber <= numItems)
    {
      *totalBill += menu[orderNumber - 1].price;
    }
    else
    {
      printf("Invalid order number!\n");
      // Retry the current order
    }
  }
}

void printBill(MenuItem menu[], int numItems, float totalBill, int discount)
{
  float dicountAmt = 0;
  printf("**********************************************\n");
  for (int i = 0; i < numItems; i++)
  {
    printf("*\t%d. %s - NRS%.2f\t\t\t*\n", i + 1, menu[i].name, menu[i].price);
  }
  // apply the dicount
  if (discount != 0)
  {
    dicountAmt = totalBill - (totalBill * 0.1);
  }
  printf("\n");
  printf("\n*\tTotal bill: \tNRs %.2f\t\t*\n", totalBill);
  NEW_LINE
  printf("*\t After Discount\t\t\t\t*\n");
  NEW_LINE
  printf("*\tTotal bill: \tNRs %.2f\t\t*\n", dicountAmt);
  printf("**********************************************\n");
}

void printMenu(MenuItem menu[], int numItems)
{
  printf("**********************************************\n");
  for (int i = 0; i < numItems; i++)
  {
    NEW_LINE
    printf("%d. %s - NRS%.2f\n", i + 1, menu[i].name, menu[i].price);
  }
  NEW_LINE
  printf("**********************************************\n");
}

void getUserInfo()
{
  Users users;
  FILE *fptr;
  fptr = fopen("data.txt", "r");
  if (fptr == NULL)
  {
    printf("Error!");
    exit(1);
  }
  fscanf(fptr, "Name: %s\n", users.name);
  fscanf(fptr, "Age: %d\n", &users.age);
  fscanf(fptr, "Adress: %s\n", users.adress);
  fscanf(fptr, "Phone: %d\n", &users.phone);
  printf("Name: %s\n", users.name);
  printf("Age: %d\n", users.age);
  printf("Adress: %s\n", users.adress);
  printf("Phone: %d\n", users.phone);
  fclose(fptr);
}

int main()
{
  MenuItem menu[MAX_MENU_ITEMS];
  int numItems;
  float totalBill = 0.0;
  int discount = 0;
  discount = TableNumber();
  printf("Enter the number of menu items: \n");

  scanf("%d", &numItems);
  if (numItems > MAX_MENU_ITEMS)
  {
    printf("Number of menu items cannot exceed %d\n", MAX_MENU_ITEMS);
    return 1;
  }
  inputMenuItems(menu, numItems);
  printMenu(menu, numItems);

  generateBill(menu, numItems, &totalBill);

  printBill(menu, numItems, totalBill, discount);
  NEW_LINE
  printf("Do you want to see your details?(Y/N)\n");
  char Decision;
  scanf(" %c", &Decision);
  if (Decision == 'y' || Decision == 'Y')
  {
    getUserInfo();
  }
  printf("Do you want to see your bill Menu(Y/N)\n");
  scanf(" %c", &Decision);
  if (Decision == 'y' || Decision == 'Y')
  {
    printMenu(menu, discount);
  }
  else{
    printf("Thank you for visiting our restaurant!\n");
  }

  return 0;
}