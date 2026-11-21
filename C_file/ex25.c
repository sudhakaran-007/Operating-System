#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    int fd = open("foo.txt", O_RDWR | O_CREAT, 0644);
    write(fd, "Operating Systems Lab", 21);

    // fcntl
    int flags = fcntl(fd, F_GETFL);
    printf("File descriptor flags: %d\n", flags);

    // lseek
    lseek(fd, 10, SEEK_SET);
    char buf[20] = {0};
    read(fd, buf, 7);
    printf("Read after lseek(10): %s\n", buf);
    close(fd);

    // stat
    struct stat fileStat;
    stat("foo.txt", &fileStat);
    printf("File Size: %ld bytes\n", fileStat.st_size);

    // opendir & readdir
    DIR *d = opendir(".");
    struct dirent *dir;
    printf("Current directory files:\n");
    while ((dir = readdir(d)) != NULL) {
        printf("  %s\n", dir->d_name);
    }
    closedir(d);
    return 0;
}