#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    string s1,s2,s="";
    cin>>s1>>s2;
    int m=s1.size(),n=s2.size();
    int dp[m+1][n+1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i==0||j==0)
            {
                dp[i][j]=0;
            }else if (s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
            
        }
        
    }

    int i=m,j=n;
    while (i>0&&j>0)
    {
        if (s1[i-1]==s2[j-1])
        {
            s+=s1[i-1];
            i--;j--;
        }else if(dp[i][j-1]>dp[i-1][j])
        {
            j--;
        }else
        {
            i--;
        }
  
    }
    reverse(s.begin(),s.end());
    cout<<"The size of the LCS is: "<<dp[m][n]<<"\nLCS: "<<s<<'\n';
    return 0;
}
