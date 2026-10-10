#include <stdio.h>
#include <windows.h>
DWORD WINAPI thread1(LPVOID arg)
{
    int i;

    for(i = 1; i <= 5; i++)
    {
        printf("Thread 1: %d\n", i);
        Sleep(500);
    }

    return 0;
}
DWORD WINAPI thread2(LPVOID arg)
{
    int i;

    for(i = 1; i <= 5; i++)
    {
        printf("Thread 2: %d\n", i);
        Sleep(500);
    }

    return 0;
}
int main()
{
    HANDLE t1, t2;
    t1 = CreateThread(NULL, 0, thread1, NULL, 0, NULL);
    t2 = CreateThread(NULL, 0, thread2, NULL, 0, NULL);
    WaitForSingleObject(t1, INFINITE);
    WaitForSingleObject(t2, INFINITE);
    CloseHandle(t1);
    CloseHandle(t2);
    printf("Both threads completed.\n");
    return 0;
}