#include <stdio.h>
#include <stdlib.h>

struct Block {
    int blockNumber;
    char data[256];
};

int main() {
    FILE *file;
    struct Block block;
    int blockNumber;
    long indexBlock[100];
    for (int i = 0; i < 100; i++) indexBlock[i] = -1;

    file = fopen("indexed_file.dat", "wb");
    if (file == NULL) { printf("Error opening file.\n"); return 1; }

    printf("Enter blocks (Enter '0' as block number to exit):\n");
    while (1) {
        printf("Block Number (1-99): ");
        scanf("%d", &block.blockNumber);
        if (block.blockNumber == 0) break;
        printf("Data: ");
        scanf(" %[^\n]", block.data);
        indexBlock[block.blockNumber] = ftell(file);
        fwrite(&block, sizeof(struct Block), 1, file);
    }
    fclose(file);

    file = fopen("indexed_file.dat", "rb");
    while (1) {
        printf("\nEnter the block number to read (0 to exit): ");
        scanf("%d", &blockNumber);
        if (blockNumber == 0) break;

        if (indexBlock[blockNumber] == -1) {
            printf("Block not found.\n");
        } else {
            fseek(file, indexBlock[blockNumber], SEEK_SET);
            fread(&block, sizeof(struct Block), 1, file);
            printf("Block Number: %d\nData: %s\n", block.blockNumber, block.data);
        }
    }
    fclose(file);
    return 0;
}