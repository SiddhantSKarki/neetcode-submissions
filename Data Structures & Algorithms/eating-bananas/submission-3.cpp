class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        bool found = false;
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int mid = 0;
        int result = r;
        while (l <= r) {
            mid = (l + r) / 2 ;
            long long total_time = 0;
            for (int& num: piles) {
                total_time += ceil(static_cast<double>(num) / mid);
            }
            if (total_time > h) {
                l = mid + 1;
            } else {
                result = mid;
                r = mid - 1;
            }
        }

        return result;
    }
};
