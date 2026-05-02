class Solution {
public:

    string encode(vector<string>& strs) {
        string encode = "";
        for(const string& str: strs) encode += to_string(str.size()) + "#"+str;
        return encode;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i  = 0;
        while(i<s.size()){
            int j = i;
            while(s[j] != '#') j++;
            int len= stoi(s.substr(i,j-i));
            decoded.push_back(s.substr(j+1,len));
            i= j+1+len;
        }
        return decoded;
    }
};
