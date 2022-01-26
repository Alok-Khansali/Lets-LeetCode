//Runtime: 179 ms, faster than 46.68% of C++ online submissions for All Elements in Two Binary Search Trees.
//Memory Usage: 84.6 MB, less than 67.43% of C++ online submissions for All Elements in Two Binar
class Solution {     //The approach I didnt think about (or understood in the beginning), but understood from the discussion just beacuse it might come handy some day                    
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        stack<TreeNode*> st1,st2;
        vector<int> ans;
        while(root1 != NULL || root2 != NULL || !st1.empty() || !st2.empty())  //If there are Untraversed-Nodes or Filled Stacks Continue, 
        {
            while(root1 != NULL)                                               //Get All the left Side Nodes of the current Node
            {
                st1.push(root1);
                root1 = root1->left;                                           //Inorder traversal, to get the sorted array
            }
            while(root2 != NULL)                                               //Get All the Left Side Nodes of the current node
            {
                st2.push(root2);
                root2 = root2->left;                                           //Inorder traversal, to get the sorted array
            }
            if(st2.empty() || (!st1.empty() && st1.top()->val<=st2.top()->val)) //If stack 2 is empty or the top of stack 1 is less than the top of stack 2
            {
                root1 = st1.top();                                              //Store the top node in stack 1
                st1.pop();                                                      //Pop it from the stack 1
                ans.push_back(root1->val);                                      //Send the value of the stored node into the answer vector
                root1 = root1->right;                                           //time to do the right thing, to get all the nodes on the left side(Smaller valued)
            } 
            else                                                                //Stack2 Supreme mode on
            {
                root2 = st2.top();                                              //Store the top node in Stack2
                st2.pop();                                                      //Remove it from the top of the stack
                ans.push_back(root2->val);                                      //Send the value held by the stored node into the answer vector
                root2 = root2->right;                                           //time to do the right thing, to get all the nodes on the left side(Smaller valued)
            }
        }
        return ans;                                                             //Return the container that made you work so hard
    }
};
/*   //My First Approach, No-Stack-Approach
class Solution {     Runtime: 185 ms, faster than 44.34% of C++ online submissions for All Elements in Two Binary Search Trees.
public:
    void get_elements(TreeNode *root, vector<int> &a)        //Inorder Traversal, to get elements in Ascending order
    {
        if(root == NULL)
            return;
        get_elements(root->left,a);                          //Left
        a.push_back(root->val);                              //Root
        get_elements(root->right,a);                         //Right
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        ios_base::sync_with_stdio(false);                    //Speed game
        cin.tie(NULL);
        vector<int> one,two,v;
        get_elements(root1,one);
        get_elements(root2,two);
        int i = 0, j = 0;
        while(i < one.size() && j < two.size())              //Merging the two sorted vectors into a new vector
            if(one[i] < two[j])
            {
                v.push_back(one[i]);
                ++i;
            }
            else
            {
                v.push_back(two[j]);
                ++j;
            }
        while(i < one.size())
        {
            v.push_back(one[i]);
            i++; 
        }
        while(j < two.size())
        {
            v.push_back(two[j]);
            j++;
        }
        return v;
    }
};


//APPROACH 2,using STL, Slightly Space effecient 
//Runtime: 257 ms, faster than 20.75% of C++ online submissions for All Elements in Two Binary Search Trees.
//Memory Usage: 84.3 MB, less than 91.67% of C++ online submissions for All Elements in Two Binary Search Trees.
class Solution {     //Non-Stack Approach, stl
public:
    void get_elements(TreeNode *root, vector<int> &a)        //Inorder Traversal, to get elements in Ascending order
    {
        if(root == NULL)
            return;
        get_elements(root->left,a);                          //Left
        a.push_back(root->val);                              //Root
        get_elements(root->right,a);                         //Right
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> v;
        get_elements(root1,v);
        get_elements(root2,v);
        sort(v.begin(),v.end());
        return v;
    }
};


//APPROACH 3
//Slighlty Modified use of STL
//Runtime: 226 ms, faster than 31.37% of C++ online submissions for All Elements in Two Binary Search Trees.
//Memory Usage: 85.5 MB, less than 44.06% of C++ online submissions for All Elements in Two Binary Search Trees.
class Solution {     //Non-Stack Approach, stl
public:
    void get_elements(TreeNode *root, vector<int> &a)        //Inorder Traversal, to get elements in Ascending order
    {
        if(root == NULL)
            return;
        get_elements(root->left,a);                          //Left
        a.push_back(root->val);                              //Root
        get_elements(root->right,a);                         //Right
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> one,two;
        get_elements(root1,one);
        get_elements(root2,two);
        vector<int> ans(one.size()+two.size());
        merge(one.begin(), one.end(), two.begin(), two.end(), ans.begin());  //Sorts and combines together, in ascending fashion
        return ans;
    }
};
*/