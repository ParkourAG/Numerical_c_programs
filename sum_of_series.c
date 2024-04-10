// calculate the value of, (1/1)+(1/2)+(1/3)+(1/4)+......+(1/n).

#include<stdio.h>

int main(){
    int num, i;
    float sum= 0;

    printf("Enter the number of terms: ");
    scanf("%d", &num);

    for(i=1; i<=num; i++){
        sum= sum+((1/(float)i));
        if(i==num){
            printf(" 1/%d ", i);
        }else{
            printf(" 1/%d +", i);
        }
    }
    printf("= %f", sum);

    return 0;
}