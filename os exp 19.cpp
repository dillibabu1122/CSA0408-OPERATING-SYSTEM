#include <stdio.h>
#include <windows.h>
HANDLE mutex;
int counter = 0;
DWORD WINAPI task(LPVOID arg)
{
    int i;

    for(i = 0; i < 5; i++)
    {
        WaitForSingleObject(mutex, INFINITE);

        counter++;
        printf("Thread %d: Counter = %d\n",
               (int)(INT_PTR)arg, counter);

        ReleaseMutex(mutex);
    }
    return 0;
}
int main()
{
    HANDLE t1, t2;
    mutex = CreateMutex(NULL, FALSE, NULL);
    t1 = CreateThread(NULL, 0, task, (LPVOID)1, 0, NULL);
    t2 = CreateThread(NULL, 0, task, (LPVOID)2, 0, NULL);
    WaitForSingleObject(t1, INFINITE);
    WaitForSingleObject(t2, INFINITE);
    printf("Final Counter = %d\n", counter);
    CloseHandle(t1);
    CloseHandle(t2);
    CloseHandle(mutex);

    return 0;
}
