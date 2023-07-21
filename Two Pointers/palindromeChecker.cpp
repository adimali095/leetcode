class Solution {
public:
    string convert(string s)
    {
        string temp = "";
        for(char c:s)
        {
            if(isalnum(c))
            {
                temp.push_back(tolower(c));
            }
        }
        return temp;
    }
    bool isPalindrome(string s) 
    {
        int left,right;
        s = convert(s);
        left = 0;
        right = s.size()-1;
        while(left<right)
        {
            if(s[left]==s[right])
            {
                left++;
                right--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
