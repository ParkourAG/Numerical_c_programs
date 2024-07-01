// Fitting parabola of the type y=a+bx^2

// R=6
// x-R/10=0 => x-6/10=0 => x=0.6
// y-3R/10=0 => y-3*6/10=0 => y=1.8
#include <stdio.h>
#include <stdio.h>
int main()
{
    int i, j, n, r;
    float x[10], y[10], sum1, sum2, sum3, sum4, sum5;
    float a, b, d;
    printf("\n Enter the number of data pairs to be entered: \n");
    scanf("%d", &n);
    printf("\n Enter the x-axis values and y-axis values pairwise: \n");
    for (i = 0; i < n; i++)
        scanf("%f%f", &x[i], &y[i]);
    sum1 = 0.0;
    sum2 = 0.0;
    sum3 = 0.0;
    sum4 = 0.0;
    sum5 = 0.0;
    for (i = 0; i < n; i++)
    {
        sum1 = sum1 + x[i];
        sum2 = sum2 + x[i] * x[i];
        sum3 = sum3 + x[i] * x[i] * x[i];
        sum4 = sum4 + y[i];
        sum5 = sum5 + x[i] * y[i];
    }
    d = n * sum3 - sum1 * sum2;
    a = (sum3 * sum4 - sum2 * sum5) / d;
    b = (n * sum5 - sum1 * sum4) / d;
    printf("\n The values of a and b are: %f\t %f \n", a, b);
    printf("\n The Linear Relation is: \n");
    printf("\n y=(%f)+(%f)x^2", a, b);

    return 0;
}