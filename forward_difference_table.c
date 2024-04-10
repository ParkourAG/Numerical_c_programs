#include<stdio.h>

int main(){
    int num;
// loop variables
    int i, j, k, l, m;

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

// Calculation of forward difference table
    for(i=1; i<num; i++){
        for(j=0; j<(num-i); j++){
            y[j][i]= y[j+1][i-1]-y[j][i-1];
        }
    }

// Printing forward difference table
    printf("\n Forward difference table: \n\n");
    for(l=0; l<num; l++){
        printf("%0.3f\t", x[l]);
        for(m=0; m<(num-l); m++){
            printf("%0.3f\t", y[l][m]);
        }
        printf("\n");
    }

    return 0;
}