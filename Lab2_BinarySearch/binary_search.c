#include <stdio.h>

int Binsrch(int a[], int low, int high, int key);

int main() {
    int a[100], n, key, i, pos;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements in sorted order:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    pos = Binsrch(a, 0, n - 1, key);
    if (pos == -1)
        printf("Element not found\n");
    else
        printf("Element found at index %d\n", pos);
    return 0;
}

int Binsrch(int a[], int low, int high, int key) {
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (a[mid] == key)
        return mid;
    else if (a[mid] > key)
        return Binsrch(a, low, mid - 1, key);
    else
        return Binsrch(a, mid + 1, high, key);
}