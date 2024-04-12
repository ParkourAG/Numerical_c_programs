#include <stdio.h>
// newton divided difference interpolation

int factorial(int num)
{
    int fact = 1;
    if (num == 0)
    {
        fact = 1;
    }
    else
    {
        for (int i = 1; i <= num; i++)
        {
            fact *= i;
        }
    }
    return fact;
}

int main()
{
    int num, fact;
    float calc, h, u, result;
    // loop variables
    int i, j, k, l, m, n, o;

    printf("Enter the number of terms: ");
    scanf("%d", &num);
    float x[num], y[num][num];

    // Taking inputs
    printf("Enter the values one by one:\n");
    for (k = 0; k < num; k++)
    {
        printf("x[%d]= ", k);
        scanf("%f", &x[k]);
        printf("y[%d]= ", k);
        scanf("%f", &y[k][0]);
    }

    // Calculation of forward difference table
    for (i = 1; i < num; i++)
    {
        for (j = 0; j < (num - i); j++)
        {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }

    // Printing forward difference table
    printf("\n Forward difference table: \n\n");
    for (l = 0; l < num; l++)
    {
        printf("%0.3f\t", x[l]);
        for (m = 0; m < (num - l); m++)
        {
            printf("%0.3f\t", y[l][m]);
        }
        printf("\n");
    }

    // // newton forward interpolation calculatoin
    // printf("Enter interpolating point: ");
    // scanf("%f", &calc);
    // h = x[1] - x[0];
    // printf("h= %f\n", h);
    // u = (calc - x[0]) / h;
    // printf("u= %f", u);
    // result= y[0][0];
    // for(n=1; n<num; n++){
    //     result+= (calc_u(u, n)/factorial(n))* y[0][n];
    // }

    // divided difference calculation
    printf("Enter interpolating point: ");
    scanf("%f", &calc);
    h = x[1] - x[0];
    printf("h= %f\n", h);
    u = (calc - x[0]) / h;
    printf("u= %f", u);
    result= y[0][0];

    // result
    printf("\nResult: \n");
    printf("f(%0.6f)= %0.6f", calc, result);

    return 0;
}