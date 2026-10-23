class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();

        bool lower = false, upper = false, digit = false;

        for (char ch : password) {
            if (islower(ch)) lower = true;
            if (isupper(ch)) upper = true;
            if (isdigit(ch)) digit = true;
        }

        int missing = !lower + !upper + !digit;
        int replace = 0, one = 0, two = 0;

        for (int i = 0; i < n;) {
            int j = i;

            while (j < n && password[j] == password[i])
                j++;

            int len = j - i;

            if (len >= 3) {
                replace += len / 3;

                if (len % 3 == 0)
                    one++;
                else if (len % 3 == 1)
                    two++;
            }

            i = j;
        }

        if (n < 6)
            return max(missing, 6 - n);

        if (n <= 20)
            return max(missing, replace);

        int del = n - 20;
        replace -= min(del, one);
        replace -= min(max(0, del - one), two * 2) / 2;
        replace -= max(0, del - one - two * 2) / 3;

        return del + max(missing, replace);
    }
};//favirout que ask in interview 