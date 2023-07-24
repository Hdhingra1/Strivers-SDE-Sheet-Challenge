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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        int level = 0;
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int s = q.size();
            vector<int> v;
            level++;
            while (s--)
            {
                auto it = q.front();
                v.push_back(it->val);
                q.pop();
                if (it->left != NULL)
                {
                    q.push(it->left);
                }
                if (it->right != NULL)
                {
                    q.push(it->right);
                }
            }
            if (level % 2 == 0)
            {
                reverse(v.begin(), v.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};