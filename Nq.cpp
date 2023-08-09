//Dinar Perseüs
#include<bits/stdc++.h>
using namespace std;

int size;
int x[100];
int cnt=0;




bool Place(int k,int i){
	for(int j=1;j<=k-1;j++){
    	if(x[j]==i || abs(x[j]-i)==abs(j-k))
        	return false;
    }
    return true;	
}

void NQueens(int k,int n){
	for(int i=1;i<=n;i++){
    	if(Place(k,i)){
            
        	x[k]=i;
            if(k==n){
                cnt++;
                cout<<cnt<<" No. way :";
                for (int j = 1; j <=n; j++)
                {
                    cout<<x[j]<<" ";
                }
                cout<<"\n";
                
            }
            else NQueens(k+1,n);
        }
    }
}


int main(){
    cin>>size;
	NQueens(1,size);
return 0;
}
