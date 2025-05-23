// GFG

/*
struct LNode { //Linked List
    int data;
    struct LNode* next;
    LNode(int x){
        data = x;
        next = NULL; }
};
struct TNode {   //Tree
    int data;
    struct TNode* left;
    struct TNode* right;
    TNode(int x){
        data=x;
        left=right=NULL; }
}; */
class Solution {
  public:
    
    TNode* helperBST(vector<int>& arr, int l, int h){
        if(l>=h) return NULL;
        int mid=(l+h)/2;
        
        TNode* root=new TNode(arr[mid]);
        root->left=helperBST(arr,l,mid);
        root->right=helperBST(arr,mid+1,h);
        return root;
    }    
    
    TNode *sortedListToBST(LNode *head) {
        LNode* temp= head;
        vector<int>arr;
        while(temp){
            arr.push_back(temp->data);
            temp=temp->next;
        }
         
        // int n=(int)arr.size();
        return helperBST(arr,0,arr.size());
        
    }
};
