class Solution {
public:
    void solve(vector<string> &res,vector<string> &digits,unordered_map<string,vector<string>> &mp,vector<string> &temp,int start)
    {
        cout<<start<<"\t";
        if(start == digits.size())
        {   cout<<start<<" base\t";
            string tempStr;
            for(string s : temp)
            {
                cout<<s;
                tempStr+= s;
            }
            cout<<tempStr;
            res.push_back(tempStr);
            return;
        }
        cout<<start<<" loopBefore\t";
        for(int i = 0;i<(mp[digits[start]]).size();i++)
        {
            temp.push_back(mp[digits[start]][i]);
            solve(res,digits,mp,temp,start+1);
            temp.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) 
    {
        vector<string> str;
        for(auto c : digits)
        {
            str.push_back(string(1,c));
        }
        unordered_map<string,vector<string>> mp;
        mp["2"] = {"a","b","c"};
        mp["3"] = {"d","e","f"};
        mp["4"] = {"g","h","i"};
        mp["5"] = {"j","k","l"};
        mp["6"] = {"m","n","o"};
        mp["7"] = {"p","q","r","s"};
        mp["8"] = {"t","u","v"};
        mp["9"] = {"w","x","y","z"};
        vector<string> res;
        vector<string> temp;
        if(str.size() == 0)
        {
            return {};
        }
        solve(res,str,mp,temp,0);
        return res;
    }
};
