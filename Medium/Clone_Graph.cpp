/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution
{
public:
    unordered_map<Node *, Node *> mp;
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;
        if (mp.find(node) == mp.end()) // if node has not been traverses yet
        {
            // Store the node with its value and the empty vector of its neighbours
            mp[node] = new Node(node->val, {});
            // Now traverse the nodes and keep adding the
            // deep copies of neighbour nodes into the vector
            for (Node *nebur : node->neighbors)
                mp[node]->neighbors.push_back(cloneGraph(nebur));
        }
        // Return the node
        return mp[node];
    }
};