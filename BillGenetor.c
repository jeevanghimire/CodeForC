#include <stdio.h>

#define MAX_MENU_ITEMS 10

typedef struct {
  char name[50];
  float price;
} MenuItem;

int main() {
  MenuItem menu[MAX_MENU_ITEMS];
  int numItems;
  float totalBill = 0.0;
  printf("Enter the number of menu items: \n");
  scanf("%d", &numItems);
  // Input menu items
  for (int i = 0; i < numItems; i++) {
    printf("Enter the name of menu item %d: \n", i + 1);
    scanf("%s", menu[i].name);
    printf("Enter the price of menu item %d: \n", i + 1);
    scanf("%f", &menu[i].price);
  }

  // Generate bill
  printf("\nMenu:\n");
  for (int i = 0; i < numItems; i++) {
    printf("%d. %s - NRS%.2f\n", i + 1, menu[i].name, menu[i].price);
  }

  int numOrders;
  printf("\nEnter the number of orders: ");
  scanf("%d", &numOrders);

  for (int i = 0; i < numOrders; i++) {
    int orderNumber;
    printf("\nEnter the order number for order %d: ", i + 1);
    scanf("%d", &orderNumber);

    if (orderNumber >= 1 && orderNumber <= numItems) {
      totalBill += menu[orderNumber - 1].price;
    } else {
      printf("Invalid order number!\n");
      // Retry the current order
    }
  }
  printf("*************************************\n");
  for (int i=0;i<numItems;i++){
    printf("*\t%d. %s - NRS%.2f\t*\n", i + 1, menu[i].name, menu[i].price);
  }
  printf("\n");
  printf("\n*\tTotal bill: NRs %.2f\t*\n", totalBill);
  printf("*************************************\n");

  return 0;
}