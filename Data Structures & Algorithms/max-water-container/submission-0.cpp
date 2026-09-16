class Solution {
public:
    int maxArea(vector<int>& heights) {
        int idx1 = 0;
        int idx2 = heights.size() - 1;

        int result = 0;
        int temp = 0;
        while (idx1 < idx2) {
            temp = min(heights[idx1], heights[idx2]) * (idx2-idx1);
            result = max(result, temp);

            if (heights[idx1] <= heights[idx2]) {
                idx1++;
            } else {
                idx2--;
            }
        }
        
        return result;
        
    }
};
