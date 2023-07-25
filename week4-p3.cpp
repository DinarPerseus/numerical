//Dinar Perseüs
#include<bits/stdc++.h>
using namespace std;
int a[1000000], b[1000000];
void merge(int low,int mid,int high){
    int h=low,i=low,j=mid+1;
    while (h<=mid&&j<=high)
    {
        if (a[h]>=a[j])
        {
            b[i]=a[h];
            h++;
        }else
        {
            b[i]=a[j];
            j++;
        }
        i++;   
    }
    if (h>mid)
    {
        for (int k = j; k <= high; k++,i++)b[i]=a[k]; 
    }else
    {
        for (int k = h; k <= mid; k++,i++)b[i]=a[k];
    } 
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
int main() {
    int n;cout<<"Enter the size of emergency room :";cin>>n;
    srand((unsigned) time(NULL));
    for(int i=0; i<n; i++)a[i]=rand()%(int)110;
    mergesort(0, n-1);

    cout<<"The sorted patient list : ";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
        
    }
    cout<<endl;
    
    return 0;

}
