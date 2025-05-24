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
    int length(ListNode* head) {
        ListNode* temp = head;
        int c = 0;
        while (temp != NULL) {
            c++;
            temp = temp->next;
        }
        return c;
    }
    ListNode* traversal(ListNode* head, int k) {
        if (head == NULL)
            return NULL;
        ListNode* temp = head;
        while (k!=1) {
            temp = temp->next;
            k--;
        }
        return temp;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = traversal(head, k);
        ListNode* second = traversal(head, length(head) - k + 1);
        swap(first->val, second->val);
        return head;
    }
};
