class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(),l = 0,max_l = 0;
        unordered_set<char> unique;
        for(int r= 0;r<n;++r){
            while(unique.find(s[r]) != unique.end()){
                unique.erase(s[l]);
                l++;
            }
            unique.insert(s[r]);
            max_l = max(max_l,r-l+1);
        }
        return max_l;

    }
};
