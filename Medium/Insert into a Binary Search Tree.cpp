class Solution { //Runtime: 72 ms, faster than 98.84 % of C++ online submissions for Insert into a Binary Search Tree.
                 //Memory Usage: 56.8 MB, less than 80.92% of C++ online submissions for Insert into a Binary Search Tree.
public:
    TreeNode* insertIntoBST(TreeNode* root, int val)  //When I realised I Know something about recursion
    {
        if(root == NULL)
            return (new TreeNode(val));
        if(val>root->val)
            root->right = insertIntoBST(root->right, val);
        else
            root->left = insertIntoBST(root->left, val);
        return root;
    }
};
/* //First Approach is not always the best like this one , took 111ms
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
        TreeNode *trav = root;
        if(root == NULL)    //Empty means send the new node
            return (new TreeNode(val));
        while(trav != NULL)
        {
            if(trav->val < val)          //If the current is less, go to the right
            {
               if(trav->right == NULL)   //If no node is Available, time to return 
               {
                   trav->right = new TreeNode(val);
                   return root;
               }
               trav = trav->right; 
            }
            else                        //Else go to the left
            {
               if(trav->left == NULL)  //If no node is Available, time to return 
               {
                   trav->left = new TreeNode(val);
                   return root;
               }
               trav = trav->left;
            }
        }
        return root;
    }
};
*/
