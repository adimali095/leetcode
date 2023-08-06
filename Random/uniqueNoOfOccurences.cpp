class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto i : arr)
        {
            mp[i]++;
        }
        unordered_map<int,vector<int>> mp2;
        for(auto kv : mp)
        {
            mp2[kv.second].push_back(kv.first);
        }
        for(auto kv:mp2)
        {
            if(kv.second.size() > 1)
            {
                return false;
            }
        }
        return true;
    }
};
