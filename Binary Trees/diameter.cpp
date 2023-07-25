class Solution {
public:
    int max(int a,int b)
    {
        return a>b?a:b;
    }
    int maxDepth(TreeNode *root,int &diameter)
    {
        if(root== NULL)
        {
            return 0;
        }
        int leftHeight = maxDepth(root->left,diameter);
        int rightHeight = maxDepth(root->right,diameter);
        diameter = max(diameter,leftHeight+rightHeight+1);
        return max(leftHeight,rightHeight)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int d =0;
        maxDepth(root,d);
        return d-1;
    }
};
