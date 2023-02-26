//Dinar Perseüs
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,i;
    cout<<"Enter the number of points:";
    cin>>n;i=n;
    double x,y,sx=0,sy=0,sxx=0,sxy=0,a,b;
    while(i--){
        cin>>x>>y;sx+=x;sy+=y;
        sxy+=x*y;sxx+=x*x;
    }
    b=(n*sxy-sx*sy)/(n*sxx-sx*sx);
    a=(sy/n)-b*(sx/n);
    cout<<"a : "<<a<<"\nb : "<<b<<"\n";
    return 0;
}
