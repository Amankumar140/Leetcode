/* Structure of the node of the list is as
class DLLNode {
public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to merge two sorted doubly linked lists
    DLLNode* merge(DLLNode* h1, DLLNode* h2) {
        if (h1 == nullptr) return h2;
        if (h2 == nullptr) return h1;

        DLLNode* result = nullptr;

        if (h1->data <= h2->data) {
            result = h1;
            result->next = merge(h1->next, h2);
            if (result->next) result->next->prev = result;
        } else {
            result = h2;
            result->next = merge(h1, h2->next);
            if (result->next) result->next->prev = result;
        }

        return result;
    }

    // Function to split a doubly linked list into two halves
    DLLNode* split(DLLNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        DLLNode* slow = head;
        DLLNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        DLLNode* secondHalf = slow->next;
        slow->next = nullptr;
        if (secondHalf) secondHalf->prev = nullptr;

        return secondHalf;
    }

    // Function to sort the given doubly linked list using Merge Sort
    DLLNode* sortDoubly(DLLNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        DLLNode* secondHalf = split(head);

        head = sortDoubly(head);
        secondHalf = sortDoubly(secondHalf);

        return merge(head, secondHalf);
    }
};
