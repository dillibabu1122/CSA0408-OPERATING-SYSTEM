#include <stdio.h>
#include <windows.h>
#define SIZE 5
int buffer[SIZE], in = 0, out = 0;
HANDLE emptySlots, fullSlots, mutex;
DWORD WINAPI producer(LPVOID arg)
{
    int i;
    for(i = 1; i <= 5; i++)
    {
        WaitForSingleObject(emptySlots, INFINITE);
        WaitForSingleObject(mutex, INFINITE);

        buffer[in] = i;
        in = (in + 1) % SIZE;
        printf("Produced: %d\n", i);

        ReleaseMutex(mutex);
        ReleaseSemaphore(fullSlots, 1, NULL);
    }
    return 0;
}
DWORD WINAPI consumer(LPVOID arg)
{
    int i, item;
    for(i = 1; i <= 5; i++)
    {
        WaitForSingleObject(fullSlots, INFINITE);
        WaitForSingleObject(mutex, INFINITE);

        item = buffer[out];
        out = (out + 1) % SIZE;
        printf("Consumed: %d\n", item);

        ReleaseMutex(mutex);
        ReleaseSemaphore(emptySlots, 1, NULL);
    }

    return 0;
}

int main()
{
    HANDLE p, c;
    emptySlots = CreateSemaphore(NULL, SIZE, SIZE, NULL);
    fullSlots = CreateSemaphore(NULL, 0, SIZE, NULL);
    mutex = CreateMutex(NULL, FALSE, NULL);
    p = CreateThread(NULL, 0, producer, NULL, 0, NULL);
    c = CreateThread(NULL, 0, consumer, NULL, 0, NULL);
    WaitForSingleObject(p, INFINITE);
    WaitForSingleObject(c, INFINITE);
    CloseHandle(p);
    CloseHandle(c);
    CloseHandle(emptySlots);
    CloseHandle(fullSlots);
    CloseHandle(mutex);
    return 0;
}
