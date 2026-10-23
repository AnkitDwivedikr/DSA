class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if (password.length() < 8)
            return false;

        bool lower = false, upper = false;
        bool digit = false, special = false;

        string sp = "!@#$%^&*()-+";

        for (int i = 0; i < password.length(); i++) {

            char ch = password[i];

            if (islower(ch))
                lower = true;

            if (isupper(ch))
                upper = true;

            if (isdigit(ch))
                digit = true;

            if (sp.find(ch) != string::npos)
                special = true;

            if (i > 0 && password[i] == password[i - 1])
                return false;
        }

        return lower && upper && digit && special;
    }
};