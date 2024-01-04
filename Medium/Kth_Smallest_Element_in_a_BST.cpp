class Solution {  //Runtime: 11 ms, faster than 98.64% of C++ online submissions for Kth Smallest Element in a BST.
//Memory Usage: 24 MB, less than 87.81% of C++ online submissions for Kth Smallest Element in a BST.
public:
    int ans = -1;
    void kth(TreeNode* r,int &k)
    {
        if(r == NULL)
            return;
        kth(r->left, k);
        k -= 1;
        if(k == 0)
        {
            ans = r->val;
            return;
        }
        kth(r->right,k);
    }
    int kthSmallest(TreeNode* root, int k) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        kth(root,k);
        return ans;
    }
};