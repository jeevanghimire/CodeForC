/*
    Selection Sort
    Time Complexity: O(n^2) best case: O(n^2), worst case, average case
    Space Complexity: O(1)
        [1] Input the number of elements in the array
        for eg [3,7,2,55,23,1,2] n = 7
        now at first we will select the minimum element from arry to swap it with the first element
        then we will select the minimum element from the remaining array to swap it with the second element
        and so on
        [2] Input the elements of the array
        [3] Call the selectionSort function
        [4] Print the sorted array
        [5] Exit
        
*/
#include <stdio.h>
// function that sort the array using selection sort
void selectionSort(int arr[], int n)
{
    for (int i = 0;i<n-1;i++){
        int min = i;
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[min]) min = j;
        }
        if(min!=i){
            //swapping here if min ! = i
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    //printing the sorted array
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}


int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n);
return 0;
}