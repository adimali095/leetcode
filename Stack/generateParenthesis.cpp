class Solution {
public:
    
    string concatenateStackElements(stack<string> st) {
    string result;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(),result.end());
    return result;
    }
    void backtrack(stack<string> &st,vector<string> &res,int open,int close,int &n)
    {
        if(open == n && close == n)
        {
            res.push_back(concatenateStackElements(st));
            return;
        }
        if(open < n)
        {
            st.push("(");
            backtrack(st,res,open+1,close,n);
            st.pop();
        }
        if(close < open)
        {
            st.push(")");
            backtrack(st,res,open,close+1,n);
            st.pop();
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string>res;
        stack<string>st;
        backtrack(st,res,0,0,n);
        return res;
    }
};
