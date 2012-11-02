// Basic data structure
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
        process_item(l->item);
        traverse_tree(l->right);
    }
}

insert_tree(tree **l, item_type x, tree *parent)
{
    tree *p;
    /* temporary pointer */
    if (*l == NULL) {
        p = malloc(sizeof(tree)); /* allocate new node */
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
