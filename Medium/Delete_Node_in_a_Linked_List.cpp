// Brute Force, copy all the succeeding nodes into current ones,
// the last node is eliminated
class Solution
{
public:
    // Function to delete a node from a singly linked list
    void deleteNode(ListNode *node)
    {
        // Traverse the list until the second last node
        while (node->next->next)
        {
            // Copy the value of the next node to the current node
            node->val = node->next->val;
            // Move to the next node
            node = node->next;
        }
        // Copy the value of the last node to the current node
        node->val = node->next->val;
        // Remove the last node by setting the next pointer to NULL
        node->next = NULL;
    }
};

// Building upon the above solution
// Just remove the next node by shifting its value into the current one

class Solution
{
public:
    // Function to delete a node from a singly linked list
    void deleteNode(ListNode *node)
    {
        // Store the next node's pointer temporarily
        ListNode *nextNode = node->next->next;
        // Copy the value of the next node to the current node
        node->val = node->next->val;
        // Update the next pointer to skip the next node
        node->next = nextNode;
    }
};

// The Game of pointers, just change the referance
class Solution {
public:
    void deleteNode(ListNode *node) {
        // Copy the value of the next node to the current node
        *node = *(node->next);
    }
};
