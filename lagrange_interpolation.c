#include<stdio.h>

int main(){
    int count;
    float x[100], y[100], intp, prod, sum=0;
    // loop variables
    int i,j,k;

    printf("Enter total numbers of data: ");
    scanf("%d", &count);

    // taking values
    printf("Enter data one by one: \n");
    for(i=0; i<count; i++){
        printf("x[%d]: ", i+1);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i+1);
        scanf("%f", &y[i]);
    }
    printf("Enter the interpolation value: ");
    scanf("%f", &intp);

    // interpolation
    for(j=0; j<count; j++){
        prod= 1;
        for(k=0; k<count; k++){
            if(j!=k){
                prod= prod* (intp-x[k])/(x[j]-x[k]);
            }
        }
        sum= sum+ prod*y[j];
    }

    printf("The interpolated value at %0.3f is %0.3f", intp, sum);
    return 0;
}