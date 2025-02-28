#include <stdio.h>

//function to insert element in array
void insert(int arr[], int n){
    arr[1] = arr[n];
    n = n-1;
    int i = 1,j;
    while(i<n){
        int left = arr[2*i];
        int right = arr[2*i+1];
        int max = arr[i];
        if(left>max){
            max = left;
            j = 2*i;
        }
        if(right>max){
            max = right;
            j = 2*i+1;
        }
        if(max == arr[i]) break;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i = j;
    }
}
//function to delet the elements in heap array
    void deleteHeap(int arr[],int n){
        arr[1] = arr[n];
        n = n-1;
        int i = 1,j;
        while(i<n){
            //checking if there is left element is present or not
            if(2*i>n) break;
            int left = arr[2*i];
            //checking if there is right element is present or not
            if(2*i+1>n){
                if(arr[i]<left){
                    int temp = arr[i];
                    arr[i] = arr[2*i];
                    arr[2*i] = temp;
                }
                break;
            }
            int right = arr[2*i+1];
            int large = left > right ? 2 * i : 2 * i + 1;
            if(arr[i]<arr[large]){
                int temp = arr[i];
                arr[i] = arr[large];
                arr[large] = temp;
                i = large;
            }
            else break;
        }
    }



int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n+1];
    printf("Enter the elements of the array: ");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    //inserting the elements in the heap
    for(int i = 2;i<=n;i++){
        int j = i;
        while(j>1){
            int parent = j/2;
            if(arr[j]>arr[parent]){
                int temp = arr[j];
                arr[j] = arr[parent];
                arr[parent] = temp;
                j = parent;
            }
            else break;
        }
    }
    //deleting the elements from the heap
    for(int i = n;i>1;i--){
        int temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;
        deleteHeap(arr,i-1);
    }
    //printing the sorted array
    for(int i = 1;i<=n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
return 0;
}