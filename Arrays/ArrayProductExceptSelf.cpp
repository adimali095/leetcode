class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int pre=1,post=1;

        vector<int>prefix(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            prefix[i] = pre * nums[i];
            pre = prefix[i];
        }

        vector<int> postfix(nums.size());
        for(int i=nums.size()-1;i>=0;i--)
        {
            postfix[i] = post * nums[i];
            post = postfix[i];
        }
        
        vector<int>res(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            if(i==0)
            {
                res[i]=postfix[i+1];
            }
            else if(i==nums.size()-1)
            {
                res[i]=prefix[i-1];
            }
            else
            {
                res[i]=prefix[i-1]*postfix[i+1];
            }
        }
        return res;

    }
};
