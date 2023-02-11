//Dinar Perseüs
//secant
#include<bits/stdc++.h>
using namespace std;
double f(double x){
    return (double)(3*x*x-4*x);
}

int main(int argc, char const *argv[])
{
    double a=1,b=2,c,fa,fb;
    fa=f(a);
    fb=f(b);
    do
    {
        c=b-(b-a)/(fb-fa)*fb;
        a=b;
        b=c;
        fa=fb;
        fb=f(b);
    }while (fabs(fa)>0.0001);
    printf("%.6f\n",c);
    return 0;
}
