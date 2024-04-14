// C program to accept 100 numbers as input and to sort them in ascending order.
#include <stdio.h>

int main()
{
    int numCount, number[100], temp;
    printf("How many numbers to want to enter: ");
    scanf("%d", &numCount);
    printf("Enter the numbers one by one: \n");
// taking inputs
    for (int i = 0; i < numCount; i++)
    {
        printf("%d) ", i+1);
        scanf("%d", &number[i]);
    }
// computation for ascending order
    for (int i = 0; i < numCount; i++)
    {
        for(int j= i+1; j < numCount; j++){
            if(number[i]>number[j]){
                temp= number[i];
                number[i]= number[j];
                number[j]= temp;
            }
        }
    }
// printing ascending order
    printf("The numbers in ascending order: ");
    for(int k=0; k<numCount; k++){
        if(k==(numCount-1)){
            printf(" %d", number[k]);
        }else{
            printf(" %d ,", number[k]);
        }
    }
    
    return 0;
}