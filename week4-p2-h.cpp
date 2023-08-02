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
void find_kth_element(){
    int x,c=0,i=0;
    int k;cout<<"Enter the value of k: ";cin>>k;
    int a[k+1];
    cout<<"NB :: Enter as many as elements you want ..";
    cout<<"\nand finally enter a single dot (.) to exit .."<<endl;
    while (cin>>x)
    {
        a[i++]=x;c++;
        if (c==k)heapSort(a,k);
        else if (c>k)
        {
            heapSort(a,k+1);
            i--;
        }   
    }
    if (c<k) cout<<"your array is too small to find the "<<k<<"th element";
    else cout<<"the "<<k<<"th element is:"<<a[k-1];    
}
int main() {
    find_kth_element();
    return 0;
}
