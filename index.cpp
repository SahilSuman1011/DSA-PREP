#include <bits/stdc++.h>
using namespace std;

/* Function to print the second largest elements */
void print2largest(int arr[], int arr_size)
{
    // sort the array in descending order
    sort(arr, arr + arr_size, greater<int>());
    // start from second element as first
    // element is the largest
    for (int i = 1; i < arr_size; i++) {
        // if the element is not equal to largest element
        if (arr[i] != arr[0]) {
            printf("The second largest element is %d\n",
                   arr[i]);
            return;
        }
    }
    printf("There is no second largest element\n");
}

/* Driver program to test above function */
int main()
{
    int arr[] = { 12, 35, 1, 10, 34, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    print2largest(arr, n);
    return 0;
}