#include <stdio.h>
#include <string.h>
#include <windows.h>
int main()
{
    HANDLE hMapFile;
    char *message;
    hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE,
        0,
        1024,
        "MyMessageQueue");
    if (hMapFile == NULL)
    {
        printf("Message queue creation failed.\n");
        return 1;
    }
    message = (char *)MapViewOfFile(
        hMapFile,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        1024);
    if (message == NULL)
    {
        printf("Unable to access message queue.\n");
        CloseHandle(hMapFile);
        return 1;
    }
    strcpy(message, "Hello from Message Queue");
    printf("Message sent: %s\n", message);
    printf("Message received: %s\n", message);
    UnmapViewOfFile(message);
    CloseHandle(hMapFile);
    return 0;
}