// Euler method

#include <stdio.h>
#include <math.h>
// R=6
// y(0)=1+R/100 => 1.06
#define f(x, y) (sinh(1 - x * y * y) + cosh(1 - x * x * y)) / (2 + x + y + x * y)
int main()
{
    float x0, y0, y1, xn, h;
    printf("Enter the value of x0, y0, h, xn: ");
    scanf("%f %f %f %f", &x0, &y0, &h, &xn);
    printf("\n x\t\t y \n");
    do
    {
        y1 = y0 + h * f(x0, y0);
        x0 = x0 + h;
        y0 = y1;
        printf("%f \t %f \n", x0, y0);
    } while (x0 <= xn);

    return 0;
}