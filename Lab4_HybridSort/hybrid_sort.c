#include <stdio.h>
#include <time.h>
#define THRESHOLD 10

void quickSort(int a[], int low, int high);
void hybridSort(int a[], int low, int high);
int partition(int a[], int low, int high);
void insertionSort(int a[], int low, int high);

int main() {
    int a[10000], b[10000], n, i;
    clock_t start, end;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    start = clock();
    quickSort(a, 0, n - 1);
    end = clock();
    printf("Time taken by Quick Sort: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    start = clock();
    hybridSort(b, 0, n - 1);
    end = clock();
    printf("Time taken by Hybrid Sort: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    printf("\nSorted array using Hybrid Sort:\n");
    for (i = 0; i < n; i++)
        printf("%d ", b[i]);

    return 0;
}

void insertionSort(int a[], int low, int high) {
    int i, j, key;
    for (i = low + 1; i <= high; i++) {
        key = a[i];
        j = i - 1;
        while (j >= low && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            int t = a[i]; a[i] = a[j]; a[j] = t;
        }
    }
    int t = a[i + 1]; a[i + 1] = a[high]; a[high] = t;
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

void hybridSort(int a[], int low, int high) {
    if (low < high) {
        int size = high - low + 1;
        if (size <= THRESHOLD)
            insertionSort(a, low, high);
        else {
            int p = partition(a, low, high);
            hybridSort(a, low, p - 1);
            hybridSort(a, p + 1, high);
        }
    }
}