class Solution // 94.88% faster
{              // 29.97% space efficient
public:
    bool test = 1; // Bool value to store the answer, intially assuming that the tree is balanced
    int chc(TreeNode *r)
    {
        if (r == NULL) // If the end point is reached, return the value 0;
            return 0;
        int lt = 1 + chc(r->left), rt = 1 + chc(r->right); // Check for the maximum left and right depth for a given node
        if (abs(rt - lt) > 1)                              // If the difference between the left and right depth is greater than 1,
            test = 0;                                      // set the answer as false
        return max(rt, lt);                                // return the maximum depth
    }
    bool isBalanced(TreeNode *root)
    {
        ios_base::sync_with_stdio(0);
        chc(root);
        return test;
    }
};