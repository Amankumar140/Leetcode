/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
class Solution {
  public:
    Node* prev = nullptr;
    void convertToDLL(Node* root, Node*& head) {
        if (root == NULL) {
            return;
        }
        convertToDLL(root->left, head);
        if (prev == NULL) {
            head = root;
        } else {
            root->left = prev;  // Left acts as 'previous' in DLL
            prev->right = root;  // Right acts as 'next' in DLL
        }
        prev = root;
        convertToDLL(root->right, head);
    }
    
 
    Node* bToDLL(Node* root) {
        Node* head = nullptr;
        convertToDLL(root, head);
        return head;
    }
};
