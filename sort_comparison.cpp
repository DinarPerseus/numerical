//Dinar Perseüs
#include<bits/stdc++.h>
using namespace std;

//array a,b for merge sort
int a[200000], b[200000];

//selection sort
void selectionSort(int arr[], int n) {
    int i, j, minIdx;
    for (i = 0; i < n - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])minIdx = j;
        }
        swap(arr[i],arr[minIdx]);
    }
}

//quick sort
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

//merge sort
void merge(int low,int mid,int high){
    int h=low,i=low,j=mid+1;
    while (h<=mid&&j<=high)
    {
        if (a[h]<=a[j])
        {
            b[i]=a[h];h++;
        }else
        {
            b[i]=a[j];j++;
        }
        i++;   
    }
    if (h>mid)for (int k = j; k <= high; k++,i++)b[i]=a[k]; 
    else for (int k = h; k <= mid; k++,i++)b[i]=a[k];

    for (int k = low; k <= high; k++)a[k]=b[k];
}
void mergesort(int low,int high){
    if (low<high)
    {
        int mid=(low+high)/2;
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(low,mid,high);
    } 
}

//heap sort
void heapify(int arr[], int n, int i)
{
	int largest = i; 
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 
	if (l < n && arr[l] > arr[largest])largest = l;
	if (r < n && arr[r] > arr[largest])largest = r;
	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
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


int main(int argc, char const *argv[])
{
    int n;cout<<"Enter the size of array:";cin>>n;
    srand((unsigned) time(NULL));
    //array s for selection
    //array q for quick
    //array h for heap
    int s[n],q[n],h[n];
    for(int i=0; i<n; i++)a[i]=s[i]=q[i]=h[i]=rand()%(int)1e9;

    double selection_exe_time,quick_exe_time,merge_exe_time,heap_exe_time;
    
    clock_t start_time, end_time;
    start_time = clock();  
    selectionSort(s, n);
    end_time = clock();
    selection_exe_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    cout << fixed << setprecision(6)<<"\nselection sort exe Time: "<<selection_exe_time<<" s\n";


    start_time = clock(); 
    quickSort(q,0, n-1);
    end_time = clock();  
    quick_exe_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    cout << fixed << setprecision(6)<<"\nquick sort exe Time: "<<quick_exe_time<<" s\n";

    start_time = clock(); 
    mergesort(0, n-1);
    end_time = clock();  
    merge_exe_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    cout << fixed << setprecision(6)<<"\nmerge sort exe Time: "<<merge_exe_time<<" s\n";

    start_time = clock(); 
    for(int i=n/2 -1;i>=0;i--)heapify(h,n,i);
	heapSort(h, n);
    end_time = clock();  
    heap_exe_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    cout << fixed << setprecision(6)<<"\nheap sort exe Time: "<<heap_exe_time<<" s\n";

    //for (int i = 0; i < n; i++)cout<<s[i]<<" "<<q[i]<<" "<<a[i]<<" "<<h[i]<<endl;
    
    return 0;
}
