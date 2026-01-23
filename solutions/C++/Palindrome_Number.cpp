class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int t = x;
        int x_digits = 0;
        while (t > 0) {
            x_digits++;
            t /= 10;
        }
        t = x;
        while (t > 0) {
            if (t % 10 != t / static_cast<int>(pow(10, x_digits-1))) {
                return false;
            };
            t %= static_cast<int>(pow(10, x_digits-1));
            t /= 10;
            x_digits -= 2;
        }
        return true;
    }
};