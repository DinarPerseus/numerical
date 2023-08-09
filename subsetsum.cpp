//Dinar Perseüs
#include<bits/stdc++.h>
using namespace std;


int n=6,m=30;
int w[7]={0,5,10,12,13,15,18};
bool x[7]={0};

void sumofsub(int s,int k,int r){
    x[k]=1;
    if (s+w[k]==m)
    {
        for (int i = 1; i <= k; i++)
        {
            cout<<x[i]<<" ";
        }
        cout<<"\n";
        
    }else if (s+w[k]+w[k+1]<=m)
    {
        sumofsub(s+w[k],k+1,r-w[k]);
    }
    if (s+r-w[k]>=m&&s+w[k+1]<=m)
    {
        x[k]=0;
        sumofsub(s,k+1,r-w[k]);

    }
     
}


int main(){
    int r=0,s=0,k=1;
    for (int i = 1; i <= n; i++)r+=w[i];
    sumofsub(s,k,r);
    return 0;
}
