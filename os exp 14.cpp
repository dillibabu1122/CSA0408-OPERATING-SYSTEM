#include <stdio.h>
#include <string.h>

int main()
{
    int n, i;
    char file[20][20];

    printf("Enter number of files: ");
    scanf("%d", &n);

    printf("Enter file names:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%s", file[i]);
    }

    printf("\nFiles in Single Level Directory:\n");
    for(i = 0; i < n; i++)
    {
        printf("%s\n", file[i]);
    }

    return 0;
}