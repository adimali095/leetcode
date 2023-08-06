class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1,mp2,temp1,temp2;
        for(auto i : nums1)
        {
            mp1[i]++;
        }
        for(auto i:nums2)
        {
            mp2[i]++;
        }

        for(auto i :nums1)
        {
            if(mp2.find(i) == mp2.end())
            {
                temp2[i]++;
            }
        }
        for(auto i : nums2)
        {
            if(mp1.find(i) == mp1.end())
            {
                temp1[i]++;
            }
        }
        vector<vector<int>> res(2);
        for(auto kv :temp2)
        {
            res[0].push_back(kv.first);
        }
        for(auto kv :temp1)
        {
            res[1].push_back(kv.first);
        }
        /*
        res.push_back(temp2);
        res.push_back(temp1);
        */
        return res;
    }
};
