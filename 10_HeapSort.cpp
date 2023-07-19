#include <bits/stdc++.h>
using namespace std;
  
void printArray(int arr[], int n) 
{
    for (int i=0; i<n; i++)
        cout <<arr[i]<< " ";

    cout <<"\n";
}
  
void heapify(int arr[], int n, int i) 
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
        
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);

        cout<<"\nFrom Heapify :- ";
        printArray(arr, n);
    }
}
  
void heapSort(int arr[], int n) {
  
    cout<<"\n Build Heap :- ";
    for (int i = n/2-1; i>=0; i--)
        heapify(arr, n, i);
    
    cout<<"\n Heap Sort :- ";
    cout <<"\n Heap is :- ";
        printArray(arr, n);

    //Heap sort
    for (int i=n-1; i>=0; i--) 
    {
        swap(arr[0], arr[i]);
    
        cout <<"\n"<<i<<"th Pass :- ";
        printArray(arr, n);
        
        heapify(arr, i, 0);
    
        cout <<"\n"<<i<<"th Pass After Heapiy :- ";
        printArray(arr, n);
    }
}
  
int main()
{
    int arr[] = {1, 12, 9, 5, 6, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout <<"Array Before Sorting :-\n";
    printArray(arr, n);
    
    heapSort(arr, n);
  
    cout <<"Array AFter Sorting is :-\n";
    printArray(arr, n);
}