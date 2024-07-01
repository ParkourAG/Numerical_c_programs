// Complex root by Newton-Raphson method (based on solving a nonlinear equations)

#include <stdio.h>
#include <math.h>
// F(z)= z^4 - 4z^3 + 9z^2 - 4z + 8 ; z=x+iy
#define f(x, y) (pow(x, 4) - 6 * x * x * y * y + pow(y, 4) - 4 * pow(x, 3) + 12 * x * y * y + 9 * (x * x - y * y) - 4 * x + 8)
#define fx(x, y) (4 * pow(x, 3) - 12 * x * y * y - 12 * x * x + 12 * y * y + 18 * x - 4)
#define fy(x, y) (-12 * x * x * y + 4 * pow(y, 3) - 24 * x * y - 18 * y)
#define g(x, y) (-4 * pow(x, 3) * y + 4 * x * pow(y, 3) - 12 * x * x * y + 4 * pow(y, 3) + 18 * x * y - 4 * y)
#define gx(x, y) (-12 * x * x * y + 4 * pow(y, 3) - 24 * x * y + 18 * y)
#define gy(x, y) (-4 * pow(x, 3) - 12 * x * y * y - 12 * x * x + 12 * y * y + 18 * x - 4)
int main()
{
    float eps = 0.000001, x0, y0, x1, y1, J, h, k;
    int i = 0, maxit = 10;
    printf("\n\n Enter the initial guesses for x and y \n: ");
    scanf("%f %f", &x0, &y0);
    printf("\n i x0 y0 f(x0,y0) g(x0,y0) \n");
    do
    {
        J = fx(x0, y0) * gy(x0, y0) - gx(x0, y0) * fy(x0, y0);
        h = (-f(x0, y0) * gy(x0, y0) + g(x0, y0) * fy(x0, y0)) / J;
        k = (-g(x0, y0) * fx(x0, y0) + f(x0, y0) * gx(x0, y0)) / J;
        x0 = x0 + h;
        y0 = y0 + k;
        i = i + 1;
        printf("\n %d %f %f %f %f", i, x0, y0, f(x0, y0), g(x0, y0));
    } while (fabs(f(x0, y0)) > eps && fabs(g(x0, y0)) > eps && i < maxit);
    printf("\n\n The One root is (%f)+i(%f)", x0, y0);
    return 0;
}