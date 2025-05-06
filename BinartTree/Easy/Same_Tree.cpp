// O(n)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL) return p==q;
        bool leftTree=isSameTree(p->left,q->left);
        bool rightTree=isSameTree(p->right, q->right);
        return (leftTree && rightTree && q->val==p->val);
    }
};
