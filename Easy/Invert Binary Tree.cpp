class Solution
{ // Runtime: 4 ms, faster than 52.67% of C++ online submissions for Invert Binary Tree.
  // Memory Usage: 9.8 MB, less than 37.19% of C++ online submissions for Invert Binary Tree.
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
            return root;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int x = q.size();
            for (int i = 0; i < x; i++)
            {
                TreeNode *r = q.front(), *l = r->left, *rgt = r->right;
                q.pop();
                r->left = rgt;
                r->right = l;
                if (l != NULL)
                    q.push(l);
                if (rgt != NULL)
                    q.push(rgt);
            }
        }
        return root;
    }
};