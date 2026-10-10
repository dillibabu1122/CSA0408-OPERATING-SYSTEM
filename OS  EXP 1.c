#include <stdio.h>
#include <windows.h>

int main()
{
    DWORD pid, ppid;

    pid = GetCurrentProcessId();
    ppid = GetCurrentProcessId();

    printf("Current Process ID: %lu\n", pid);
    printf("Parent Process ID: %lu\n", ppid);

    return 0;
}
 