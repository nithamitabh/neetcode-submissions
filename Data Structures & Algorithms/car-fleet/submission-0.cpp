class Solution {
public:
    int carFleet(int tar, vector<int>& pos, vector<int>& speed) {
        int n = pos.size();
        vector<pair<int,double>>cars;
        for(int i = 0;i<n;++i) cars.push_back({pos[i],(double)(tar-pos[i])/speed[i]});
        sort(cars.rbegin(),cars.rend());
        int fleets = 0;
        double slowest_time= 0;
        for(auto &p : cars){
            if(p.second>slowest_time){
                fleets++;
                slowest_time = p.second; 
            }
        }
        return fleets;
    }
};
