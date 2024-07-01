// Weddle's rule

#include <stdio.h>
#include <conio.h>
#include <math.h>
// R=6
// q=(6+R)/20 => q=0.6
#define f(x) (0.6 + x * x * cos(0.6 * x)) / (sqrt(1 + x + sinh(x + 1)))
int main()
{
    float l, u, h, s = 0, l1, l2, l3, l4, l5, l6, f1, f2, f3, f4, f5, f6;
    int i, n, m;
    printf("Enter the value of lower limit: ");
    scanf("%f", &l);
    printf("Enter the value of upper limit: ");
    scanf("%f", &u);
    // l=l*22/(7*180);
    //  u=u*22/(7*180);
    printf("Enter the value of n: ");
    scanf("%d", &n);
    h = (u - l) / n;
    printf("h= %f", h);
    m = n / 6;
    s = 0;
    if (n % 6 == 0)
    {
        for (i = 1; i <= m; i++)
        {
            l1 = l + h;
            l2 = l + 2 * h;
            l3 = l + 3 * h;
            l4 = l + 4 * h;
            l5 = l + 5 * h;
            l6 = l + 6 * h;
            f1 = f(l1);
            f2 = f(l2);
            f3 = f(l3);
            f4 = f(l4);
            f5 = f(l5);
            f6 = f(l6);
            printf("\n f(%f)=%f \nf(%f)=%f \nf(%f)=%f \nf(%f)=%f \nf(%f)=%f \nf(%f)=%f"
                   "\nf(%f)=%f",
                   l, f(l), l1, f1, l2, f2, l3, f3, l4, f4, l5, f5, l6, f6);
            s = s + (3 * h / 10) * (f(l) + 5 * f1 + f2 + 6 * f3 + f4 + 5 * f5 + f6);
            l = l + 6 * h;
        }
        printf("\n\nResult is : %f ", s);
    }
    else
        printf(" Weddle's rule is not applicable");
    return 0;
}
