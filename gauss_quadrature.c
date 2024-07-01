// Integration by Gauss quadrature

#include <stdio.h>
#include <math.h>
// R=6
// q=(6+R)/20 => q=0.6
#define f(x) (0.6 + x * x * cos(0.6 * x)) / (sqrt(1 + x + sinh(x + 1)))
int main()
{
    int i;
    float a, b, xi, fi, c, sum = 0, intg;
    float t[6] = {-0.932470, -0.661209, -0.238619, 0.238619, 0.661209, 0.932470};
    float k[6] = {0.171324, 0.360762, 0.467914, 0.467914, 0.360762, 0.171324};
    printf("Enter lower limit of integration: ");
    scanf("%f", &a);
    printf("Enter upper limit of integration: ");
    scanf("%f", &b);
    printf("\n\n t[i]\t\t x[i]\t\t f[i]\t\t k[i]\t\t k[i]*f[i]");
    for (i = 0; i <= 5; i++)
    {
        xi = ((b + a) + (b - a) * t[i]) / 2;
        fi = f(xi);
        c = k[i] * fi;
        sum = sum + c;
        printf("\n\n %f\t %f \t%f \t%f \t%f", t[i], xi, fi, k[i], c);
    }
    intg = ((b - a) * sum) / 2;
    printf("\n\n Value of the integral = %f", intg);
    return 0;
}