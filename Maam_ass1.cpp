#include<bits/stdc++.h>
using namespace std;

int parent(int i,int p[]){
	if(p[i]==-1) return i;
    return parent(p[i],p);
}

void makeunion(int u,int v,int p[]){
	p[u]=v;
}

int main(int argc, char const *argv[])
{
    int n=5,c=0,mincost=0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    int cost[5][5]={{0, 1, 2, 3, 4},
                    {1, 0, 5, 0, 7},
                    {2, 5, 0, 6, 0},
                    {3, 0, 6, 0, 0},
                    {4, 7, 0, 0, 0}};
    int p[n];
    memset(p,-1,n*4);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i<j&&cost[i][j])
            {
                pq.push({cost[i][j],{i,j}});
            }
            
        }
        
    }
    

    while (c!=n-1&&pq.size())
    {
        auto i=pq.top();
        int pu=parent(i.second.first,p);
        if(pu!=parent(i.second.second,p)){
        	c++;
            makeunion(pu,i.second.second,p);
            mincost+=i.first;
        }
        pq.pop();
        

    }
    cout<<mincost;


    return 0;
}
