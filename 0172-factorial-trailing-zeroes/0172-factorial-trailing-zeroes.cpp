class Solution {
public:

int calc(int n) {
	// 5^13
	int ret = 0;
	for (int i = 1; i <= 12; i++) {
		int cur = pow(5, i);
		// n / cur
		int rem = max(0, n - cur + 1);
		int md = rem % cur;
		// 1 2 3 4
		int nn = rem / cur;
		int sum = nn * (nn + 1) / 2;
		sum *= cur;
		sum = sum + md * (nn + 1);
		ret += sum;
	}
 
	return ret;
}
    int trailingZeroes(int n) {
        if(n<4)return 0;
        return calc(n)-calc(n-1);
    }
};