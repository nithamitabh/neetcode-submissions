class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty()) return "";
        unordered_map<char,int> freq,w;
        for(char ch : t) freq[ch]++;
        int left = 0,right= 0,minLen =INT_MAX,start = -1,req = freq.size(),form = 0;
        while(right<s.size()){
            char c  = s[right];
            w[c]++;
            if(freq.count(c) && w[c] == freq[c]) form++;
            while(form == req){
                if(right-left+1<minLen){
                    minLen = right - left+1;
                    start = left;
                }
                char leftChar = s[left];
                w[leftChar]--;
                if(freq.count(leftChar) && w[leftChar] <freq[leftChar]) form --;
                left++;
            }
            right++;
        }
        return (start == -1) ? "" : s.substr(start,minLen);
    }
};
