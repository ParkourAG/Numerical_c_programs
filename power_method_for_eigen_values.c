//power method : largest eigen value and corresponding eigen vectors 

#include <stdio.h>
int main()
{
    float matrix[10][10], x[20], y[20], m;
    int i, j, k, n;
    printf("Enter order of matrix:");
    scanf("%d", &n);
    printf("enter the matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%f", &matrix[i][j]);
            x[i] = 1;
        }
    }
    for (k = 0; k < 30; k++)
    {
        for (i = 0; i < n; i++)
        {
            y[i] = 0;
            for (j = 0; j < n; j++)
                y[i] = y[i] + matrix[i][j] * x[j];
        }
        m = y[0];
        for (i = 1; i < n; i++)
        {
            if (m < y[i])
                m = y[i];
        }
        printf("\n y[%d]=%f", i, m);
        for (i = 0; i < n; i++)
            x[i] = y[i] / m;
    }
    printf("\n Numerically the largest eigen value is %f\n", m);
    printf("\n\n the corresponding eigen vector is:");
    for (i = 0; i < n; i++)
        printf("\n x[%d]=%f", i, x[i]);
    return 0;
}