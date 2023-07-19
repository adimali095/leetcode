class Solution {
public:
/*
    vector<int> getAnagramIndexes(vector<string> strs,string str)
    {
        vector<int> res;
        int i;
        for(i=0;i<strs.size();i++)
        {
            if(str == strs[i])
            {
                cout<<i<<endl;
                res.push_back(i);
            }
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> res;
        
        vector<string> copy = strs;
        vector<string> temp;

        vector<int> indexes;
        
        string str;
        
        int i;
        for(i=0;i<copy.size();i++)
        {
            sort(copy[i].begin(),copy[i].end() );
        }


        while(!copy.empty())
        {
            indexes = getAnagramIndexes(copy,copy[0]);
            for(i=0;i<indexes.size();i++)
            {
                //cout<<i<<endl;
                str = strs[indexes[i]];
                temp.push_back(str);
                copy.erase(copy.begin()+indexes[i]);
                strs.erase(strs.begin()+indexes[i]);
            }
            cout<<"\nEND\n";
            res.push_back(temp);
            temp.clear();
        }
        return res;
    }
    */
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> res;
        
        unordered_map<string,vector<string>> mp;
        string t;
        for(string s:strs)
        {
            t = s;
            sort(t.begin(),t.end());
            mp[t].push_back(s);
        }
        for(auto kv:mp)
        {
            res.push_back(kv.second);
        }
        return res;
    }
};
