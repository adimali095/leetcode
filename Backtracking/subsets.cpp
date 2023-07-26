class Solution {
public:
    void solve(vector<int> &nums,vector<vector<int>> &res,vector<int> &temp,int start,int end)
    {
        if(start == end)
        {
            return;
        }
        temp.push_back(nums[start]);
        solve(nums,res,temp,start+1,end);
        res.push_back(temp);
        temp.pop_back();
        solve(nums,res,temp,start+1,end);
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> temp;
        
        solve(nums,res,temp,0,nums.size());
        res.push_back({});
        sort(res.begin(),res.end());
        
        return res;
    }
};
