class Solution   //BFS IN O(1)
{
public:
    Node *connect(Node *root)
    {
        Node *trav = root;
        while (trav)
        {
            Node *stored = new Node(0), *temp = stored;
            while (trav)
            {
                if (trav->left)
                    stored->next = trav->left, stored = stored->next;
                if (trav->right)
                    stored->next = trav->right, stored = stored->next;

                trav = trav->next;
            }
            trav = temp->next;
        }
        return root;
    }
};