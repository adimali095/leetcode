class Solution {
public:
    void traverse(TreeNode * root,int max,int &count)
    {
        if(root!=NULL)
        {
            if(root->val >= max)
            {
                count++;
                traverse(root->left,root->val,count);
                traverse(root->right,root->val,count);
            }
            else
            {
                traverse(root->left,max,count);
                traverse(root->right,max,count);
                   
            }
        }
    }
    int goodNodes(TreeNode* root) 
    {
        int max = INT_MIN;
        int count = 0;
        traverse(root,max,count);
        return count;      
    }
};
