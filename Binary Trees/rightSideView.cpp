class Solution {
public:
    void traverse(TreeNode * root,int level,queue<pair<TreeNode*,int>> &que,unordered_map<int,vector<int>> &mp)
    {
        if(root!=NULL)
        {
            que.push(make_pair(root->left,level+1));
            que.push(make_pair(root->right,level+1));
            mp[level].push_back(root->val);
        }
        if(!que.empty())
        {
            pair<TreeNode*,int> temp = que.front();
            que.pop();
            TreeNode * node = temp.first;
            int nlevel = temp.second;
            traverse(node,nlevel,que,mp);
        }
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        queue<pair<TreeNode*,int>> que;
        unordered_map<int,vector<int>> mp;
        traverse(root,0,que,mp);
        vector<vector<int>> temp(mp.size());
        for(auto kv : mp)
        {
            temp[kv.first] = kv.second;
        }
        vector<int> res;
        for(auto vec: temp)
        {
            res.push_back(vec.back());
        }
        return res;
    }
};
