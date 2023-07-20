class Solution {
public:

    //A minimized solution
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
          unordered_map<int,int> mp;
          //storing element as key and occurences as values
          for(auto num:nums)
          {
              mp[num]++;
          }
          //publishing an empty vector
          vector<vector<int>> count(nums.size()+1);   
          for(auto kv:mp)
          {
              //using occurences as indexes
              count[kv.second-1].push_back(kv.first);
          }
          vector<int>res;
          int j;
          for(int i=count.size()-1;i>=0 && res.size()<k;i--)
          {
              for(j=0;j<count[i].size();j++)
              {
                  res.push_back(count[i][j]); 
              }
          }
          return res;
    }

    /*
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
          unordered_map<int,int> mp;
          //storing key as element and values as occurences
          
          for(auto num : nums)
          {
              if(mp.find(num)!=mp.end())
              {
                  mp[num]++;
              }
              else
              {
                  mp[num]=1;
              }
          }
          for(auto num:nums)
          {
              mp[num]++;
          }

          //publishing an empty vector
          vector<vector<int>> count;
          for(int i=0;i<nums.size();i++)
          {
              count.push_back({});
          }        
          for(auto kv:mp)
          {
              //using occurences as indexes
              count[kv.second-1].push_back(kv.first);
          }
          vector<int>res;
          int kcount=0,j;
          for(int i=count.size()-1;i>=0;i--)
          {
              for(j=0;j<count[i].size();j++)
              {
                  if(kcount == k)
                  {
                      break;
                  }
                  else
                  {
                      res.push_back(count[i][j]);
                      kcount++;
                  }
              }
          }
          return res;
    }*/
};
