//Dinar Perseüs
#include<bits/stdc++.h>
using namespace std;

void heapify(int arr1[], int n, int i)
{
	int largest = i; 
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 
	if (l < n && arr1[l] > arr1[largest])largest = l;
	if (r < n && arr1[r] > arr1[largest])largest = r;
	if (largest != i) {
		swap(arr1[i], arr1[largest]);
		heapify(arr1, n, largest);
	}
}

void heapSort(int arr1[],int arr2[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)heapify(arr1, n, i);
	for (int i = n - 1; i >= 0; i--) {
		swap(arr1[0], arr1[i]);
        arr2[n-i-1]=arr1[i];
		heapify(arr1, i, 0);
	}
}

void make_a_list_of_patients(){
    int n;cout<<"Enter the number of patients :";cin>>n;
    int a[n];
    int b[n];
    cout<<"Enter patients ages :";
    for(int i=0; i<n; i++)cin>>a[i];
    heapSort(a,b,n);
    cout<<"The sorted patient list : ";
    for (int i = 0; i < n; i++)cout<<b[i]<<" ";    
    cout<<endl;
}
int main() {
    make_a_list_of_patients();
    return 0;
}
