class Solution {
public:
    bool isSame(TreeNode *p,TreeNode *q)
    {
        if(p==NULL && q==NULL)
        {
            return true;
        }
        if(p==NULL || q==NULL)
        {
            return false;
        }
        if(p->val == q->val)
        {
            return (isSame(p->left,q->left) && isSame(p->right,q->right));
        }
        else
        {
            return false;
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(root==NULL)
        {
            return false;
        }
        return (isSame(root,subRoot)|| (isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot)));
    }
};
