class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        vector<int>res(n,0);
        stack<int>st;
        for(int i = 0;i<n;++i){
            while(!st.empty() && temps[i]> temps[st.top()]){
                int preIdx = st.top();
                st.pop();
                res[preIdx] = i-preIdx;
            }
            st.push(i);
        }
        return res;
    }
};
