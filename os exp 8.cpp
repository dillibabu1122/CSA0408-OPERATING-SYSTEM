#include <stdio.h>

int main()
{
    int n, i, time = 0, remain, tq;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rt[n];
    
    for(i = 0; i < n; i++)
    {
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    remain = n;
    float wt = 0, tat = 0;

    printf("\nProcess\tTurnaround Time\tWaiting Time\n");

    while(remain > 0)
    {
        for(i = 0; i < n; i++)
        {
            if(rt[i] > 0)
            {
                if(rt[i] <= tq)
                {
                    time += rt[i];
                    rt[i] = 0;
                    remain--;

                    int turnaround = time;
                    int waiting = turnaround - bt[i];

                    tat += turnaround;
                    wt += waiting;

                    printf("P%d\t%d\t\t%d\n", i + 1, turnaround, waiting);
                }
                else
                {
                    time += tq;
                    rt[i] -= tq;
                }
            }
        }
    }

    printf("\nAverage Waiting Time = %.2f", wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", tat / n);

    return 0;
}