class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root == NULL)
        {
            return root;
        }
        TreeNode *left,*right;
        left = invertTree(root->right);
        right = invertTree(root->left);

        root->left = left;
        root->right = right;
        return root;
    }
};
