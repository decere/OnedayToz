#include <iostream>
#include <cstdlib>

using namespace std;

// Basic data structure
typedef int item_type;
typedef struct tree {
    item_type item;    /* data item */
    struct tree *parent;
    struct tree *left;
    struct tree *right;
} tree;

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

void traverse_tree(tree *l)
{
    if (l != NULL) {
        traverse_tree(l->left);
#if 0
        process_item(l->item);
#else
        cout << l->item << endl;
#endif
        traverse_tree(l->right);
    }
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

int main(void) {

    tree *root = NULL;
    tree *tmp = NULL;

    cout << "inserting...\n";
    insert_tree(&root, 100, NULL);
    insert_tree(&root, 10, NULL);
    insert_tree(&root, 200, NULL);
    insert_tree(&root, 50, NULL);
    insert_tree(&root, 123, NULL);
    insert_tree(&root, 400, NULL);

    cout << "traversing...\n";
    traverse_tree(root);

    cout << "searching...50";
    tmp = search_tree(root, 50);
    if (tmp != NULL) {
        if (tmp->item == 50)
            cout << " OK\n";
        else
            cout << " Not match!\n";
    }
    else
        cout << " Can't find it!\n";

    cout << "deleting...50\n";
    delete_tree(&root, 50);

    cout << "traversing again...\n";
    traverse_tree(root);

    cout << "deleting...123\n";
    delete_tree(&root, 123);

    cout << "traversing again...\n";
    traverse_tree(root);

    cout << "deleting the root..." << root->item << endl;
    delete_tree(&root, root->item);

    cout << "traversing again...\n";
    traverse_tree(root);

    return 0;
}
