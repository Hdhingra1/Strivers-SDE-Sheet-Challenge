#include <bits/stdc++.h>
/************************************************************
    Following is the Binary Search Tree node structure

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void findKthLarge(TreeNode<int> *root, int &ans, int &k)
{
    if (!root || k <= 0)
        return;
    findKthLarge(root->right, ans, k);
    k--;
    if (k == 0)
    {
        ans = root->data;
        return;
    }
    findKthLarge(root->left, ans, k);
}

int KthLargestNumber(TreeNode<int> *root, int k)
{
    int ans = -1;
    findKthLarge(root, ans, k);
    return ans;
}
