#include <stdio.h>

int main()
{
    int b[10], p[10], nb, np, i, j;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter block sizes:\n");
    for(i = 0; i < nb; i++)
        scanf("%d", &b[i]);

    printf("Enter process sizes:\n");
    for(i = 0; i < np; i++)
        scanf("%d", &p[i]);

    /* First Fit */
    printf("\nFIRST FIT\n");
    for(i = 0; i < np; i++)
    {
        for(j = 0; j < nb; j++)
        {
            if(b[j] >= p[i])
            {
                printf("Process %d allocated to Block %d\n", i + 1, j + 1);
                b[j] -= p[i];
                break;
            }
        }
    }

    return 0;
}