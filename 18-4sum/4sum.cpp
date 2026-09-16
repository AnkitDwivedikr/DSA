class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i=0; i<n-3; i++){
            if(i>0 && nums[i]==nums[i-1])
            continue;

            for(int j=i+1; j<n-2; j++){
                if(j>i+1 && nums[j]==nums[j-1])
                continue;

              long long sum = nums[i]+nums[j];
                int start = j+1, end = n-1;

                while(start<end){
                    long long total = sum + nums[start] + nums[end];

                    if(total == target){
                    ans.push_back({nums[i],nums[j], nums[start], nums[end]});
                    start++;
                    end--;
                    while(start<end && nums[start]==nums[start-1])
                    start++;
                    while(start<end && nums[end]==nums[end+1])
                    end--;
                    }
                    else if(total<target){
                        start++;
                    }
                    else
                    end--;
                }
            }
        }
        return ans;
    }
};