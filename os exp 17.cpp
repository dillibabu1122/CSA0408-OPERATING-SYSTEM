
#include <stdio.h>

#define P 5
#define R 3

int available[R] = {3, 3, 2};

int maximum[P][R] = {
    {7, 5, 3}, {3, 2, 2}, {9, 0, 2},
    {2, 2, 2}, {4, 3, 3}
};

int allocation[P][R] = {
    {0, 1, 0}, {2, 0, 0}, {3, 0, 2},
    {2, 1, 1}, {0, 0, 2}
};

int is_safe() {
    int work[R], finish[P] = {0};
    int i, j, count = 0;

    for (i = 0; i < R; i++)
        work[i] = available[i];

    while (count < P) {
        int found = 0;

        for (i = 0; i < P; i++) {
            if (!finish[i]) {
                for (j = 0; j < R; j++)
                    if (maximum[i][j] - allocation[i][j] > work[j])
                        break;

                if (j == R) {
                    for (j = 0; j < R; j++)
                        work[j] += allocation[i][j];

                    finish[i] = 1;
                    count++;
                    found = 1;
                }
            }
        }

        if (!found)
            return 0;
    }
    return 1;
}

int main() {
    int p, req[R], i;

    printf("Enter process number (0-4): ");
    scanf("%d", &p);

    if (p < 0 || p >= P) {
        printf("Invalid process number.\n");
        return 0;
    }

    printf("Enter request (3 resources): ");
    for (i = 0; i < R; i++)
        scanf("%d", &req[i]);

    for (i = 0; i < R; i++) {
        if (req[i] > available[i] ||
            req[i] > maximum[p][i] - allocation[p][i]) {
            printf("Request denied.\n");
            return 0;
        }
    }

    for (i = 0; i < R; i++) {
        available[i] -= req[i];
        allocation[p][i] += req[i];
    }

    if (is_safe())
        printf("Request granted. System is safe.\n");
    else
        printf("Request denied. System is unsafe.\n");

    return 0;
}
\