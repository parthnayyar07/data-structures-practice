#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define THRESHOLD 0.7

int hash(int key) {
    return key % SIZE;
}

int linear(int key, int x, int *arr) {
    for (int i = 0; i < SIZE; i++) {
        if (arr[(x + i) % SIZE] == -1) {
            arr[(x + i) % SIZE] = key;
            return 0;
        }
    }
    return -1;
}

void resize(int *arr) {
    int newSize = 2 * SIZE;
    int newTable[newSize];
    for (int i = 0; i < newSize; i++)
        newTable[i] = -1;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] != -1) {
            int newIndex = arr[i] % newSize;
            newTable[newIndex] = arr[i];
        }
    }
    printf("Table resized\n");
}

int main() {
    int n, x, counter = 0;
    printf("No. of inputs: ");
    scanf("%d", &n);
    int arr[SIZE], store[n];

    for (int i = 0; i < SIZE; i++)
        arr[i] = -1;

    printf("Input the %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &store[i]);

    printf("Hashing Start\n");
    for (int i = 0; i < n; i++) {
        x = hash(store[i]);
        linear(store[i], x, arr);
        counter++;
    }

    float loadFactor = (float)counter / SIZE;
    if (loadFactor > THRESHOLD) {
        printf("Rehashing required\n");
        resize(arr);
    }

    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] == -1)
            printf("NULL ");
        else
            printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}