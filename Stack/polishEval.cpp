class Solution {
public:
    stack<string>st;
    int evalRPN(vector<string>& tokens) 
    {
        for(string s : tokens)
        {
            if( s!="+" && s!="-" && s!="*" && s!="/")
            {
                st.push(s);
            }
            else
            {
                int res;
                int op1 = stoi(st.top());
                st.pop();
                int op2 = stoi(st.top());
                st.pop();
                if(s == "+")
                {
                    res = op2+op1;
                }
                if(s == "-")
                {
                    res = op2-op1;
                }
                if(s == "*")
                {
                    res = op2*op1;
                }
                if(s == "/")
                {
                    res = op2/op1;
                }
                cout<<res<<"\t";
                st.push(to_string(res));
            }
        }    
        return stoi(st.top());
    }
};
