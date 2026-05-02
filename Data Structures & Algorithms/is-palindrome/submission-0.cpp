class Solution {
public:
    bool isPalindrome(string s) {
        string n_s = "";
        for(char c : s){
            if(isalnum(c)) n_s += tolower(c);
        }
        int l =0,r = n_s.size()-1;
        while(l<r){
            if(n_s[l] != n_s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
