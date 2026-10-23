#include <stdio.h>
int main()
{
    int b[20], p[20], used[20] = {0};
    int nb, np, i, j, worst;
    printf("Enter number of blocks: ");
    scanf("%d", &nb);
    for(i = 0; i < nb; i++)
    {
        printf("Enter block %d size: ", i + 1);
        scanf("%d", &b[i]);
    }
    printf("Enter number of processes: ");
    scanf("%d", &np);

    for(i = 0; i < np; i++)
    {
        printf("Enter process %d size: ", i + 1);
        scanf("%d", &p[i]);
    }

    for(i = 0; i < np; i++)
    {
        worst = -1;

        for(j = 0; j < nb; j++)
        {
            if(!used[j] && b[j] >= p[i])
            {
                if(worst == -1 || b[j] > b[worst])
                    worst = j;
            }
        }

        if(worst != -1)
        {
            used[worst] = 1;
            printf("P%d allocated to Block %d\n",
                   i + 1, worst + 1);
        }
        else
            printf("P%d not allocated\n", i + 1);
    }

    return 0;
}
