class Solution {
public:
    bool helper(vector<int>& piles, int h,int k){
        int tot = 0;
        for(int pile:piles) tot+= (pile+k-1)/k;
        return tot<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1,r = *max_element(piles.begin(),piles.end());
        int res = r;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(helper(piles,h,mid)){ //tar<nums[mid]
                res = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return res;
    }
};
