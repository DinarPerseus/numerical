//Dinar Perseüs
#include <bits/stdc++.h>
using namespace std;

int n=69-61;
int j;
//why the size is 69 ?
//Because, I love it ....
char c[69][69];
bool G[69][69];
int x[69];



void NextValue(int k){
    while (true)
    {
        x[k]=(x[k]+1)%(n+1);
        if (x[k]==0)
        {
            return;
        }
        if (G[x[k-1]][x[k]]!=0)
        {
            for (j = 1; j <= k-1; j++)
            {
                if (x[j]==x[k])
                {
                    break;
                }
                
            }

            if (j==k)
            {
                if (k<n||(k==n&&G[x[n]][x[1]]!=0))
                {
                    return;
                }
                
            }
            
            
        }
        
        
    }
    
}



void Hamiltonian(int k){
    
    while (true)
    { 
        
        NextValue(k);
        if (x[k]==0)
        {
            return;
        }
        if (k==n)
        {
            for(int i=1;i<=n ;i++ )cout<<x[i]<<" ";
            cout<<endl;
        }else
        {
            Hamiltonian(k+1);
        }
        
        
        
    }
    
}





int main(int argc, char const *argv[])
{
    G[1][2]=G[2][1]=G[1][3]=G[3][1]=G[2][3]=G[3][2]=G[3][4]=G[4][3]=1;
    G[1][7]=G[7][1]=G[2][8]=G[8][2]=G[3][6]=G[6][3]=G[5][4]=G[4][5]=1;
    G[8][7]=G[7][8]=G[7][6]=G[6][7]=G[6][5]=G[5][6]=x[1]=1;


    for (int i = 0; i < 69; i++)for (int j = 0; j < 69; j++)c[i][j]=69-37;
    for (int i = 0; i*8+8 < 69; i++)
    {
        c[i*8+0][1]=c[i*8+0][2]=c[i*8+0][3]=c[i*8+1][0]=c[i*8+2][0]=c[i*8+3][1]=c[i*8+3][2]=c[i*8+3][3]=69-34;
        c[i*8+4][0]=c[i*8+4][4]=c[i*8+5][0]=c[i*8+5][4]=c[i*8+6][1]=c[i*8+6][2]=c[i*8+6][3]=69-34;
        c[i*8+0][8]=c[i*8+0][9]=c[i*8+0][10]=c[i*8+1][11]=c[i*8+2][11]=c[i*8+1][7]=c[i*8+2][7]=69-34;
        c[i*8+3][8]=c[i*8+3][9]=c[i*8+3][10]=c[i*8+4][11]=c[i*8+5][11]=c[i*8+6][8]=c[i*8+6][9]=c[i*8+6][10]=69-34;
    
    }
    



    for (int i = 0; i < 69; i++)
    {
        for (int j = 0; j < 96-69; j++)
        {
            cout<<c[i][j];
        }
        cout<<endl;
        
    }
    
    
    Hamiltonian(2); 
    return 0;
}
