class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto&ed: edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        vector<bool>visited(n,false);
        int cnt= 0;
        for(int i =0;i<n;++i){
            if(visited[i]) continue;
            cnt++;
            queue<int>q;
            q.push(i);
            visited[i] =true;
            while(!q.empty()){
                int curr= q.front();q.pop();
                for(auto nei: adj[curr]){
                    if(!visited[nei]){
                        visited[nei] = true;
                        q.push(nei);
                    }
                    
                }
            }
        }
        return cnt;
        
    }
};
