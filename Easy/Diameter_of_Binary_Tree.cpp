class Solution // Approach 1
{ // i guess, its just about getting the max of left depth and right depth about any node and getting the max of all P.S. I was right
public:
    int mx = 0;
    int chc(TreeNode *r)
    {
        if (r == NULL)
            return 0;
        int lt = 1 + chc(r->left), rt = 1 + chc(r->right);
        mx = max(mx, lt + rt - 2);
        return max(lt, rt);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        chc(root);
        return mx;
    }
};
// Approach 2: Slight modification
class Solution
{
public:
    int find(TreeNode *root, int &dia)
    {
        if (root == NULL)
            return 0;
        int l = find(root->left, dia), r = find(root->right, dia);
        dia = max(l + r, dia);
        return 1 + max(l, r);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int dia = 0;
        find(root, dia);
        return dia;
    }
};