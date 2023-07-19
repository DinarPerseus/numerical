#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int b[10000000];

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
    if (h>mid)
    {
        for (int k = j; k <= high; k++,i++)
        {
            b[i]=a[k];
        }
        
    }else
    {
        for (int k = h; k <= mid; k++,i++)
        {
            b[i]=a[k];
        }
    } 
    for (int k = low; k <= high; k++)
    {
        a[k]=b[k];
    }
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

int main() {
    int n;
    cout<<"Enter the size of array:";cin>>n;
    srand((unsigned) time(NULL));
    for(int i=0; i<n; i++)a[i]=rand()%(int)1e9;
    //for(int i=0;i<n;i++)cout<<a[i]<<" ";
    clock_t start_time, end_time;
    double execution_time;
    start_time = clock();  
    mergesort(0, n-1);
    end_time = clock(); 
    execution_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    //for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout << fixed << setprecision(6)<<"\nExe Time: "<<execution_time<<" seconds\n";
    return 0;
}
