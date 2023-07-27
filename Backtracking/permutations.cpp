class Solution {
public:
    void removeElement(vector<int> &num,int eleRemove)
    {
        num.erase( find(num.begin(),num.end(),eleRemove) );
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 1)
        {
            return {{nums[0]}};
        }
        vector<vector<int>> perms,res;
        for(auto i :nums)
        {
            int n = nums[0];
            removeElement(nums,n);
            perms = permute(nums);
            for(auto perm : perms)
            {
                perm.push_back(n);
                res.push_back(perm);
            }
            nums.push_back(n);
        }
        return res;
    }
};
