#include <stdio.h>
// r=6
// x=0.4+r/100 => x=0.46
int main()
{
    float x[10], y[10], p[10], k, f1 = 1.0, f2 = 0.0, f;
    int n, i, j = 1;
    printf("\n Enter the number of observations : \n");
    scanf("%d", &n);
    printf("\n Enter the different values of x: \n");
    for (i = 1; i <= n; i++)
        scanf("%f", &x[i]);
    printf("\n Enter the corresponding values of y: \n");
    for (i = 1; i <= n; i++)
        scanf("%f", &y[i]);
    f = y[1];
    printf("\n Enter the value of 'k' in f(k) you want to evaluate: \n");
    scanf("%f", &k);
    do
    {
        for (i = 1; i <= n - 1; i++)
        {
            p[i] = ((y[i + 1] - y[i]) / (x[i + j] - x[i]));
            y[i] = p[i];
        }
        f1 = 1;
        for (i = 1; i <= j; i++)
            f1 *= (k - x[i]);
        f2 += (y[1] * f1);
        n--;
        j++;
    } while (n != 1);
    f += f2;
    printf("\n f(%f) = %f", k, f);
    return 0;
}
