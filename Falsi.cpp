//Dinar Perseüs
//Falsi Method
#include<bits/stdc++.h>
using namespace std;
double f(double x){
    return (double)(3*x*x-4*x);
}
int main(int argc, char const *argv[])
{
    double a=1,b=2,c,fa,fb,fc;
    fa=f(a);
    fb=f(b);
    do
    {
        c=(a*fb-b*fa)/(fb-fa);
        fc=f(c);
        if (fa*fc<0)
        {
            fb=fc;
            b=c;
        }else
        {
            fa=fc;
            a=c;
        }
    } while (fabs(fc)>0.0001);
    printf("%.6f\n",c);
    return 0;
}
