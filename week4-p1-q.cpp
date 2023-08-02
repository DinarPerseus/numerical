#include<bits/stdc++.h>
using namespace std;
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) { 
        if (arr[j] < pivot) {
            i++;
            int t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;
        }
    }
    int t=arr[i + 1];
    arr[i + 1]=arr[high];
    arr[high]=t;
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void find_kth_element(){
    int sz;printf("Enter the size of array:");scanf("%d", &sz);
    int arr[sz];
    printf("Enter elements:");
    for(int i=0; i<sz; i++)cin>>arr[i];  
    int k;cout<<"Enter the value of k: ";cin>>k;
    if (sz<k) cout<<"your array is too small to find the "<<k<<"th element";
    else cout<<"the "<<k<<"th element is:"<<arr[sz-k];

}
int main() {
    find_kth_element();
    return 0;
}
