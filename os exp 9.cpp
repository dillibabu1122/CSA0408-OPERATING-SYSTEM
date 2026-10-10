#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    key_t key = 1234;
    int shmid;
    char *str;

    shmid = shmget(key, 1024, IPC_CREAT | 0666);

    str = (char *)shmat(shmid, NULL, 0);

    printf("Enter message: ");
    scanf("%s", str);

    printf("Message written to shared memory: %s\n", str);

    shmdt(str);

    return 0;
}