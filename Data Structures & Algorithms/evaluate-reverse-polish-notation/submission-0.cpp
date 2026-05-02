class Solution {
public:
    bool isOpr(const string& ts) {
        return ts == "+" || ts == "-" || ts == "*" || ts == "/";
    }
    int eval(int a,int b,const string &op){
        if(op == "+") return a+b;
        if(op == "-") return a-b;
        if(op == "*") return a*b;
        return a/b;
    }
    int evalRPN(vector<string>& ts) {
        stack<int>st;
        for(const string& t : ts){
            if(isOpr(t)){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(eval(a,b,t));
            }else{
                st.push(stoi(t));
            }
        }
        return st.top();        
    }
};
