// Gauss Jacobi iteration


#include <stdio.h>
#include <math.h>
/* Arranging the given Equations */
#define f1(x1, x2, x3, x4) (2.95 + 0.73 * x2 + 0.65 * x3 - 1.06 * x4) / 6.32
#define f2(x1, x2, x3, x4) (3.36 - 0.89 * x1 + 0.47 * x3 - 0.95 * x4) / 4.32
#define f3(x1, x2, x3, x4) (1.97 - 0.74 * x1 - 1.01 * x2 + 0.88 * x4) / 5.28
#define f4(x1, x2, x3, x4) (4.27 - 1.13 * x1 + 0.89 * x2 - 0.16 * x3) / 5.63
int main()
{
    float x10 = 0, x20 = 0, x30 = 0, x40 = 0, x11, x21, x31, x41, e1, e2, e3, e4, e;
    int count = 1;
    printf("Enter tolerable error: \n");
    scanf("%f", &e);
    printf("\n Count x1 x2 x3 x4\n");
    do
    {
        x11 = f1(x10, x20, x30, x40);
        x21 = f2(x10, x20, x30, x40);
        x31 = f3(x10, x20, x30, x40);
        x41 = f4(x10, x20, x30, x40);
        printf("%d %f %f %f %f\n", count, x11, x21, x31, x41);
        // Error
        e1 = fabs(x10 - x11);
        e2 = fabs(x20 - x21);
        e3 = fabs(x30 - x31);
        e4 = fabs(x40 - x41);
        count++;
        // Set value for next iteration
        x10 = x11;
        x20 = x21;
        x30 = x31;
        x40 = x41;
    } while (e1 > e && e2 > e && e3 > e && e4 > e);
    printf("\nSolution: x1=%f, x2=%f, x3=%f and x4=%f\n", x11, x21, x31, x41);
    return 0;
}