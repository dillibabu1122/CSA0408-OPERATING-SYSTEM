#include <stdio.h>
int main()
{
    int n, i, time = 0, completed = 0;
    int at[10], bt[10], pr[10], rt[10];
    int wt[10], tat[10], ct[10];
    int high, min;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("\nP%d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);

        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);

        printf("P%d Priority: ", i + 1);
        scanf("%d", &pr[i]);

        rt[i] = bt[i];
    }
    while(completed < n)
    {
        high = -1;
        min = 999;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] > 0 && pr[i] < min)
            {
                min = pr[i];
                high = i;
            }
        }

        if(high == -1)
        {
            time++;
            continue;
        }

        rt[high]--;
        time++;

        if(rt[high] == 0)
        {
            completed++;

            ct[high] = time;
            tat[high] = ct[high] - at[high];
            wt[high] = tat[high] - bt[high];
        }
    }
    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], pr[i],
               ct[i], tat[i], wt[i]);
    }

    return 0;
}