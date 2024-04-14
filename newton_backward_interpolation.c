#include<stdio.h>

int factorial(int num)
{
    int fact = 1;
    if (num == 0)
    {
        fact = 1;
    }
    else
    {
        for (int i = 1; i <= num; i++)
        {
            fact *= i;
        }
    }
    return fact;
}
float calc_u(float u, int num){
    float prod= 1;
    for(int i= 0; i<num; i++){
        prod*= (u+i);
    }
    return prod;
}


int main(){
    int num;
    float calc, h, u, result;
// loop variables
    int i, j, k, l, m, n;

    printf("Enter the number of terms: ");
    scanf("%d", &num);
    float x[num], y[num][num];

// Taking inputs
    printf("Enter the values one by one:\n");
    for(k=0; k<num; k++){
        printf("x[%d]= ", k);
        scanf("%f", &x[k]);
        printf("y[%d]= ", k);
        scanf("%f", &y[k][0]);
    }

// Calculation of backward difference table
    for(i=1; i<num; i++){
        for(j=i; j<num; j++){
            y[j][i]= y[j][i-1]-y[j-1][i-1];
        }
    }

// Printing Backward difference table
    printf("\nBackward difference table: \n\n");
    for(l=0; l<num; l++){
        printf("%0.3f\t", x[l]);
        for(m=0; m<=l; m++){
            printf("%0.5f\t", y[l][m]);
        }
        printf("\n");
    }

// Calculation of newton backward interpolation
    printf("Enter interpolating point: ");
    scanf("%f", &calc);
    h = x[1] - x[0];
    printf("h= %f\n", h);
    u = (calc - x[num-1]) / h;
    printf("u= %f", u);

    result= y[num-1][0];
    for(n=1; n<num; n++){
        result+= (calc_u(u,n)/factorial(n))* y[num-1][n];
    }

    // result
    printf("\nResult: \n");
    printf("f(%0.6f)= %0.6f", calc, result);
    
    return 0;
}

/* Example set ; f(38)=0.615667
x  y
0 0
10 0.17365
20 0.34202
30 0.5
40 0.64279
*/