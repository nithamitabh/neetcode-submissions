class Solution {
public:
    bool isCycle(int src,vector<bool> &vis,vector<bool> &recPath,vector<vector<int>> adj){
        vis[src] = true;
        recPath[src] = true;
        for(int v: adj[src]){
            if(!vis[v]){
                if(isCycle(v,vis,recPath,adj)) return true;
            }else if(recPath[v]){
                return true;
            }
        }
        recPath[src] = false;
        return false;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<bool>vis(numCourses,false),recPath(numCourses,false);
        for(auto &p : prerequisites){
            adj[p[1]].push_back(p[0]); // p[1]->p[0]
        }
        for(int i =0;i<numCourses;++i){
            if(!vis[i]){
                if(isCycle(i,vis,recPath,adj)) return false;
            }
        }
        return true;
        
    }
};
