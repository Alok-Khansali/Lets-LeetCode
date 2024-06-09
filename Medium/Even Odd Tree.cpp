class Solution
{
public:
    bool isEvenOddTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        while (!q.empty())
        {
            int len = q.size(), prev = INT_MAX * (level & 1);
            if (level & 1)
            {
                for (int i = 0; i < len; i++)
                {
                    TreeNode *lt = q.front()->left, *rt = q.front()->right, *curr = q.front();
                    q.pop();
                    int x = curr->val;
                    if (x & 1 || x >= prev)
                        return false;
                    prev = x;
                    if (lt)
                        q.push(lt);
                    if (rt)
                        q.push(rt);
                }
            }
            else
            {
                for (int i = 0; i < len; i++)
                {
                    TreeNode *lt = q.front()->left, *rt = q.front()->right, *curr = q.front();
                    q.pop();
                    int x = curr->val;
                    if (x % 2 == 0 || x <= prev)
                        return false;
                    prev = x;
                    if (lt)
                        q.push(lt);
                    if (rt)
                        q.push(rt);
                }
            }
            level++;
        }
        return true;
    }
};