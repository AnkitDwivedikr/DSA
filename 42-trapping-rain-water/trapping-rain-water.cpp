class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftmax=0, rightmax=0;
        int maxheight = height[0];
        int index = 0, water = 0;
        // find the maximum height.
        for(int i=1; i<n; i++){
            if(maxheight<height[i]){
            maxheight = height[i];
            index = i;
            }
        }
        // max left side.
        for(int i=0; i<index; i++){
            if(leftmax > height[i])
            water += leftmax-height[i];
            else
            leftmax = height[i];
        }
        // max right side.
        for(int i=n-1; i>index; i--){
            if(rightmax>height[i])
            water += rightmax-height[i];
            else
            rightmax = height[i];
        } 
        return water;
    }
};