// Regula-Falsi

#include <stdio.h>
#include <math.h>
// R=16
// P=1.5+R/20=2.3
#define f(x) (sin(2.3 * x) - 2.3 * x * x * x - x + 0.5)
int main()
{
    int n = 0;
    float a, b, x;
    printf("\n\n Enter the value of a and b: ");
    scanf("%f%f", &a, &b);
    if (f(a) * f(b) < 0)
    {
        printf("\n n a b x f(x)\n");
        do
        {
            x = a - ((b - a) / (f(b) - f(a))) * f(a);
            printf("\n %2d %f %f %f %f ", n, a, b, x, f(x));
            if (f(a) * f(x) < 0)
                b = x;
            else
                a = x;
            n = n + 1;
        } while (fabs(f(x)) > .000001 && n < 30);
        printf("\n\n The root is %f", x);
    }
    else
        printf("\n Change the values of a and b");
    return 0;
}