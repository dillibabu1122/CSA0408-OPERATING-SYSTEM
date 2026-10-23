
#include <stdio.h>
#include <windows.h>

int main()
{
    HANDLE file;
    DWORD written, readBytes;
    char data[] = "Operating System File Management";
    char buffer[100] = {0};
    BY_HANDLE_FILE_INFORMATION info;

    file = CreateFileA(
        "sample.txt",
        GENERIC_READ | GENERIC_WRITE,
        0, NULL, CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL, NULL);

    if(file == INVALID_HANDLE_VALUE)
    {
        printf("File creation failed\n");
        return 1;
    }

    WriteFile(file, data, sizeof(data) - 1,
              &written, NULL);

    SetFilePointer(file, 0, NULL, FILE_BEGIN);

    ReadFile(file, buffer, sizeof(buffer) - 1,
             &readBytes, NULL);

    printf("File content: %s\n", buffer);

    if(GetFileInformationByHandle(file, &info))
        printf("File size: %lu bytes\n",
               (unsigned long)info.nFileSizeLow);

    CloseHandle(file);

    printf("File closed successfully\n");

    return 0;
}
