class Solution
{
public:
    bool yes(TreeNode *f, TreeNode *s)
    {
        if (f == NULL && s == NULL)
            return true;
        if (f == NULL || s == NULL || f->val != s->val)
            return false;
        return yes(f->left, s->right) && yes(f->right, s->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;

        return yes(root->left, root->right);
    }
};