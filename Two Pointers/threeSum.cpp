class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        int i,j,k,n,target,sum;
        n = nums.size();
        target = 0;
        for(i=0;i<n;i++)
        {
            if(i>0 && nums[i] == nums[i-1])
            {
                continue;
            }
            j= i+1;
            k = n-1;
            while(j<k)
            {
                sum = nums[i]+nums[j]+nums[k];
                if(sum == target)
                {
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    res.push_back(temp);
                    temp.clear();
                    
                    while(j<k && nums[j]==nums[j+1])
                    {
                        j++;
                    }
                    while(k>j && nums[k]==nums[k-1])
                    {
                        k--;
                    }
                    j++;
                    k--;
                }
                else if(sum < target)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }    
        return res;
    }
};
