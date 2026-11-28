class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        int mask = 0;

        for(int i = 30; i >= 0; i--) {
            mask |= (1 << i);

            unordered_set<int> st;

            for(int num : nums) {
                st.insert(num & mask);
            }

            int candidate = ans | (1 << i);

            for(int p : st) {
                if(st.count(candidate ^ p)) {
                    ans = candidate;
                    break;
                }
            }
        }

        return ans;
    }
};// smjh mei hi nhi aaya; revise karana hai mujhe;