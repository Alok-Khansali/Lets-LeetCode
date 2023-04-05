// Post order's last is the root of the tree [ L R Root ]
// Inorder's first is the left most and last is the right most node of a Binary tree
// In the beginning its self we know three elements , where the tree begins and where it ends
// find the position of root in the order
// all elements to the left of this element belong to its left subtree, say x elements
// now x elements from to the left of this element in the postorder are of left subtree(LST)
// all elements to the right of this element belong to its right subtree, say y
// now y elements from the left(or remaining) in the postorder are of right subtree(RST)
// now recursively do this for all subtrees and u r done
class Solution
{
public:
    unordered_map<int, int> inp;
    TreeNode *build(vector<int> &p, int st_in_post, int index, int st_pt_of_in, int end_pt_in_in)
    {
        TreeNode *node = new TreeNode(p[index]);
        int pos_in_inorder = inp[p[index]];
        int lst_size = pos_in_inorder - st_pt_of_in, rst_size = end_pt_in_in - pos_in_inorder;
        if (lst_size > 0)
            node->left = build(p, st_in_post, st_in_post + lst_size - 1, st_pt_of_in, pos_in_inorder - 1);
        if (rst_size > 0)
            node->right = build(p, st_in_post + lst_size, index - 1, pos_in_inorder + 1, end_pt_in_in);
        return node;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for (int i = 0; i < inorder.size(); i++)
            inp[inorder[i]] = i;
        return build(postorder, 0, inorder.size() - 1, 0, inorder.size() - 1);
    }
};