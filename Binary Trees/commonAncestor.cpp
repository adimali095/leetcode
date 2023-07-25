class Solution {
public:
    void search(TreeNode * root,TreeNode * p, unordered_map<TreeNode*,TreeNode*> &mp)
    {
        if(root == NULL)
        {
            return;
        }
        if(root->val == p->val)
        {
            //do nothing
            return;
        }
        else if(root->val > p->val)
        {
            mp[root->left] = root;
            search(root->left,p,mp);
        }
        else
        {
            mp[root->right]=root;
            search(root->right,p,mp);
        }
    }
    TreeNode* changedSearch(TreeNode * root,TreeNode * p, unordered_map<TreeNode*,TreeNode*> &mp)
    {
        while(root->val != p->val)
        {
            if(root->val > p->val)
            {
                if(mp.find(root->left) == mp.end())
                {
                    return root;
                }
                else
                {
                    root = root->left;
                }
            }
            else
            {
                if(mp.find(root->right)==mp.end())
                {
                    return root;
                }
                else
                {
                    root= root->right;
                }
            }
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        unordered_map<TreeNode*,TreeNode*> mp;
        search(root,p,mp);
        return changedSearch(root,q,mp);
    }
};
