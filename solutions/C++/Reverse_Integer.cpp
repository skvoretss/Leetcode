class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int size = 1;
        int t = abs(x);
        while (t > 9) {
            t /= 10;
            size *= 10;
        }
        t = abs(x);
        if (size < 1000000000) {
            while (t > 0) {
                res += (t % 10) * size;
                t /= 10;
                size /= 10;
            }
            if (x < 0) res *= -1;
        }
        else {
            int int_max = INT_MAX;
            while (t > 0) {
                //cout << "res = " << res << "\n";
                if (size == 1000000000 && t%10 > 2) return 0;
                res += (t % 10) * size;
                t /= 10;
                size /= 10;
                if (int_max - res < (t%10)*size) return 0;
            }
            if (x < 0) res *= -1;
        }
        return res;
    } //2 147 483 647
};