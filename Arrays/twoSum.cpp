class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        int i,j;
        for(i=0;i<nums.size();i++)
        {
            for(j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j] == target)
                {
                    return {i,j};
                }
            }
        }
        return {};
        */
        int i,temp;
        unordered_map<int,int> map;
        for(i=0;i<nums.size();i++)
        {
            temp = target - nums[i];
            if( map.find(temp) != map.end())
            {
                return {i,map[temp]};
            }
            else
            {
                map[nums[i]] = i;
            }
        }
        return {};

    }
};
