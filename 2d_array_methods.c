#include<stdio.h>

int main(){
    int row, col;
//Loop variables
    int i, j, k, l;
    
    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &col);

    int  arr[row][col];
    printf("Enter data one by one:\n");
// Input values in Matrix
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            printf("row %d, col %d: ", i+1, j+1);
            scanf("%d", &arr[i][j]);
        }
    }
// Printing the Matrix
    for(k=0; k<row; k++){
        printf("\n");
        for(l=0; l<col; l++){
            printf("%d\t", arr[k][l]);
        }
    }

    return 0;
}
