#include <iostream>
#include <cstdlib>

// Basic data structure
typedef int item_type;
typedef struct tree {
    item_type item;    /* data item */
    struct tree *parent;
    struct tree *left;
    struct tree *right;
} tree;

typedef int item_type;
typedef struct stack_node {
    item_type item;
    struct stack_node *next;
} node;

node *root_node;
tree *root_tree;

using namespace std;

tree *search_tree(tree *l, item_type x)
{
    if (l == NULL) return(NULL);
    if (l->item == x) return(l);
    if (x < l->item)
        return( search_tree(l->left, x) );
    else
        return( search_tree(l->right, x) );
}

tree *find_minimum(tree *t)
{
    tree *min;
    /* pointer to minimum */
    if (t == NULL) return(NULL);
    min = t;
    while (min->left != NULL)
        min = min->left;
    return(min);
}

void
insert_tree(tree **l, item_type x, tree *parent)
{
    tree *p;
    /* temporary pointer */
    if (*l == NULL) {
        p = static_cast<tree*>(malloc(sizeof(tree))); /* allocate new node */
        p = new tree; /* allocate new node */
        p->item = x;
        p->left = p->right = NULL;
        p->parent = parent;
        *l = p;
        /* link into parent’s record */
        return;
    }
    if (x < (*l)->item)
        insert_tree(&((*l)->left), x, *l);
    else
        insert_tree(&((*l)->right), x, *l);
}

void
delete_tree(tree **l, item_type x)
{
    tree *p_old = NULL;
    tree *p_new = NULL;
    int attach_new_children = 0;

    p_old = search_tree(*l, x);
    if (p_old == NULL)
        return;

    /* if either left or right is NULL, quite simple case it is. */
    if (p_old->left != NULL && p_old->right == NULL) {
        p_new = p_old->left;
    }
    else if (p_old->left == NULL && p_old->right != NULL) {
        p_new = p_old->right;
    }
    else if (p_old->left == NULL && p_old->right == NULL) {

        p_new = NULL;
    }
    else {
        /* if both left and right tree exist?
         * find the minimum on right side and make it replace with to be deleted.
         */
        p_new = find_minimum(p_old->right);

        /* detach from original position */
        if (p_new->parent->left == p_new)
            p_new->parent->left = p_new->right;
        else
            p_new->parent->right = p_new->right;

        attach_new_children = 1;
    }

    /* link to the new parent */
    if (p_new)
        p_new->parent = p_old->parent;
    if (p_old->parent != NULL) {
        if (p_old->parent->left == p_old)
            p_old->parent->left = p_new;
        else
            p_old->parent->right = p_new;
    }

    if (attach_new_children) {
        /* link to the new children */
        p_new->left = p_old->left;
        p_old->left->parent = p_new;
        p_new->right = p_old->right;
        p_old->right->parent = p_new;
    }

    if (p_old == *l)
        *l = p_new;

    delete p_old;

    return; 
}

void push(node **root, item_type item) {

    node *n;

    n = new node;
    n->item = item;
    n->next = *root;
    *root = n;

    insert_tree(&root_tree, item, NULL);
}

int pop(node **root, item_type *item) {

    node *tmp;

    if (*root == NULL)
        return -1;

    tmp = *root;
    *item = tmp->item;
    *root = (*root)->next;
    delete tmp;

    delete_tree(&root_tree, *item);

    return 0;
}

int minimum(node *root, item_type *item) {

    tree *tmp = find_minimum(root_tree);
    if (tmp == NULL)
        return -1;

    *item = tmp->item;
    return 0;
}

int main(int argc, char* argv[]) {

    item_type value;

    push(&root_node, 10);
    push(&root_node, 12);
    push(&root_node, 100);
    push(&root_node, 5);

    if (!minimum(root_node, &value))
        cout << "min value is " << value << endl;

    while(!pop(&root_node, &value)) {
        cout << " " << value;
    }
}
