class Solution {
public:
    void solve(vector<int> &nums,vector<int> &temp,vector<vector<int>> &res,int i,int total,int target)
    {
        if(total == target)
        {
            res.push_back(temp);
            return;
        }
        if(total > target ||  i >= nums.size())
        {
            return;
        }
        temp.push_back(nums[i]);
        solve(nums,temp,res,i,total+nums[i],target);
        temp.pop_back();
        solve(nums,temp,res,i+1,total,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(candidates,temp,res,0,0,target);
        sort(res.begin(),res.end());
        return res;
    }
};
