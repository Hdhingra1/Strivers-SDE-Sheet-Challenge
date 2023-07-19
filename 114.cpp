vector<int> leftView(Node *root)
{
    // Your code here
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int m = q.size();
        auto it = q.front();
        ans.push_back(it->data);
        while (m--)
        {
            it = q.front();
            q.pop();
            if (it->left)
                q.push(it->left);
            if (it->right)
                q.push(it->right);
        }
    }
    return ans;
}