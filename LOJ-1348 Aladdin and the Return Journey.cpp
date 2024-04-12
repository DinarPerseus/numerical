// Dinar Perseüs 2.0
#include <bits/stdc++.h>
using namespace std;

int level[30000];
int jump[30000][15];
int total[30000];

void dfs(int u,int p,int l, vector<int> tree[], vector<int> s[]){
    level[u]=l;
    s[l].push_back(u);
    for(auto v:tree[u]){
        if(v!=p){
            jump[v][0]=u;
            dfs(v,u,l+1,tree,s);
        }
    }

}

void build_lift(int n){

    for(int i=1;i<15;i++){
        for(int j=0;j<n;j++){
            jump[j][i]=jump[jump[j][i-1]][i-1];
        }
    }
    
}


void update_bit(int node, int v, int n,vector<int> s[]){
    if(node<n){
        total[node]+=v;
        int t=level[node];
        int nt=t+(t&(-t));
        if(nt>n) return;
        int def=t&(-t);
        for(auto next_node:s[nt]){
            int k=0;
            while((1<<(k+1))<=def){
                k++;
            }
            if(jump[next_node][k]==node){
                update_bit(next_node,v,n,s);
            }
        
        }
    
    }


}


int query_bit(int node){
    
    int t=level[node];
    int def=t&(-t);
    int k=0;
    while((1<<(k+1))<=def){
                k++;
    }
    if(t-def==0) return total[node];
    else return total[node]+query_bit(jump[node][k]);
}


void build_bit(int n, vector<int> &g,vector<int> s[]){
    for(int i=0;i<n;i++){
        update_bit(i,g[i],n,s);
    }

}

int lca(int u,int v){
    if(level[u]>level[v]) swap(u,v);
    int def=level[v]- level[u];
    int k=0;
    while(def!=0){
        if(def&1){
            v=jump[v][k];
        }
        k++;
        def>>=1;
        
    }
    if(u==v) return u;
    
    k=14;
    while(k>=0){
        if(jump[u][k]!=jump[v][k]){
            u=jump[u][k];
            v=jump[v][k];
        }
        k--;
    }
    //cout<<jump[v][0];
    return jump[v][0];

}



void solve(int t){
    cout<<"Case "<<t<<": \n";
    int n;
    cin>>n;
    
    vector<int> g(n);
    for(int i=0;i<n;i++){
        total[i]=0;
        cin>>g[i];
    }
    vector<int> tree[n];
    vector<int> s[n+1];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    dfs(0,0,1,tree,s);
    build_lift(n);
    build_bit(n,g,s);
    
    int i=2,j=3;
    
    
    //cout<<query_bit(i)<<'\n'<<query_bit(lca(i,j))<<'\n'<<query_bit(j)<<'\n';
            
            
            
    /*
    for(int i=0;i<n;i++){
        cout<<total[i]<<' ';
    
    }
    */
    
    
    
    int q;
    cin>>q;
    while(q--){
        int op;
        cin>>op;
        if(op==0){
            int i,j;
            cin>>i>>j;
            int l=lca(i,j);
            cout<<query_bit(i)-2*query_bit(l)+query_bit(j)+g[l]<<'\n';
            
            
        
        }else{
            int i,j;
            cin>>i>>j;
            update_bit(i,-1*g[i],n,s);
            g[i]=j;
            update_bit(i,j,n,s);
        
        }
    
    
    }
    
    
    
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++)solve(i);
   

    return 0;
}