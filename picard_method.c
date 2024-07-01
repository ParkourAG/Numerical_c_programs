// picard_method
#include <stdio.h>
#include <math.h>
#include <conio.h>
// dy/dx = 1 + xy , y(0)=2
#define yy1(x) (2 + (x) + pow(x, 2))
#define yy2(x) (2 + (x) + pow(x,2) + pow(x,3)/3 + pow(x,4)/4)
#define yy3(x) (2 + (x) + pow(x, 2) + pow(x, 3) / 3 + pow(x, 4) / 4 + pow(x, 5) / 15 + pow(x, 6) / 24)
#define yy4(x) (2 + (x) + pow(x,2) + pow(x,3)/3 + pow(x,4)/4 + pow(x,5)/15 + pow(x,6)/24 + pow(x,7)/112 + pow(x,8)/192 ) 
int main()
 {
     double y1[20], y2[20], y3[20], y4[20], a, n, h, i;
     int j;
     printf("\nEnter the value of range: ");
     scanf("%lf %lf", &a, &n);
     printf("\n\nEnter the h: ");
     scanf("%lf", &h);
     for (i = a, j = 0; i <= n; i = i + h, j++)
     {
         y1[j] = yy1(i);
         y2[j] = yy2(i);
         y3[j] = yy3(i);
         y4[j] = yy4(i);
     }
     printf("\nX |");
     for (i = a; i <= n; i = i + h)
     {
         printf(" %.8lf", i);
     }
     printf("\n--------------------------------------------------------------------------------");
     printf("\n\nY1|");
     for (i = a, j = 0; i <= n; i = i + h, j++)
     {
         printf(" %.8lf", y1[j]);
     }
     printf("\n\nY2|");
     for (i = a, j = 0; i <= n; i = i + h, j++)
     {
         printf(" %.8lf", y2[j]);
     }
     printf("\n\nY3|");
     for (i = a, j = 0; i <= n; i = i + h, j++)
     {
         printf(" %.8lf", y3[j]);
     }
     printf("\n\nY4|");
     for (i = a, j = 0; i <= n; i = i + h, j++)
     {
         printf(" %.8lf", y4[j]);
     }
     return 0;
 }