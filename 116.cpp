class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        queue<pair<Node *, int>> q;
        map<int, int> mp;
        q.push({root, 0});
        while (!q.empty())
        {
            Node *t = q.front().first;
            int l = q.front().second;
            if (mp[l] == 0)
            {
                mp[l] = t->data;
            }
            q.pop();
            if (t->left)
                q.push({t->left, l - 1});
            if (t->right)
                q.push({t->right, l + 1});
        }
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
