class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        sort(nums.begin(),nums.end());
        int curr = 1,res=1;
        for(int i = 1;i<n;++i){
            if(nums[i] == nums[i-1]) continue;
            if(nums[i] - nums[i-1] == 1) curr++;
            else {
                res= max(res,curr);
                curr =1;
            }
        }
        return max(res,curr);
    }
};
