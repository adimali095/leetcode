class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_map<int,int> map   ; 
        int i,search;
        for(i=0;i<nums.size();i++)
        {
            search = nums[i];
            if(map.find(search) != map.end())
            {
                return true;
            }
            else
            {
                map[nums[i]] = i;
            }
        }
        return false;
    }
};
