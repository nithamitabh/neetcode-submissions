// i do topological sorting but it also requires me to use cycle detection
//0 - unvisited,1 - visiting,2 - visited
class Solution {
public:
    bool dfs(int src,vector<int> &vis, stack<int> &st,vector<vector<int>> & adj ){
        vis[src] = 1;
        for(int v: adj[src]){
            if(vis[v] == 0){
                if(dfs(v,vis,st,adj)) return true;
            }else if(vis[v] == 1) return true;
        }
        vis[src] = 2;
        st.push(src);
        return false;
    }
    vector<int> findOrder(int nums, vector<vector<int>>& pres) {
        vector<vector<int>> adj(nums);
        for(auto &p: pres){
            adj[p[1]].push_back(p[0]);
        }
        vector<int> vis(nums,0);
        stack<int>st;
        for(int i=0;i<nums;++i){
            if(vis[i] == 0){
                if(dfs(i,vis,st,adj)) return {};
            }
        }
        vector<int>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
