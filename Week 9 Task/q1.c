#include <stdio.h>
void dots_and_os(int N)
{
    int lines, j;
    int temp_n = N;
    for (lines = N; lines >= 1; lines--)
    {
        for (j = 1; j <= lines; j++)
        {
            printf(" . ");
        }
        for (j = N; j >= lines; j--)
        {
            printf("o");
        }
        printf("\n");
    }
    for (lines = 2; lines <= N; lines++)
    {
        for (j = 1; j <= lines; j++)
        {
            printf(" . ");
        }
        for (j = temp_n; j >= 2; j--)
        {
            printf("o");
        }
        temp_n--;
        printf("\n");
    }
}

int main()
{
    int Number;

    printf("Enter the number of rows: ");

    scanf("%d", &Number);

    dots_and_os(Number);

    return 0;
}