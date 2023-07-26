class Solution {
public:
    void pre(TreeNode *root,vector<int> &bst)
    {
        if(root!=NULL)
        {
            pre(root->left,bst);
            bst.push_back(root->val);
            pre(root->right,bst);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> bst;
        pre(root,bst);
        return bst[k-1];
    }
};
