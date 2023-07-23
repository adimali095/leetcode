class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < position.size(); i++) 
        {
            pairs.push_back(make_pair(position[i], speed[i]));
        }
        sort(pairs.begin(), pairs.end());

        stack<double> st;
        double t = target, s, p;
        for (int j = pairs.size() - 1; j >= 0; j--) 
        {
            p = static_cast<double>(pairs[j].first);
            s = static_cast<double>(pairs[j].second);
            double time = (t - p) / s;

            if (st.empty() || time > st.top()) 
            {
                st.push(time);
            }
        }
        return st.size();
    }
};
