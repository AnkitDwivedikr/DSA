class Solution {
public:

    struct Node {
        long long weight;
        vector<int> ids;
    };

    vector<vector<Node>> dp;

    // Lexicographically smaller vector
    bool smaller(vector<int>& a, vector<int>& b) {
        return a < b;
    }

    Node solve(vector<vector<int>>& a, int i, int k) {

        if (i == a.size() || k == 0) {
            return {0, {}};
        }

        if (dp[i][k].weight != -1) {
            return dp[i][k];
        }

        // 1. Don't take current interval
        Node skip = solve(a, i + 1, k);

        // 2. Take current interval
        int r = a[i][1];

        // Find first interval whose start > current end
        int lo = i + 1;
        int hi = a.size();

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (a[mid][0] > r)
                hi = mid;
            else
                lo = mid + 1;
        }

        int next = lo;

        Node takeNext = solve(a, next, k - 1);

        Node take;
        take.weight = a[i][2] + takeNext.weight;

        take.ids = takeNext.ids;
        take.ids.push_back(a[i][3]);

        sort(take.ids.begin(), take.ids.end());

        // Compare
        if (take.weight > skip.weight) {
            return dp[i][k] = take;
        }

        if (take.weight < skip.weight) {
            return dp[i][k] = skip;
        }

        // Same weight -> lexicographically smaller
        if (take.ids < skip.ids)
            return dp[i][k] = take;

        return dp[i][k] = skip;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // Store original index
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        // Sort by starting point
        sort(intervals.begin(), intervals.end());

        dp.assign(n, vector<Node>(5, {-1, {}}));

        return solve(intervals, 0, 4).ids;
    }
};//akd