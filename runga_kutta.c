// Runga kutta 4 method

#include <stdio.h>
#include <math.h>
// R=6
// y(0)=1+R/10 => 1.6
#define f(x, y) (1 + cos(0.25 * x * x + 0.4 * y * y * y)) / (1 + 0.25 * x * x * x + 0.4 * y * y)
int main()
{
    float x0, y0, y1, xn, h, k1, k2, k3, k4;
    printf("Enter the value of x0,y0,h,xn: ");
    scanf("%f %f %f %f", &x0, &y0, &h, &xn);
    printf("\n x\t\t y \n");
    do
    {
        k1 = h * f(x0, y0);
        k2 = h * f((x0 + h / 2), (y0 + k1 / 2));
        k3 = h * f((x0 + h / 2), (y0 + k2 / 2));
        k4 = h * f((x0 + h), (y0 + k3));
        y1 = y0 + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x0 = x0 + h;
        y0 = y1;
        printf("%f \t %f \n", x0, y1);
    } while (x0 <= xn);
    return 0;
}