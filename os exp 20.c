#include <stdio.h>
#include <windows.h>
HANDLE resource, readerMutex;
int readers = 0;
int data = 10;
DWORD WINAPI reader(LPVOID arg)
{
    WaitForSingleObject(readerMutex, INFINITE);

    readers++;
    if(readers == 1)
        WaitForSingleObject(resource, INFINITE);

    ReleaseSemaphore(readerMutex, 1, NULL);

    printf("Reader %d reads data: %d\n",
           (int)(INT_PTR)arg, data);
    Sleep(100);

    WaitForSingleObject(readerMutex, INFINITE);

    readers--;
    if(readers == 0)
        ReleaseSemaphore(resource, 1, NULL);

    ReleaseSemaphore(readerMutex, 1, NULL);

    return 0;
}

DWORD WINAPI writer(LPVOID arg)
{
    WaitForSingleObject(resource, INFINITE);

    data = 20;
    printf("Writer updates data: %d\n", data);

    ReleaseSemaphore(resource, 1, NULL);

    return 0;
}

int main()
{
    HANDLE r1, r2, w;

    resource = CreateSemaphore(NULL, 1, 1, NULL);
    readerMutex = CreateSemaphore(NULL, 1, 1, NULL);

    r1 = CreateThread(NULL, 0, reader, (LPVOID)1, 0, NULL);
    r2 = CreateThread(NULL, 0, reader, (LPVOID)2, 0, NULL);
    w = CreateThread(NULL, 0, writer, NULL, 0, NULL);

    WaitForSingleObject(r1, INFINITE);
    WaitForSingleObject(r2, INFINITE);
    WaitForSingleObject(w, INFINITE);

    CloseHandle(r1);
    CloseHandle(r2);
    CloseHandle(w);
    CloseHandle(resource);
    CloseHandle(readerMutex);

    return 0;
}
