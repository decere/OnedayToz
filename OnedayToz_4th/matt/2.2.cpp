#include <iostream>

typedef struct stack_node {
    int val;
    struct stack_node *next;
} node;

node *root_node;

using namespace std;

void push(node **root, int val) {

    node *n;

    n = new node;
    n->val = val;
    n->next = *root;
    *root = n;
}

int pop(node **root, int *val) {

    node *tmp;

    if (*root == NULL)
        return -1;

    tmp = *root;
    *val = tmp->val;
    *root = (*root)->next;
    delete tmp;

    return 0;
}

int main(int argc, char* argv[]) {

    int value;

    push(&root_node, 10);
    push(&root_node, 12);
    push(&root_node, 100);
    push(&root_node, 5);

    while(!pop(&root_node, &value)) {
        cout << " " << value;
    }
}
