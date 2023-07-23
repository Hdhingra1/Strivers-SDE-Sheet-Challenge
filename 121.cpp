/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> ans;
        while (!q.empty())
        {
            int m = q.size();
            vector<int> temp;
            while (m--)
            {
                auto it = q.front();
                q.pop();
                if (it->left)
                    q.push(it->left);
                if (it->right)
                    q.push(it->right);
                temp.push_back(it->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};