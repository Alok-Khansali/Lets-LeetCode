// Slightly better, 100% faster
class Solution
{
public:
    int totalSum = 0; // Variable to store the total sum
    // Recursive function to calculate the sum of numbers formed by root to leaf paths
    void sumNumbersHelper(TreeNode *root, int currentSum)
    {
        // Base case: if the node is a leaf node
        if (root->left == NULL && root->right == NULL)
        {
            // Add the sum formed by the path from root to leaf to the total sum
            totalSum += currentSum * 10 + root->val;
            return;
        }
        // Update the current sum by appending the current node's value
        currentSum *= 10;
        currentSum += root->val;
        // Recursively traverse the left and right subtrees if they are available
        if (root->left)
            sumNumbersHelper(root->left, currentSum);
        if (root->right)
            sumNumbersHelper(root->right, currentSum);
    }

    // Function to calculate the sum of numbers formed by root to leaf paths
    int sumNumbers(TreeNode *root)
    {
        // Start the recursive function with initial sum 0
        sumNumbersHelper(root, 0);
        // Return the total sum
        return totalSum;
    }
};
// No other function
class Solution
{
public:
    int sumNumbers(TreeNode *root, int sum = 0)
    {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return sum * 10 + root->val;
        sum = sum * 10 + root->val;
        return sumNumbers(root->left, sum) + sumNumbers(root->right, sum);
    }
};