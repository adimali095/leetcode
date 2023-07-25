class Solution {
public:
    bool res = true;
    int max(int a,int b)
    {
        return a>b?a:b;
    }
    int depth(TreeNode * root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int lDepth = 1+depth(root->left);
        int rDepth = 1+depth(root->right);
        int diff = lDepth-rDepth;
        if( !(diff > -2 && diff < 2) )
        {
            res = false;
        }
        return max(lDepth,rDepth);
    }
    bool isBalanced(TreeNode* root) 
    {
        depth(root);
        return res;
    }
};
