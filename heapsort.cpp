//Dinar Perseüs
#include<bits/stdc++.h>
using namespace std;
int x;
void insert(int a[],int n){
    int i=n, item=a[n];
    while ((i>1)&&(a[i/2]<item))
    {
        a[i]=a[i/2];
        i=i/2;
    }
    a[i]=item;

}

void adjust(int a[],int i,int n){
    int j=2*i,item=a[i];
    while (j<=n)
    {
        if ((j<n)&&(a[j]<a[j+1]))j++;
        if (item>=a[j])break;
        a[j/2]=a[j];
        j=2*j; 

    }
    a[j/2]=item;
    
}

void delmax(int a[],int n,int &x){
    if(n==0)return;
    x=a[1];
    a[1]=a[n];
    adjust(a,1,n-1);
}

void heapsort(int a[], int n){
    for (int i = 1; i <= n; i++)insert(a,i);
    for (int i = n; i >= 1; i--)
    {
        delmax(a,i,x);a[i]=x;
       
    }
}


int main() {
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int a[n+1];
    srand((unsigned) time(NULL));
    for(int i=1; i<=n; i++)a[i]=rand()%(int)1e9;

    clock_t start_time, end_time;
    double execution_time;
    start_time = clock();  
    heapsort(a, n);
    end_time = clock(); 
    execution_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    //for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    cout << fixed << setprecision(6)<<"\nExe Time: "<<execution_time<<" seconds\n";
    return 0;
}
