// Fitting Polynomial

// R=6
// x=0,y-R/10=0;=>x=0,y=0.6
#include <stdio.h>
#include <math.h>
int main()
{
    int i, j, k, n, m;
    printf("\n Enter the no. of data pairs to be entered: \n");
    scanf("%d", &m);
    double x[m], y[m];
    printf("\n Enter the x-axis values: \n");
    for (i = 0; i < m; i++)
        scanf("%lf", &x[i]);
    printf("\n Enter the y-axis values: \n");
    for (i = 0; i < m; i++)
        scanf("%lf", &y[i]);
    printf("\n Enter the degree of Polynomial: \n");
    scanf("%d", &n);
    double xx[2 * n + 1];
    for (i = 0; i < 2 * n + 1; i++)
    {
        xx[i] = 0;
        for (j = 0; j < m; j++)
            xx[i] = xx[i] + pow(x[j], i);
    }
    double B[n + 1][n + 2], a[n + 1];
    for (i = 0; i <= n; i++)
        for (j = 0; j <= n; j++)
            B[i][j] = xx[i + j];
    double Y[n + 1];
    for (i = 0; i < n + 1; i++)
    {
        Y[i] = 0;
        for (j = 0; j < m; j++)
            Y[i] = Y[i] + pow(x[j], i) * y[j];
    }
    for (i = 0; i <= n; i++)
        B[i][n + 1] = Y[i];
    n = n + 1;
    printf("\n The Normal(Augmented Matrix) is as follows: \n");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j <= n; j++)
        {
            printf("%lf", B[i][j]);
            printf("\t");
        }
    }
    for (i = 0; i < n; i++)
        for (k = i + 1; k < n; k++)
            if (B[i][i] < B[k][i])
                for (j = 0; j <= n; j++)
                {
                    double temp = B[i][j];
                    B[i][j] = B[k][j];
                    B[k][j] = temp;
                }

    for (i = 0; i < n - 1; i++)
        for (k = i + 1; k < n; k++)
        {
            double t = B[k][i] / B[i][i];
            for (j = 0; j <= n; j++)
                B[k][j] = B[k][j] - t * B[i][j];
        }
    for (i = n - 1; i >= 0; i--)
    {
        a[i] = B[i][n];
        for (j = 0; j < n; j++)
            if (j != i)
                a[i] = a[i] - B[i][j] * a[j];
        a[i] = a[i] / B[i][i];
    }
    printf("\n\n The values of the coeƯicients are as follows: \n");
    for (i = 0; i < n; i++)
        printf("\nx^%d=%lf", i, a[i]);
    printf("\n\n Hence the fitted Polynomial is given by: \n y= ");
    for (i = 0; i < n; i++)
        printf("+(%lf)x^%d", a[i], i);
    printf("\n");
    return 0;
}