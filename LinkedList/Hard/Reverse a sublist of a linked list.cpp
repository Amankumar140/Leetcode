// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/
class Solution {
  public:
    Node* reverseBetween(int a, int b, Node* head) {
         if(!head || a==b) return head;
         Node* dummy=new Node(-1);
         dummy->next=head;
         Node* prev=dummy;
         for(int i=1; i<a; i++){
             prev=prev->next;
         }
         Node * curr=prev->next;
         for(int i=0; i<b-a; i++){
             Node * next=curr->next;
             curr->next=next->next;
             next->next=prev->next;
             prev->next=next;
         }
        return dummy->next;
    }
};
