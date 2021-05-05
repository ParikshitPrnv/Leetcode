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

class Solution {
public:
    map<int,Node*>ispresent;
    map<Node*,bool>visited;
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
       Node* current_node=NULL;
        visited[node]=true;
        if(ispresent.find(node->val)!=ispresent.end())
        {
            current_node=ispresent[node->val];
        }
        else
        {
            current_node=new Node(node->val);
            ispresent[node->val]=current_node;
        }
        for(auto i:node->neighbors)
        {
            if(ispresent.find(i->val)!=ispresent.end())
            {
                current_node->neighbors.push_back(ispresent[i->val]);
            }
            else
            {
                Node* new_node=new Node(i->val);
                ispresent[i->val]=new_node;
                current_node->neighbors.push_back(new_node);
            }
            
        }
        for(auto i:node->neighbors){
            if(visited[i]==false)
            {
                visited[i]=true;
                cloneGraph(i);
            }
        }
        return current_node;
    }
};