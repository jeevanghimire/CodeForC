#include <bits/stdc++.h>
using namespace std;
//MARK: Binary searchf
void targetfound(int si, int en, int arr[], int target)
{
    int targetidx = -1;
    int start = si, end = en;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (arr[mid] == target)
        {
            targetidx = mid;
            break;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    if(arr[targetidx] == target)
    {
    cout << "Target index is: " << targetidx << endl;
    }
    
}
//MARK: Merge sort sorting algorithm
void conqure(int arr[], int si,int mid, int en){

    int merge[en-si+1];
    int idx1= si,idx2= mid+1,x=0;
    while(idx1<=mid && idx2<=en){
        if(arr[idx1]<arr[idx2]){
            merge[x] = arr[idx1];
            x++; idx1++;
        }
        else{
            merge[x] = arr[idx2];
            x++; idx2++;
        }
    }
    while(idx1<=mid){
        merge[x] = arr[idx1];
        x++; idx1++;
    }
    while(idx2<=en){
        merge[x] = arr[idx2];
        x++; idx2++;
    }
    for (int i = 0; i < en-si+1; i++)
    {
        arr[si+i] = merge[i];
    }
    //printing array
    for (int i = 0; i < en-si+1; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    targetfound(si,en, merge, 13);
}
//MARK: Divide function
void divide(int arr[], int si, int en)
{
    if(si>=en){
        return;
    }
    int mid = si + (en - si)/2;
    divide(arr,si,mid);
    divide(arr,mid+1,en);
    conqure(arr,si,mid,en);
    
}
//MARK: Main function
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int sizeofarr = sizeof(arr)/sizeof(arr[0]);
    //calling function
    divide(arr,0,sizeofarr-1);
    cout<<endl;
    


return 0;
}