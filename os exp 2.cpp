#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int source, destination;
    char buffer[1024];
    int bytesRead;
    source = open("source.txt", O_RDONLY);

    if (source < 0)
    {
        printf("Unable to open source file\n");
        exit(1);
    }
    destination = open("destination.txt",
                       O_CREAT | O_WRONLY | O_TRUNC,
                       0644);

    if (destination < 0)
    {
        printf("Unable to create destination file\n");
        close(source);
        exit(1);
    }
    while ((bytesRead = read(source, buffer, sizeof(buffer))) > 0)
    {
        write(destination, buffer, bytesRead);
    }

    printf("File copied successfully.\n");
    close(source);
    close(destination);

    return 0;
}