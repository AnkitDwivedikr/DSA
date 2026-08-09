class Solution {
public:
    int n;
    vector<vector<int>> memo;
    vector<int> suffix;

    int solve(int i, int M) {
        if (i >= n)
            return 0;

        // Can take all remaining piles
        if (i + 2 * M >= n)
            return suffix[i];

        if (memo[i][M] != -1)
            return memo[i][M];

        int ans = 0;

        for (int x = 1; x <= 2 * M; x++) {
            ans = max(ans, suffix[i] - solve(i + x, max(M, x)));
        }

        return memo[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        suffix.resize(n);
        suffix[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suffix[i] = suffix[i + 1] + piles[i];

        memo.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1);
    }
};//akd