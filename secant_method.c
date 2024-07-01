// secant method

#include <stdio.h>
#include <math.h>
// R=6
// P=(1+R)/20=.35
#define f(x) (pow(x, x) + (0.35 * log(1 + x * x)) / log(10) - 3.4)
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
            a = x;
            n = n + 1;
        } while (fabs(f(x)) > .000001 && n < 30);
        if (fabs(f(x)) > 0.00001)
            printf("\n\n The root is %f", x);
        else
            printf("\n\n The iteration does not converge");
    }
    else
        printf("\n\n Change the values of a and b");

    return 0;
}
