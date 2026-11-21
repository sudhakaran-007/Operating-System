#include <stdio.h>

int main() {
    int b[20], f[20], nb, nf, temp, lowest = 10000;
    static int bf[20], ff[20];

    printf("Memory Management Scheme - Best Fit\n");
    printf("Enter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of files: ");
    scanf("%d", &nf);

    printf("Enter the size of the blocks:\n");
    for (int i = 1; i <= nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }

    printf("Enter the size of the files:\n");
    for (int i = 1; i <= nf; i++) {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }

    for (int i = 1; i <= nf; i++) {
        for (int j = 1; j <= nb; j++) {
            if (bf[j] != 1) {
                temp = b[j] - f[i];
                if (temp >= 0 && lowest > temp) {
                    ff[i] = j;
                    lowest = temp;
                }
            }
        }
        bf[ff[i]] = 1;
        lowest = 10000;
    }

    printf("\nFile_no\tFile_size\tBlock_no\tBlock_size\tFragment\n");
    for (int i = 1; i <= nf; i++) {
        if (ff[i] != 0)
            printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i, f[i], ff[i], b[ff[i]], b[ff[i]] - f[i]);
        else
            printf("%d\t%d\t\tNot Allocated\n", i, f[i]);
    }
    return 0;
}