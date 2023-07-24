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

int solve(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int left = 1 + solve(root->left);
    int right = 1 + solve(root->right);
    return max(left, right);
}
bool isBalancedBT(BinaryTreeNode<int> *root)
{
    int from_left = 0;
    int from_right = 0;
    if (root == NULL)
        return true;
    if (root->left != NULL)
        from_left = solve(root->left);
    if (root->right != NULL)
        from_right = solve(root->right);
    if (abs(from_left - from_right) > 1)
        return false;
    return isBalancedBT(root->left) && isBalancedBT(root->right);
    // Write your code here.
}