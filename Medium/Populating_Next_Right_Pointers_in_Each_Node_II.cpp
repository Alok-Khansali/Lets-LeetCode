class Solution // BFS IN O(1)
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
int getMinTime(int n, vector<int> tm, vector<int> tt)
{
    vector<pair<int, int>> vp;
    for(int i = 0; i < tm.size();i++)
    {
        vp.push_back({tm[i], tt[i]});
    }
}