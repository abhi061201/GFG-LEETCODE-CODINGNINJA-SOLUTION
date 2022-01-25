#include <iostream>

using namespace std;

void heapify(int i, int arr[], int n)
{
    int largest = i;
    if (2 * i + 1 < n && arr[largest] < arr[2 * i + 1])
        largest = 2 * i + 1;
    if (2 * i + 2 < n && arr[largest] < arr[2 * i + 2])
        largest = 2 * i + 2;
    if (largest != i)
    {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        heapify(largest, arr, n);
    }
}
void heapsort(int arr[], int n)
{

    for (int i = n / 2; i >= 0; i--)
    {
        heapify(i, arr, n);
    }
    for(int i=0 ;i<n ;i++){
        int temp= arr[0];
        arr[0]= arr[n-i-1];
        arr[n-i-1]= temp;
        heapify(0,arr,n-i-1);
    }

}

int main()
{

    int arr[] = {2, 3, 5, 1, 6, 4, 3, 8, 2, 5};
    heapsort(arr, 10);

    for(auto it : arr)cout<<it<<" , ";
     

    return 0;
}
