// Bisection Method

#include <stdio.h>
#include <math.h>

#define f(x) (pow(x, 3) - x - 1)

float modNum(float a)
{
    if (a < 0)
    {
        a*= -1;
    }
    return a;
}

float bisect(float num1, float num2)
{
    return (num1 + num2) / (float)2;
}

float correctDecimal(int a)
{
    int denominator = pow(10, a);
    float result = 1 / (float)denominator;
    return result;
}

int main()
{
    float a, b, x[50], fnx, result, diff = 1;
    int correct;
    float arrA[50], arrB[50];
    // loop variables
    int i=1;

// checking validation of given range
    do
    {
        printf("Enter the range: \n");
        printf("Enter the value of a: ");
        scanf("%f", &a);
        printf("Enter the value of b: ");
        scanf("%f", &b);
        if (!((f(a) * f(b)) < 0))
        {
            printf("Entered range is invalid.\n\n");
        }
        else
        {
            printf("Valid range.\n\n");
        }

    } while (!((f(a) * f(b)) < 0));

    printf("The value of a: %f\n", a);
    printf("The value of b: %f\n", b);

    printf("Enter the number of decimal place to be corrected: ");
    scanf("%d", &correct);

// calculation for the first row
    arrA[0] = a;
    arrB[0] = b;
    x[0] = bisect(arrA[0], arrB[0]);
    fnx = f(x[0]);

    if (fnx < 0)
    {
        arrA[1] = x[0];
        arrB[1] = arrB[0];
    }
    else if (fnx > 0)
    {
        arrB[1] = x[0];
        arrA[1] = arrA[0];
    }
    else
    {
        result = x[0];
    }

    printf("\n\n   a\t\t");
    printf("   b\t\t");
    printf("  x\t\t");
    printf("  f(x)\t\t\n");

    printf("%f\t", arrA[0]);
    printf("%f\t", arrB[0]);
    printf("%f\t", x[0]);
    printf("%f\t\n", fnx);

// calculation for the rest rows
    do
    {
        x[i] = bisect(arrA[i], arrB[i]);
        fnx = f(x[i]);

        if (fnx < 0)
        {
            arrA[i + 1] = x[i];
            arrB[i + 1] = arrB[i];
        }
        else if (fnx > 0)
        {
            arrB[i + 1] = x[i];
            arrA[i + 1] = arrA[i];
        }
        else
        {
            result = x[i];
        }
        diff = modNum(x[i - 1] - x[i]);

        printf("%f\t", arrA[i]);
        printf("%f\t", arrB[i]);
        printf("%f\t", x[i]);
        printf("%f\t\n", fnx);
        // printf("%f\t\n", diff);
        i += 1;

    } while (!(diff<correctDecimal(correct)));

    result= x[i-1];
    printf("\nRoot is %f\n\n", result);

    return 0;
}