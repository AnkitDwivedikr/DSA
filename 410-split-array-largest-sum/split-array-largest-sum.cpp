class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0, end = 0, ans=0;
        for(int i=0; i<n; i++){
            start = max(start,nums[i]);
            end += nums[i];
        }
        while(start<=end){
            int mid = start+(end-start)/2;
            int pages =0 , count=1;
            for(int i=0; i<n; i++){
            if(pages+nums[i]<=mid)
            pages += nums[i];
            else
            {
                count++;
                pages = nums[i];
            }
            }
            if(count<=k){
                ans = mid;
                end = mid-1;
            }
            else
            start = mid+1;
        }
        return ans;
    }
};