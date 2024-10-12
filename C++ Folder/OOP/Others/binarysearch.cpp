//writing a function to do binary search

#include <iostream>
using namespace std;

// Function to find target element in the array
void targetSearch(int arr[], int target, int n) {
    int start = 0, end = n - 1;
    int mid = start + (end - start) / 2;

    while (start <= end) {
        mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            cout << "Target found at index: " << mid << endl;
            return;
        } else if (arr[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    cout << "Target not found in the array" << endl;
}



int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;
    targetSearch(arr, target, n);
    

    return 0;
}