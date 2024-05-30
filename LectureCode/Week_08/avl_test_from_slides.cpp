//
// Created by esben on 3/20/2024.
//

#include "avl_tree.h"

int main()
{
    AvlTree<int> tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(1);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);
    tree.insert(6);
    tree.insert(8);

    tree.printTree();
}