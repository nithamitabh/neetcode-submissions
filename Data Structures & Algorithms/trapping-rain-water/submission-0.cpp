class Solution {
public:
    int trap(vector<int>& height) {
        int l =0,r = height.size() -1,lMax = 0,rMax = 0,tapped = 0;
        while(l<r){
            if(height[l]<height[r]){
                if(height[l]>=lMax) lMax =height[l];
                else tapped += lMax-height[l];
                l++;
            } else{
                if(height[r]>=rMax) rMax =height[r];
                else tapped += rMax-height[r];
                r--;
            }
        }
        return tapped;
    }
};
