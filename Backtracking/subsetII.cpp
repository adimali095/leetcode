class Solution {
public:
    void solve(vector<int> &nums,vector<vector<int>> &res,vector<int> &temp,int i)
    {
        if(i>=nums.size())
        {
            return;
        }
        temp.push_back(nums[i]);
        res.push_back(temp);
        solve(nums,res,temp,i+1);
        temp.pop_back();
        solve(nums,res,temp,i+1);
    }
    void removeElement(vector<vector<int>> &num,vector<int> eleRemove)
    {
        num.erase( find(num.begin(),num.end(),eleRemove) );
    }
    vector<vector<int>> delDuplicates(vector<vector<int>> vec)
    {
        vector<vector<int>> temp;
        for(int i =0;i<vec.size()-1;i++)
        {
            bool isSame = true;
            if(vec[i].size() == vec[i+1].size())
            {
                for(int j =0;j<vec[i].size();j++)
                {
                    if(vec[i][j] != vec[i+1][j])
                    {
                        isSame = false;
                        break;
                    }
                }
                if(isSame)
                {
                    temp.push_back(vec[i]);
                }
            }
        }
        for(auto i : temp)
        {
            removeElement(vec,i);
        }
        return vec;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        if(nums.empty())
        {
            return {};
        }
        vector<vector<int>> res;
        vector<int> temp;
        solve(nums,res,temp,0);
        res.push_back({});
        
        set<vector<int>> st;
        for(auto t : res)
        {
            sort(t.begin(),t.end());
            st.insert(t);
        }
        
        res.clear();
        for(auto ele : st)
        {
            res.push_back(ele);
        }
        sort(res.begin(),res.end());
        return res;
    }
};
