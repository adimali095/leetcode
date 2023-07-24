class Solution {
public:
    int max(int a,int b)
    {
        if(a >b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
    int maxDepth(TreeNode* root) 
    {
        if(root == NULL)
        {
            return 0;
        }    
        return 1 + max(maxDepth(root->right),maxDepth(root->left));
    }
};
