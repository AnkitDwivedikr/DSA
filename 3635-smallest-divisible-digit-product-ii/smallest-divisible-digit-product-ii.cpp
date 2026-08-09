class Solution {
public:

    map<int, int> factor[10];

    Solution() {
        factor[0] = {};
        factor[1] = {};
        factor[2] = {{2, 1}};
        factor[3] = {{3, 1}};
        factor[4] = {{2, 2}};
        factor[5] = {{5, 1}};
        factor[6] = {{2, 1}, {3, 1}};
        factor[7] = {{7, 1}};
        factor[8] = {{2, 3}};
        factor[9] = {{3, 2}};
    }

    map<int, int> getPrimeCount(long long t, bool &ok) {

        map<int, int> cnt = {
            {2, 0},
            {3, 0},
            {5, 0},
            {7, 0}
        };

        for (int p : {2, 3, 5, 7}) {

            while (t % p == 0) {
                cnt[p]++;
                t /= p;
            }
        }

        ok = (t == 1);

        return cnt;
    }

    map<int, int> getPrimeCount(string s) {

        map<int, int> cnt = {
            {2, 0},
            {3, 0},
            {5, 0},
            {7, 0}
        };

        for (char c : s) {

            int d = c - '0';

            for (auto [p, x] : factor[d])
                cnt[p] += x;
        }

        return cnt;
    }

    map<int, int> getFactorCount(map<int, int> cnt) {

        map<int, int> ans = {
            {2, 0},
            {3, 0},
            {4, 0},
            {5, 0},
            {6, 0},
            {7, 0},
            {8, 0},
            {9, 0}
        };

        // 2^3 = 8
        ans[8] = cnt[2] / 3;
        int rem2 = cnt[2] % 3;

        // 3^2 = 9
        ans[9] = cnt[3] / 2;
        int rem3 = cnt[3] % 2;

        // 2^2 = 4
        ans[4] = rem2 / 2;
        int rem22 = rem2 % 2;

        // 2 + 3 = 6
        if (rem22 == 1 && rem3 == 1) {

            ans[6] = 1;
            rem22 = 0;
            rem3 = 0;
        }

        // 4 + 3 = 2 + 6
        if (rem3 == 1 && ans[4] > 0) {

            ans[4]--;
            ans[6]++;
            ans[2]++;

            rem3 = 0;
        }

        ans[2] += rem22;
        ans[3] += rem3;

        ans[5] = cnt[5];
        ans[7] = cnt[7];

        return ans;
    }

    int sumValues(map<int, int> cnt) {

        int ans = 0;

        for (auto [d, f] : cnt)
            ans += f;

        return ans;
    }

    string construct(map<int, int> cnt) {

        string ans;

        for (int d = 2; d <= 9; d++)
            ans += string(cnt[d], char('0' + d));

        return ans;
    }

    map<int, int> subtract(
        map<int, int> a,
        map<int, int> b
    ) {

        for (auto [p, x] : b)
            a[p] = max(0, a[p] - x);

        return a;
    }

    bool isSubset(
        map<int, int> need,
        map<int, int> have
    ) {

        for (auto [p, x] : need) {

            if (have[p] < x)
                return false;
        }

        return true;
    }

    string smallestNumber(string num, long long t) {

        // --------------------------------
        // 1. Factorize t
        // --------------------------------

        bool ok;

        map<int, int> need =
            getPrimeCount(t, ok);

        if (!ok)
            return "-1";


        // --------------------------------
        // 2. Minimum digits required
        // --------------------------------

        map<int, int> factorCount =
            getFactorCount(need);

        int minDigits =
            sumValues(factorCount);


        // IMPORTANT:
        // If minimum required digits itself
        // is more than num length,
        // simply construct it.
        // DON'T do string(n + 1 - minDigits)
        // here.
        
        if (minDigits > (int)num.size())
            return construct(factorCount);


        // --------------------------------
        // 3. Prime factors of num
        // --------------------------------

        map<int, int> current =
            getPrimeCount(num);


        // --------------------------------
        // 4. Check if num itself works
        // --------------------------------

        int firstZero = num.find('0');

        if (firstZero == string::npos) {

            firstZero = num.size();

            if (isSubset(need, current))
                return num;
        }


        // --------------------------------
        // 5. Try changing from right
        // --------------------------------

        for (int i = num.size() - 1; i >= 0; i--) {

            int d = num[i] - '0';


            // Remove current digit
            current =
                subtract(current, factor[d]);


            int space =
                num.size() - 1 - i;


            // Prefix can't contain zero
            if (i > firstZero)
                continue;


            // Try a bigger digit
            for (int bigger = d + 1;
                 bigger <= 9;
                 bigger++) {


                // What factors are still required?
                map<int, int> remaining =
                    subtract(
                        subtract(need, current),
                        factor[bigger]
                    );


                // Minimum digits needed
                map<int, int> requiredDigits =
                    getFactorCount(remaining);


                int required =
                    sumValues(requiredDigits);


                // Can fit in suffix?
                if (required <= space) {

                    int ones =
                        space - required;


                    string ans =
                        num.substr(0, i);

                    ans += char('0' + bigger);

                    ans += string(ones, '1');

                    ans += construct(requiredDigits);

                    return ans;
                }
            }
        }


        // --------------------------------
        // 6. Same length impossible
        // --------------------------------

        factorCount =
            getFactorCount(need);

        minDigits =
            sumValues(factorCount);


        return string(
            num.size() + 1 - minDigits,
            '1'
        ) + construct(factorCount);
    }
};//akd