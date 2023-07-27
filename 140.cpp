#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

bool help(BinaryTreeNode<int> *root, int l, int u)
{
    if (root == NULL)
        return true;
    if (root->data > u || root->data < l)
        return false;
    return help(root->right, root->data, u) && help(root->left, l, root->data);
}
bool validateBST(BinaryTreeNode<int> *root)
{
    // Write your code here
    return help(root, -INT_MIN, INT_MAX);
}