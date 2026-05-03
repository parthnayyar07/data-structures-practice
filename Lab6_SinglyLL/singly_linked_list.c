#include <stdio.h>
#include <stdlib.h>

struct node { int data; struct node *next; };
struct node *head = NULL;

void insert_begin(int x) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = head;
    head = newnode;
}

void insert_end(int x) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if (head == NULL) { head = newnode; return; }
    struct node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newnode;
}

void insert_before(int item, int x) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    struct node *temp = head, *prev = NULL;
    while (temp != NULL && temp->data != item) {
        prev = temp;
        temp = temp->next;
    }
    newnode->next = temp;
    if (prev == NULL) head = newnode;
    else prev->next = newnode;
}

void delete_begin() {
    struct node *temp = head;
    head = head->next;
    free(temp);
}

void delete_end() {
    struct node *temp = head, *prev;
    while (temp->next != NULL) { prev = temp; temp = temp->next; }
    prev->next = NULL;
    free(temp);
}

void delete_after(int item) {
    struct node *temp = head;
    while (temp != NULL && temp->data != item) temp = temp->next;
    struct node *del = temp->next;
    temp->next = del->next;
    free(del);
}

void display() {
    struct node *temp = head;
    while (temp != NULL) { printf("%d ", temp->data); temp = temp->next; }
    printf("\n");
}

int main() {
    int ch, x, item;
    while (1) {
        printf("\n1.InsertBegin 2.InsertEnd 3.InsertBefore 4.DeleteBegin 5.DeleteEnd 6.DeleteAfter 7.Display 8.Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Value: "); scanf("%d", &x); insert_begin(x); break;
            case 2: printf("Value: "); scanf("%d", &x); insert_end(x); break;
            case 3: printf("Item value: "); scanf("%d %d", &item, &x); insert_before(item, x); break;
            case 4: delete_begin(); break;
            case 5: delete_end(); break;
            case 6: printf("Item: "); scanf("%d", &item); delete_after(item); break;
            case 7: display(); break;
            case 8: exit(0);
        }
    }
}