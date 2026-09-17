class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        
        vector<int> best(n, 1e9);
        
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int sum = 0;
        int ans = 1e9;
        int minLen = 1e9;
        
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            
            if(mp.count(sum - target)) {
                int j = mp[sum - target];
                int len = i - j;
                
                // Previous non-overlapping subarray
                if(j >= 0 && best[j] != 1e9) {
                    ans = min(ans, len + best[j]);
                }
                
                minLen = min(minLen, len);
            }
            
            best[i] = minLen;
            mp[sum] = i;
        }
        
        return ans == 1e9 ? -1 : ans;
    }
};//akd