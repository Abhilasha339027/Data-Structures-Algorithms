/*  We've to make a deep copy of given graph, so basic idea is to traverse the graph using BFS/DFS and map the visiting nodes to it's new copy 
    Here, I'm using map<> to store visited nodes as well as build the connection while traversing.

    The first value in map is the original node, and we'are mapping it's copy to it.
*/

//Iterative BFS solution, replace queue to stack to implement DFS.

class Node {
    int val;
    vector<Node> neighbors;
}

class Solution
{
private:
    unordered_map<Node*, Node*> hash;

public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;

        Node *temp = new Node(node->val, {});
        hash[node] = temp;

        queue<Node *> todo;
        todo.push(node);

        while (!todo.empty())
        {
            Node *curr = todo.front();
            todo.pop();

            for (Node *neighbor : curr->neighbors)
            {
                if (hash.find(neighbor) == hash.end())
                {
                    hash[neighbor] = new Node(neighbor->val, {});
                    todo.push(neighbor);
                }

                hash[curr]->neighbors.push_back(hash[neighbor]);
            }
        }

        return hash[node];
    }
};

/* Recursive, DFS Solution */
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        if (copies.find(node) == copies.end()) {
            copies[node] = new Node(node -> val, {});
            for (Node* neighbor : node -> neighbors) {
                copies[node] -> neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return copies[node];
    }
private:
    unordered_map<Node*, Node*> copies;
};