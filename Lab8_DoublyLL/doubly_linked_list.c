#include <stdio.h>
#include <stdlib.h>

struct node { int data; struct node *prev, *next; };
struct node *head = NULL;

void insert_begin(int x) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) { printf("Overflow\n"); return; }
    newnode->data = x;
    newnode->prev = NULL;
    newnode->next = head;
    if (head != NULL) head->prev = newnode;
    head = newnode;
}

void insert_end(int x) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) { printf("Overflow\n"); return; }
    newnode->data = x;
    newnode->next = NULL;
    if (head == NULL) { newnode->prev = NULL; head = newnode; return; }
    struct node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
}

void insert_before(int item, int x) {
    struct node *temp = head;
    while (temp != NULL && temp->data != item) temp = temp->next;
    if (temp == NULL) { printf("Item not found\n"); return; }
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->prev = temp->prev;
    newnode->next = temp;
    if (temp->prev != NULL) temp->prev->next = newnode;
    else head = newnode;
    temp->prev = newnode;
}

void insert_after(int item, int x) {
    struct node *temp = head;
    while (temp != NULL && temp->data != item) temp = temp->next;
    if (temp == NULL) { printf("Item not found\n"); return; }
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL) temp->next->prev = newnode;
    temp->next = newnode;
}

void delete_item(int item) {
    if (head == NULL) { printf("Underflow\n"); return; }
    struct node *temp = head;
    while (temp != NULL && temp->data != item) temp = temp->next;
    if (temp == NULL) { printf("Item not found\n"); return; }
    if (temp->prev != NULL) temp->prev->next = temp->next;
    else head = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    free(temp);
}

void display_forward() {
    struct node *temp = head;
    while (temp != NULL) { printf("%d ", temp->data); temp = temp->next; }
    printf("\n");
}

void display_backward() {
    struct node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    while (temp != NULL) { printf("%d ", temp->data); temp = temp->prev; }
    printf("\n");
}

int main() {
    int ch, x, item;
    while (1) {
        printf("\n1.InsertBegin 2.InsertEnd 3.InsertBefore 4.InsertAfter 5.DeleteItem 6.DisplayForward 7.DisplayBackward 8.Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1: scanf("%d", &x); insert_begin(x); break;
            case 2: scanf("%d", &x); insert_end(x); break;
            case 3: scanf("%d %d", &item, &x); insert_before(item, x); break;
            case 4: scanf("%d %d", &item, &x); insert_after(item, x); break;
            case 5: scanf("%d", &item); delete_item(item); break;
            case 6: display_forward(); break;
            case 7: display_backward(); break;
            case 8: exit(0);
        }
    }
}