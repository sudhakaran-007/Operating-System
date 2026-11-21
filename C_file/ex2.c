#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char src[100], dest[100], buffer[1024];
    int fd1, fd2;
    ssize_t bytesRead;

    printf("Enter the source filename: ");
    scanf("%s", src);
    fd1 = open(src, O_RDONLY);
    if (fd1 < 0) {
        perror("Cannot open source file");
        exit(1);
    }

    printf("Enter the destination filename: ");
    scanf("%s", dest);
    fd2 = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 < 0) {
        perror("Cannot open destination file");
        close(fd1);
        exit(1);
    }

    while ((bytesRead = read(fd1, buffer, sizeof(buffer))) > 0) {
        write(fd2, buffer, bytesRead);
    }

    printf("Contents copied to %s\n", dest);
    close(fd1);
    close(fd2);
    return 0;
}