class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0)
            return head;

        int  length = 1;
        ListNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
            length++;
        }

        //   Make it circular
        temp->next = head;

        //   Normalize k
        k = k % length;
        if (k == 0) {
            temp->next = nullptr;
            return head;
        }

        //   Find new tail
        int steps = length - k;
        ListNode* newTail = head;
        for (int i = 0; i < steps - 1; i++) {
            newTail = newTail->next;
        }

        //   Break the circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
