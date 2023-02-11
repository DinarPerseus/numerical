//Dinar Perseüs
//Newton Raphson
#include<bits/stdc++.h>
using namespace std;
double f(double x){
    return (double)(3*x*x-4*x);
}
double df(double x){
    return (double)(6*x-4);
}
int main(int argc, char const *argv[])
{
    double a=2,c,fa,dfa;
    do
    {
        fa=f(a);
        dfa=df(a);
        c=a-(fa/dfa);
        a=c;
    }while (fabs(fa)>0.0001);
    printf("%.6f\n",a);
    return 0;
}
