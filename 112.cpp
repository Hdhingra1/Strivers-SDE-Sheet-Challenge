class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        TreeNode *cur = root;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            if (cur == NULL)
            {
                s.pop();

                cur = s.top();
            }
            while (cur != NULL)
            {
                ans.push_back(cur->val);
                s.push(cur->left);
                cur = cur->left;
            }
            s.pop();
            cur = s.top();
            s.push(cur->right);
            cur = cur->right;
        }
        return ans;
    }
};