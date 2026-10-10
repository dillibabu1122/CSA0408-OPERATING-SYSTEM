#include <stdio.h>

#define N 5

int state[N];
int i;

void dining(int p)
{
    printf("\nPhilosopher %d is Thinking", p);

    printf("\nPhilosopher %d is Hungry", p);

    printf("\nPhilosopher %d takes Fork %d and Fork %d",
           p, p, (p + 1) % N);

    printf("\nPhilosopher %d is Eating", p);

    printf("\nPhilosopher %d puts down Fork %d and Fork %d\n",
           p, p, (p + 1) % N);
}

int main()
{
    for(i = 0; i < N; i++)
    {
        dining(i);
    }

    return 0;
}