/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
public:
    void reorderList(Node* head) {
        // Handle base cases
        if(head->next == NULL || head->next->next == NULL)
            return;
            
        // Step 1: Find middle using slow and fast pointers
        Node* slow = head, *fast = head;
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Adjust for even length lists
        if(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Step 2: Split and prepare to reverse second half
        if(slow->next != NULL)
            fast = slow->next;
        slow->next = NULL;
        
        // Step 3: Reverse second half
        while(1) {
            if(fast->next == NULL) {
                fast->next = slow;
                break;
            } else {
                Node* temp = fast->next;
                fast->next = slow;
                slow = fast;
                fast = temp;
            }
        }
        
        // Step 4: Merge both halves
        slow = head;
        Node* temp1, *temp2;
        while(fast->next != NULL) {
            temp1 = slow->next;
            slow->next = fast;
            temp2 = fast->next;
            fast->next = temp1;
            slow = temp1;
            fast = temp2;
        }
    }
};
