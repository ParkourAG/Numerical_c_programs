#include <stdio.h>
// Numerical integration-> simpson's 3/8th rule

#define f(x) (4 * x - (3 * x * x))

int main()
{
    int num;
    float upper_lt, lower_lt, h, sum1, sum2, sum3, result;
    // loop variables
    int i, j, k;

    printf("Enter the upper limit: ");
    scanf("%f", &upper_lt);
    printf("Enter the lower limit: ");
    scanf("%f", &lower_lt);
    printf("Enter the total number of sub-divisions: ");
    scanf("%d", &num);
    if ((num % 3) == 0)
    {

        h = (upper_lt - lower_lt) / (float)num;
        // printf("h= %0.3f\n", h);

        // printing x and f(x) with sib-intervals
        float x[num + 1], y[num + 1];
        x[0] = lower_lt;
        y[0] = f(x[0]);
        printf("\n   x  \t\ty\n");
        printf("%f\t", x[0]);
        printf("%f\t", y[0]);
        printf("\n");
        for (i = 1; i <= num; i++)
        {
            x[i] = x[i - 1] + h;
            y[i] = f(x[i]);
            printf("%f\t", x[i]);
            printf("%f\t", y[i]);
            printf("\n");
        }

        // calculating the final result
        sum1 = y[0] + y[num];
        sum2 = 0;
        sum3 = 0;
        for (j = 1; j < num; j++)
        {
            if ((j % 3) == 0)
            {
                sum3 += y[j];
            }
            else
            {
                sum2 += y[j];
            }
        }
        result = ((3*h) / 8) * (sum1 + (3 * sum2) + (2 * sum3));
        printf("\nintegration result= %f", result);
    }
    else
    {
        printf("\nError: Please, Enter number of sub-divisions divisible by 3.");
    }
    return 0;
}