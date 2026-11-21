#include <stdio.h>
#include <string.h>

struct {
    char dname[20], fname[20][20];
    int fcnt;
} dir[10];

int main() {
    int dcnt = 0, ch, i, k;
    char d[20], f[20];

    while (1) {
        printf("\n1. Create Directory\t2. Create File\t3. Display\t4. Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter directory name: ");
                scanf("%s", dir[dcnt].dname);
                dir[dcnt++].fcnt = 0;
                break;
            case 2:
                printf("Enter directory name: ");
                scanf("%s", d);
                for (i = 0; i < dcnt; i++) {
                    if (strcmp(d, dir[i].dname) == 0) {
                        printf("Enter file name: ");
                        scanf("%s", dir[i].fname[dir[i].fcnt++]);
                        break;
                    }
                }
                break;
            case 3:
                for (i = 0; i < dcnt; i++) {
                    printf("\nDirectory: %s -> ", dir[i].dname);
                    for (k = 0; k < dir[i].fcnt; k++) printf("%s ", dir[i].fname[k]);
                }
                printf("\n");
                break;
            case 4:
                return 0;
        }
    }
}