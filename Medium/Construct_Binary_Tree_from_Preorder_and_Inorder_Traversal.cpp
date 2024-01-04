// Post order's first is the root of the tree [ L R Root ]
// Inorder's first is the left most and last is the right most node of a Binary tree
// In the beginning its self we know three elements , where the tree begins and where it ends
// find the position of root in the inorder
// all elements to the left of this element belong to its left subtree, say x elements
// now x elements to the right of this elememt in the preorder are of left subtree(LST)
// all elements to the right of this element belong to its right subtree, say y
// now y elements from the right(or remaining) in the postorder are of right subtree(RST)
// now recursively do this for all subtrees and u r done
class Solution
{
public:
    unordered_map<int, int> inp;
    TreeNode* build(vector<int>& p, int i, int  x, int y)
    {
        TreeNode* node = new TreeNode(p[i]);
        int m = inp[p[i]], l = m - x, rl = y - m;
        if(l > 0)
        node->left = build(p, i + 1 , x, m-1);
        if( rl > 0)
        node->right = build(p, i + l + 1 , m + 1, y);
        return node;
    }
    TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
            inp[inorder[i]] = i;
        return build(preorder, 0,  0, inorder.size() - 1);
    }
};