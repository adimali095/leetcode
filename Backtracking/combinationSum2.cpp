class Solution {
public:
    
    bool validate(unordered_map<int,int> &test,unordered_map<int,int> &resMp)
    {
        bool result = true;
        for(auto kv :  resMp)
        {
            if(kv.second > test[kv.first])
            {
                result = false;
                break;
            }
        }
        return result;
    }
    void solve(vector<int>&nums,set<vector<int>> &res,vector<int> &temp,int i,int total,int &target,unordered_map<int,int> &test,unordered_map<int,int> &resMp)
    {
        if(total > target || i >= nums.size() || !validate(test,resMp))
        {
            return;
        }
        if(total == target)
        {
            vector<int> insertVec(temp);
            sort(insertVec.begin(),insertVec.end());
            res.insert(insertVec);
            return;
        }
        while( i+1 < nums.size() && nums[i] == nums[i+1])
        {
            i++;
        }

        resMp[nums[i]]++;
        temp.push_back(nums[i]);

        solve(nums,res,temp,i,total+nums[i],target,test,resMp);
        
        resMp[nums[i]]--;
        temp.pop_back();
        
        solve(nums,res,temp,i+1,total,target,test,resMp);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        unordered_map<int,int> test,resMp;
        for(auto i : candidates)
        {
            test[i]++;
        }
        set<vector<int>> st;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        solve(candidates,st,temp,0,0,target,test,resMp);

        vector<vector<int>> res;
        for(auto ele : st)
        {
            res.push_back(ele);
        }
        return res;
    }
};
