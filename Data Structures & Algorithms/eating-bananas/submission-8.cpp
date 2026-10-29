class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long totalTime;
        long long lower = 1;
        long long r = *max_element(piles.begin(), piles.end());
        long long upper = r;
        long long mid;
        long long res;
        while (lower <= upper) {
            mid = (lower + upper) / 2;
            totalTime = 0;
            for (long long banana: piles) {
                totalTime += ceil(static_cast<double>(banana) / mid);
            }
            if (totalTime <= h) {
                res = mid;
                upper = mid - 1;
            } else if (totalTime > h) {
                lower = mid + 1;
            }
        }
        return res;
    }
};
