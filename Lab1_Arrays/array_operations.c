#include <stdio.h>
#define MAX 100

void insert(int a[], int *n, int pos, int val) {
    for (int i = *n; i >= pos; i--)
        a[i] = a[i-1];        // shift right to make room
    a[pos-1] = val;          // 1-based pos → 0-based index
    (*n)++;
}

void delete(int a[], int *n, int pos) {
    for (int i = pos-1; i < *n-1; i++)
        a[i] = a[i+1];        // shift left to fill gap
    (*n)--;
}

int search(int a[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (a[i] == key) return i;
    return -1;
}

int main() {
    int a[MAX], n, ch, pos, val, idx;
    printf("Enter number of elements: "); scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    while(1) {
        printf("\n1.Traversal 2.Insert 3.Delete 4.Search 5.Exit\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                for(int i=0;i<n;i++) printf("%d ",a[i]); printf("\n"); break;
            case 2:
                printf("Enter position: "); scanf("%d",&pos);
                printf("Enter element: "); scanf("%d",&val);
                insert(a,&n,pos,val);
                printf("Element inserted successfully\n"); break;
            case 3:
                printf("Enter position: "); scanf("%d",&pos);
                delete(a,&n,pos);
                printf("Element deleted successfully\n"); break;
            case 4:
                printf("Enter element: "); scanf("%d",&val);
                idx = search(a,n,val);
                if(idx==-1) printf("Element not found\n");
                else printf("Element found at index %d\n",idx); break;
            case 5: return 0;
        }
    }
}