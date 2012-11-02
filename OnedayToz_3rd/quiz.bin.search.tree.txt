// Basic data structure
typedef struct tree {
    item_type item;    /* data item */
    struct tree *parent;
    struct tree *left;
    struct tree *right;
} tree;

tree *search_tree(tree *l, item_type x)
{
}

tree *find_minimum(tree *t)
{
}

void traverse_tree(tree *l)
{
}

insert_tree(tree **l, item_type x, tree *parent)
{
}
