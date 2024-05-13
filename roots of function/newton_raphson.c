// Newton Raphson

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define f(x) x+log(x)-2
#define deriv_f(x) 1+(1/x)

float modNum(float a)
{
    if (a < 0)
    {
        a*= -1;
    }
    return a;
}

float xVal(int i, float x[]){
    float result= x[i-1]-(f(x[i-1])/deriv_f(x[i-1]));
    return result;
}

float correctDecimal(int a)
{
    int denominator = pow(10, a);
    float result = 1 / (float)denominator;
    return result;
}

int main()
{
    float x[100], fxn, dfxn, diff;
    int correct;

    int i=0;

    printf("Enter initial value of x: ");
    scanf("%f", &x[0]);
    printf("Enter the number of decimal place to be corrected: ");
    scanf("%d", &correct);

    printf("\n   Xn\t\t f(Xn)\t\t f'(Xn)\t\t Xn+1\n\n");

    do
    {
        if(deriv_f(x[i])==0){
            printf("Mathematical Error!!");
            exit(0);
        }

        fxn= f(x[i]);
        dfxn= deriv_f(x[i]);
        x[i+1]= x[i]- (fxn/dfxn);

        printf("%f\t %f\t %f\t %f\n ", x[i], f(x[i]), deriv_f(x[i]), x[i+1]);

        diff= modNum(x[i+1]-x[i]);

        i++;
    } while (!(diff<correctDecimal(correct)));
    

    return 0;
}