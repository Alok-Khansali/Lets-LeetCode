class Solution //Runtime: 96 ms, faster than 99.33% of C++ online submissions for Range Sum of BST.
{
public:
    int sum(TreeNode* head,int l,int r)                             //l = lower_bound and r = upper_bound of the range given
    {
        if(head == NULL)                                            //If an end point is reached then end the traversal
            return 0;
        int x = head->val;                                          //Value at the current node
        
        if(x < l)                                                   //If the value to the left is less than the lower_bound, leave that left sub-tree
            return (sum(head->right,l,r)); 
        
        else if(x > r)                                              //If the value to the right is greater than the upper_bound, leave that right sub-tree
          return (sum(head->left,l,r));                         
        
        //If x lies in thge range, then return x and traverse both the left and right subtrees of the current node
        return (x + sum(head->left,l,r)+ sum(head->right,l,r));
            
    }
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        ios_base::sync_with_stdio(false);                          //Speed 
	      cin.tie(NULL);
        return sum(root,low,high);
    }
};
