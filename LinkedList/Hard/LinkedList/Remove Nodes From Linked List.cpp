/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode*& head) {
        if (!head)
            return NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
    ListNode* removeNodes(ListNode* head) {
        reverse(head);
        ListNode* temp = head;
        while (temp->next != NULL) {
            if (temp->val > temp->next->val) {
                temp->next = temp->next->next;
            }
             else {
                temp = temp->next;
            }
        }
        reverse(head);
        return head;
    }
};
