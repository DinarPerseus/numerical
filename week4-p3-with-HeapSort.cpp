//Dinar Perseüs
#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)
{
	int smalest = i; 
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 
	if (l < n && arr[l] < arr[smalest])smalest = l;
	if (r < n && arr[r] < arr[smalest])smalest = r;
	if (smalest != i) {
		swap(arr[i], arr[smalest]);
		heapify(arr, n, smalest);
	}
}

void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

int main() {
    int n;cout<<"Enter the size of emergency room :";cin>>n;
    int a[n];
    srand((unsigned) time(NULL));
    for(int i=0; i<n; i++)a[i]=rand()%(int)110;
    
    heapSort(a,n);
    cout<<"The sorted patient list : ";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
        
    }
    cout<<endl;
    
    return 0;

}
