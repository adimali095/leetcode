class Solution {
public:
    void traverse(TreeNode * root,int level,queue<pair<TreeNode*,int>> &que,unordered_map<int,vector<int>> &mp)
    {
        if(root != NULL)
        {
            que.push(make_pair(root->left,level+1));
            que.push(make_pair(root->right,level+1));
            mp[level].push_back(root->val);
        }
        if(!que.empty())
        {
            pair<TreeNode*,int> temp = que.front();
            TreeNode * node = temp.first;
            int nlevel = temp.second;
            que.pop();
            traverse(node,nlevel,que,mp);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        queue<pair<TreeNode*,int>> que;
        unordered_map<int,vector<int>>mp;
        traverse(root,0,que,mp);
        vector<vector<int>> res(mp.size());
        for(auto kv : mp)
        {
            res[kv.first] = kv.second;
        }
        return res;
    }
};
