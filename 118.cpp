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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<pair<TreeNode *, pair<int, int>>> q;
        map<int, vector<pair<int, int>>> mp;
        q.push({root, {0, 0}});
        while (!q.empty())
        {
            TreeNode *t = q.front().first;
            int l = q.front().second.first;
            int y = q.front().second.second;
            mp[l].push_back({y, t->val});
            q.pop();
            if (t->left)
                q.push({t->left, {l - 1, y + 1}});
            if (t->right)
                q.push({t->right, {l + 1, y + 1}});
        }
        for (auto it : mp)
        {
            sort(it.second.begin(), it.second.end());
            vector<int> temp;
            for (auto x : it.second)
            {
                temp.push_back(x.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};