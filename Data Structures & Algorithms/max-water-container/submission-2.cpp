class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int max_area = (right - 1) * min(heights[left], heights[right]);

        while (left < right) {
            int length = min(heights[left], heights[right]);
            int breadth = (right - left);
            max_area = max(max_area, length * breadth);

            if (heights[left] <= heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
};
