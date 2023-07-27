class Solution {
public:
    void solve(vector<int> &nums,vector<vector<int>> &res,vector<int> &temp,int i)
    {
        if(i>=nums.size())
        {
            return;
        }
        temp.push_back(nums[i]);
        res.push_back(temp);
        solve(nums,res,temp,i+1);
        temp.pop_back();
        solve(nums,res,temp,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        if(nums.empty())
        {
            return {};
        }
        vector<vector<int>> res;
        vector<int> temp;
        solve(nums,res,temp,0);
        res.push_back({});
        
        set<vector<int>> st;
        for(auto t : res)
        {
            sort(t.begin(),t.end());
            st.insert(t);
        }
        
        res.clear();
        for(auto ele : st)
        {
            res.push_back(ele);
        }
        sort(res.begin(),res.end());
        return res;
    }
};
