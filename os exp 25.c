#include <stdio.h>
#include <windows.h>

int main()
{
    HANDLE f;
    DWORD n;
    char text[] = "Hello OS";
    char buffer[20] = {0};

    f = CreateFileA("test.txt", GENERIC_READ | GENERIC_WRITE,
        0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    if (f == INVALID_HANDLE_VALUE)
    {
        printf("File error");
        return 1;
    }

    WriteFile(f, text, sizeof(text) - 1, &n, NULL);
    SetFilePointer(f, 0, NULL, FILE_BEGIN);
    ReadFile(f, buffer, sizeof(text) - 1, &n, NULL);

    printf("File content: %s\n", buffer);
    CloseHandle(f);

    return 0;
}