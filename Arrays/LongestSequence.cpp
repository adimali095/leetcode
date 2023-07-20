class Solution {
public:
    int max(int a,int b)
    {
        if(a>b)
        {
            return a;
        }
        return b;
    }
    int longestConsecutive(vector<int>& nums) {
        set<int> numSet(nums.begin(),nums.end());
        int longest =0,length;
        for(auto num : nums)
        {
            if( !(numSet.find(num-1)!=numSet.end()) )
            {
                length =0;
                while(numSet.find(num+length)!=numSet.end())
                {
                    length++;
                }
                longest = max(length,longest);
            }
        }
        return longest;
    }
};
