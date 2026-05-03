#include <stdio.h>
#include <stdlib.h>

struct node { int data; struct node *next; };
struct node *head = NULL;

void insert_begin(int x) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) { printf("Overflow\n"); return; }
    newnode->data = x;
    if (head == NULL) { newnode->next = newnode; head = newnode; return; }
    struct node *temp = head;
    while (temp->next != head) temp = temp->next;
    temp->next = newnode;
    newnode->next = head;
    head = newnode;
}

void insert_end(int x) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) { printf("Overflow\n"); return; }
    newnode->data = x;
    if (head == NULL) { newnode->next = newnode; head = newnode; return; }
    struct node *temp = head;
    while (temp->next != head) temp = temp->next;
    temp->next = newnode;
    newnode->next = head;
}

void delete_begin() {
    if (head == NULL) { printf("Underflow\n"); return; }
    struct node *temp = head;
    if (head->next == head) { head = NULL; free(temp); return; }
    struct node *last = head;
    while (last->next != head) last = last->next;
    head = head->next;
    last->next = head;
    free(temp);
}

void delete_after(int item) {
    if (head == NULL) { printf("Underflow\n"); return; }
    struct node *temp = head;
    while (temp->data != item) {
        temp = temp->next;
        if (temp == head) { printf("Item not found\n"); return; }
    }
    struct node *del = temp->next;
    if (del == head) {
        struct node *last = head;
        while (last->next != head) last = last->next;
        temp->next = head->next;
        head = head->next;
        last->next = head;
        free(del);
        return;
    }
    temp->next = del->next;
    free(del);
}

void display() {
    if (head == NULL) { printf("List empty\n"); return; }
    struct node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int ch, x, item;
    while (1) {
        printf("\n1.InsertBegin 2.InsertEnd 3.DeleteBegin 4.DeleteAfter 5.Display 6.Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1: scanf("%d", &x); insert_begin(x); break;
            case 2: scanf("%d", &x); insert_end(x); break;
            case 3: delete_begin(); break;
            case 4: scanf("%d", &item); delete_after(item); break;
            case 5: display(); break;
            case 6: exit(0);
        }
    }
}