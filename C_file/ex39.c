#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, seek_time = 0, disk_size = 200;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int req[n];
    printf("Enter the disk request queue:\n");
    for (int i = 0; i < n; i++) scanf("%d", &req[i]);

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (req[i] > req[j]) {
                int temp = req[i]; req[i] = req[j]; req[j] = temp;
            }
        }
    }

    int pos = 0;
    while (pos < n && req[pos] < head) pos++;

    printf("\nC-SCAN Disk Scheduling Sequence: %d", head);
    for (int i = pos; i < n; i++) {
        seek_time += abs(head - req[i]);
        head = req[i];
        printf(" -> %d", head);
    }
    if (pos > 0) {
        seek_time += abs(head - (disk_size - 1));
        seek_time += (disk_size - 1); // Jump to 0
        head = 0;
        printf(" -> %d -> 0", disk_size - 1);
        for (int i = 0; i < pos; i++) {
            seek_time += abs(head - req[i]);
            head = req[i];
            printf(" -> %d", head);
        }
    }

    printf("\nTotal Seek Time: %d\n", seek_time);
    printf("Average Seek Time: %.2f\n", (float)seek_time / n);
    return 0;
}