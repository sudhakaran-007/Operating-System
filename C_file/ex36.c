#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Block {
    char data[256];
    struct Block* next;
};

int main() {
    struct Block *firstBlock = NULL, *lastBlock = NULL;
    int blockCount = 0, blockNumber;
    char data[256], choice;

    printf("Linked Allocation Simulation\n");
    while (1) {
        printf("Enter 'W' to write a block, 'R' to read a block, or 'Q' to quit: ");
        scanf(" %c", &choice);
        if (choice == 'Q' || choice == 'q') break;

        if (choice == 'W' || choice == 'w') {
            printf("Enter data for the block: ");
            scanf(" %[^\n]", data);

            struct Block* newBlock = (struct Block*)malloc(sizeof(struct Block));
            strcpy(newBlock->data, data);
            newBlock->next = NULL;

            if (blockCount == 0) {
                firstBlock = lastBlock = newBlock;
            } else {
                lastBlock->next = newBlock;
                lastBlock = newBlock;
            }
            blockCount++;
        } else if (choice == 'R' || choice == 'r') {
            printf("Enter the block number to read (1-%d): ", blockCount);
            scanf("%d", &blockNumber);
            if (blockNumber < 1 || blockNumber > blockCount) {
                printf("Invalid block number.\n");
            } else {
                struct Block* currentBlock = firstBlock;
                for (int i = 1; i < blockNumber; i++) currentBlock = currentBlock->next;
                printf("Block %d Data: %s\n", blockNumber, currentBlock->data);
            }
        }
    }

    while (firstBlock != NULL) {
        struct Block* nextBlock = firstBlock->next;
        free(firstBlock);
        firstBlock = nextBlock;
    }
    return 0;
}