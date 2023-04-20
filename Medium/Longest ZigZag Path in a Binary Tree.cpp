class Solution // Direction = 0, means we went left
{              // Direction = 1, means we went right
public:
    int max_len = 0; // Store the maximum length in the max_lenwer variable
    void Get_Maximum_Length(TreeNode *node, int direction, int curr_length)
    {
        if (node == NULL) // If Node is Null, then its an end point
            return;       // Just return back the control

        max_len = max(max_len, curr_length); // Storing the maximum length so far

        if (direction == 0) // If Direction is 0,
        {                   // i.e. The current Node is the left part of the sequence

            // Now we go right and increase the current length by 1
            Get_Maximum_Length(node->right, 1, curr_length + 1);

            // If we go left again, we will not be making a zigzag sequence
            // And so we have to neglect the current length.
            // And find a path with current node as the starting point
            // Therefore we hold the current node as centre and traverse to the left
            // We send curr_length as 2, because if the left exists then surely there will
            // At least Two nodes in this sequence, hence length = 2
            Get_Maximum_Length(node->left, 0, 2);
        }
        else // Direction is 1,
        {    // i.e. The current Node is the right part of the sequence

            // Now we go left and increase the current length by 1
            Get_Maximum_Length(node->left, 0, curr_length + 1);

            // If we go right again, we will not be making a zigzag sequence
            // And so we have to neglect the current length.
            // And find a path with current node as the starting point
            // Therefore we hold the current node as centre and traverse to the right
            // We send curr_length as 2, because if the right exists then surely there will
            // At least Two nodes in this sequence, and hence length = 2
            Get_Maximum_Length(node->right, 1, 2);
        }
    }
    int longestZigZag(TreeNode *root)
    {
        // Check the maximum length to the left
        Get_Maximum_Length(root, 0, 1);
        // Check the maximum length to the right
        Get_Maximum_Length(root, 1, 1);
        // Returning max_len - 1, as asked in the question
        return max_len - 1;
    }
};