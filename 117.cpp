#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    stack<pair<BinaryTreeNode<int> *, int>> s;
    if (root == NULL)
        return {};
    s.push({root, 1});
    vector<vector<int>> ans(3);
    while (!s.empty())
    {
        auto it = s.top();
        s.pop();
        if (it.second == 1)
        {
            ans[1].push_back(it.first->data);
            s.push({it.first, 2});
            if (it.first->left)
            {
                s.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            ans[0].push_back(it.first->data);
            s.push({it.first, 3});
            if (it.first->right)
            {
                s.push({it.first->right, 1});
            }
        }
        else if (it.second == 3)
        {
            ans[2].push_back(it.first->data);
            // if(it.first->right){
            //     s.push({it.first->right,1});
            // }
        }
    }
    return ans;
}