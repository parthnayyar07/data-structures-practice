#include <stdio.h>
#include <stdlib.h>

struct node { int data; struct node *left, *right; };
struct node *queue[100];
int front = 0, rear = 0;

void enqueue(struct node *x) { queue[rear++] = x; }
struct node* dequeue() { return queue[front++]; }

struct node* create() {
    int x;
    printf("Enter root: ");
    scanf("%d", &x);
    if (x == -1) return NULL;
    struct node *root = (struct node*)malloc(sizeof(struct node));
    root->data = x;
    root->left = root->right = NULL;
    enqueue(root);
    while (front < rear) {
        struct node *temp = dequeue();
        printf("Left of %d: ", temp->data);
        scanf("%d", &x);
        if (x != -1) {
            temp->left = (struct node*)malloc(sizeof(struct node));
            temp->left->data = x;
            temp->left->left = temp->left->right = NULL;
            enqueue(temp->left);
        }
        printf("Right of %d: ", temp->data);
        scanf("%d", &x);
        if (x != -1) {
            temp->right = (struct node*)malloc(sizeof(struct node));
            temp->right->data = x;
            temp->right->left = temp->right->right = NULL;
            enqueue(temp->right);
        }
    }
    return root;
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int sum(struct node *root) {
    if (root == NULL) return 0;
    return root->data + sum(root->left) + sum(root->right);
}

int leafCount(struct node *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return leafCount(root->left) + leafCount(root->right);
}

int main() {
    struct node *root = create();
    printf("\nInorder: ");   inorder(root);
    printf("\nPreorder: ");  preorder(root);
    printf("\nPostorder: "); postorder(root);
    printf("\nSum: %d", sum(root));
    printf("\nLeaf Nodes: %d\n", leafCount(root));
    return 0;
}