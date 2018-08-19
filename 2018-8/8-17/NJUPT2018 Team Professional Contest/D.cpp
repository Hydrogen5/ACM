//Roots Intervals 
#include <iostream>
#include <cstdio>
#include <cmath>
double f(double x)
{
    return tan(sin(x)) - sin(tan(x)) + cos(x) * cos(x) * cos(x) * cos(x) * cos(x) - 0.5;
}
int main()
{
    double a,b,nb;
    while(scanf("%lf %lf %lf",&a,&b,&nb)!=EOF)
    {
        double dist=(b-a)/nb;
        double l = a;
        double r=a+dist;
        int ans = 0;
        while(r<=b+0.0000000001)
        {
            if(f(l)*f(r)<=0)
                ans++;
            l=r;
            r += dist;
        }
        printf("%d\n", ans);
    }

}