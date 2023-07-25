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

    cout<<"NB :: Enter as many as elements you want ..\nafter this enter your required position you want to find ..\nand finally enter a single dot (.) to exit .."<<endl;

    int x,i=0;
    while (cin>>x)
    {
        a[i++]=x;
    }

    mergesort(0, i-2);
    int k=a[i-1];
    cout<<"\n"<<k<<" NO largest elements is: "<<a[k-1]<<endl;
    return 0;
    
}
