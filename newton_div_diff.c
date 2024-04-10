#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    float x[10], y[10][10], sum, p, u, temp;
    int i, n, j, k = 0, f, m;
    float fact(int);
    /* Input Section */
    printf("\n How many data do you want to enter : ");
    scanf("%d", &n);
    printf("Enter the data set  (x[i],y[i]) : \n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d]= ", i);
        scanf("%f", &x[i]);
        printf("y[x%d]= ", i);
        scanf("%f", &y[k][i]);
    }
    printf("\n\nEnter x for finding f(x) : ");
    scanf("%f", &p);
    /* Computation of Difference table */
    for (i = 1; i < n; i++)
    {
        k = i;
        for (j = 0; j < n - i; j++)
        {
            y[i][j] = (y[i - 1][j + 1] - y[i - 1][j]) / (x[k] - x[j]);
            k++;
        }
    }
    /* Printing of Difference table */
    printf("\n----------------------------------------------------------------------------\n");
    printf("\n       x(i)\t           y(i)\t                y1(i)         y2(i)        y3(i)       y(4)");
    printf("\n----------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        printf("\n%0.3f", x[i]);
        for (j = 0; j < n - i; j++)
        {
            printf("        ");
            printf("%0.3f", y[j][i]);
        }
        printf("\n");
    }
    /* Computation Section */
    i = 0;
    do
    {
        if (x[i] < p && p < x[i + 1])
            k = 1;
        else
            i++;
    } while (k != 1);
    f = i;
    sum = 0;
    for (i = 0; i < n - 1; i++)
    {
        k = f;
        temp = 1;
        for (j = 0; j < i; j++)
        {
            temp = temp * (p - x[k]);
            k++;
        }
        sum = sum + temp * (y[i][f]);
    }
    /* Output Section */
    printf("\n\n f(%0.3f)=%f", p, sum);
    getch();
}