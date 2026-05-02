class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int m = mat.size(),n = mat[0].size();
        int l = 0,r= m*n-1;
        while(l<=r){
            int mid = l + (r-l)/2,val = mat[mid/n][mid%n];
            if(val == tar) return true;
            else if(val>tar) r= mid-1;
            else l= mid+1;
        }
        return false;
    }

};
