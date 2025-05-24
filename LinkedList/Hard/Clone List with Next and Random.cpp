// GFG 

/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};*/

class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        if (!head) return nullptr; 

        unordered_map<Node*, Node*> nodeMap; 
        Node* temp = head;

        // lets first create next nodes in new list
        Node* dummy = new Node(-1), *temp2 = dummy;
        while (temp) {
            Node* curr = new Node(temp->data);
            nodeMap[temp] = curr; 
            temp2->next = curr;
            temp2 = curr;
            temp = temp->next;
        }

        // now join random pointers
        temp = head;
        temp2 = dummy->next;
        while (temp) {
            temp2->random = (temp->random) ? nodeMap[temp->random] : nullptr;
            temp = temp->next;
            temp2 = temp2->next;
        }

        return dummy->next;
    }
};
