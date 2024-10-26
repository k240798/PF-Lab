#include<stdio.h>

void sand_glass() {
    int n, i, j;
    printf("Enter the number of rows");
    scanf("%d", &n);

    for(i = n; i>=0; i--) {
        for (j = 1; j <= n-i; j++){
        printf(" ");
        }
        for(j=1; j<= i; j++) {
            printf("%d ", n-j);
        }
        if(i != 0) {
            printf("\n");
        }
    }

    for (i=0; i <= n; i++) {
        for (j=1; j <= n-i; j++)
        printf(" ");
        for (j=1; j<=i; j++)
        printf("%d ", n-j);
        printf("\n");
    }
}

int main() {
    sand_glass();
    return 0;
}