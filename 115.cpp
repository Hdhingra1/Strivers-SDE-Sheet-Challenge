class Solution
{
public:
    vector<int> bottomView(Node *root)
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

            mp[l] = t->data;

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