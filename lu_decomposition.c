// LU Decomposition for solving linear equation

#include <stdio.h>
int main()
{
    int n, i, k, j, p;
    float a[10][10], l[10][10] = {0}, u[10][10] = {0}, sum, b[10], z[10] = {0}, x[10] = {0};
    printf("\nEnter the order of matrix: ");
    scanf("%d", &n);
    printf("\nEnter the elements of augmented matrix row-wise:\n\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("a[%d][%d] : ", i, j);
            scanf("%f", &a[i][j]);
        }
        printf("b[%d]: ", i);
        scanf("%f", &b[i]);
    }
    // LU decomposition
    for (k = 1; k <= n; k++)
    {
        u[k][k] = 1;
        for (i = k; i <= n; i++)
        {
            sum = 0;
            for (p = 1; p <= k - 1; p++)
                sum += l[i][p] * u[p][k];
            l[i][k] = a[i][k] - sum;
        }
        for (j = k + 1; j <= n; j++)
        {
            sum = 0;
            for (p = 1; p <= k - 1; p++)
                sum += l[k][p] * u[p][j];
            u[k][j] = (a[k][j] - sum) / l[k][k];
        }
    }
    // Displaying LU matrix
    printf("\nL and U matrices are: \n ");
    for (i = 1; i <= n; i++)
    {
        printf("\n");
        for (j = 1; j <= n; j++)
        {
            printf(" %.5f", l[i][j]);
            printf("\t");
        }
    }
    printf("\n");
    for (i = 1; i <= n; i++)
    {
        printf("\n");
        for (j = 1; j <= n; j++)
        {
            printf(" %.5f", u[i][j]);
            printf("\t");
        }
    }
    // FINDING Z; LZ=b
    for (i = 1; i <= n; i++)
    { // forward subtitution method
        sum = 0;
        for (p = 1; p < i; p++)
            sum += l[i][p] * z[p];
        z[i] = (b[i] - sum) / l[i][i];
    }
    // FINDING X; UX=Z
    for (i = n; i > 0; i--)
    {
        sum = 0;
        for (p = n; p > i; p--)
            sum += u[i][p] * x[p];
        x[i] = (z[i] - sum) / u[i][i];
        /* printf("\n x[%d]= %.3f",i,x[i]);
        printf("\n");*/
    }
    // DISPLAYING SOLUTION
    printf("\n \nSet of solution is\n");
    for (i = 1; i <= n; i++)
    {
        printf("\n x[%d]= %f", i, x[i]);
        printf("\n");
    }

    return 0;
}