// Dinar Perseüs 2.0
#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template<class T> using  oset= tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;



const int N=600005;
 
//segment tree 
int seg[N];
 
//build segment tree 
void build(int p, int l, int r){
    //lazy[p]=0;

    if(l==r){

        seg[p]=0;
        return;
    }

    int mid=(l+r)>>1;
    build(2*p,  l, mid);
    build(2*p+1,  mid+1, r);
    seg[p]=seg[2*p]+seg[2*p+1];
 
}
 
 
//update segment
void update(int p, int l, int r, int s, int e){
    if(s>r||e<l) return;
    if(s<=l&&r<=e) {
        //lazy[p]=lazy[p]+v;
        seg[p]++;
        return;
    }
    
    //propagate(p,l,r);
    
    int mid=(l+r)>>1;
    update(2*p, l, mid, s, e);
    update(2*p+1, mid+1, r, s, e);
    seg[p]=(seg[2*p]+seg[2*p+1]);
    
}
 
//query segment tree
int query(int p, int l, int r, int s, int e){
    if(s>r||e<l) return 0;
    if(s<=l&&r<=e) return seg[p];
    
    //propagate(p,l,r);
    
    int mid=(l+r)>>1;
    int x=query(2*p, l, mid, s, e);
    int y=query(2*p+1, mid+1, r, s, e);
    return (x+y);
 
 
}



void solve(int t){
    cout<<"Case "<<t<<": \n";
    int n,m;
    cin>>n>>m;
    oset<int> ys;
    ys.insert(-1);
    vector<pair<pair<int,int>,int>> v;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        ys.insert(y);
        v.push_back({{x,0},y});
        
    }
    
    
    vector<pair<int,int>> y(m);
    vector<int> pp(m);
    for(int i=0;i<m;i++){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        v.push_back({{x1,-1},i});
        v.push_back({{x2,1},i});
        y[i]={y1,y2};
        ys.insert(y1);
        ys.insert(y2);
    }
    
    
    
    sort(v.begin(),v.end());
    
    int k=ys.size();
    build(1,1,k);
    for(int i=0;i<v.size();i++){
        if(v[i].first.second==0){
            
            int s=ys.order_of_key(v[i].second);
            update(1,1,k,s,s);
        
        }
        else if(v[i].first.second==-1){
            
            int s=v[i].second;
            pp[s]=query(1,1,k,ys.order_of_key(y[s].first), ys.order_of_key(y[s].second));
        
        
        }else{
            
            int s=v[i].second;
            pp[s]=query(1,1,k,ys.order_of_key(y[s].first), ys.order_of_key(y[s].second))-pp[s];
        
        }
    
    }
    
    for(auto x:pp)cout<<x<<'\n';
    
    
    
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