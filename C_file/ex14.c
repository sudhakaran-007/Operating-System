#include <stdio.h>
#include <string.h>

struct
{
    char dname[20], fname[20][20];
    int fcnt;
} dir;

int main()
{
    int ch;
    char f[20];
    dir.fcnt = 0;

    printf("Enter name of directory: ");
    scanf("%s", dir.dname);

    while (1)
    {
        printf("\n1. Create File\t2. Delete File\t3. Search File\t4. Display Files\t5. Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the name of the file: ");
            scanf("%s", dir.fname[dir.fcnt++]);
            break;
        case 2:
            printf("Enter the name of the file: ");
            scanf("%s", f);
            for (int i = 0; i < dir.fcnt; i++)
            {
                if (strcmp(f, dir.fname[i]) == 0)
                {
                    printf("File %s is deleted.\n", f);
                    strcpy(dir.fname[i], dir.fname[--dir.fcnt]);
                    break;
                }
            }
            break;
        case 3:
            printf("Enter the name of the file: ");
            scanf("%s", f);
            for (int i = 0; i < dir.fcnt; i++)
            {
                if (strcmp(f, dir.fname[i]) == 0)
                {
                    printf("File %s is found.\n", f);
                    break;
                }
            }
            break;
        case 4:
            printf("Directory: %s\nFiles: ", dir.dname);
            for (int i = 0; i < dir.fcnt; i++)
                printf("%s ", dir.fname[i]);
            printf("\n");
            break;
        case 5:
            return 0;
        }
    }
}