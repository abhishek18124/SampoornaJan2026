class Solution {
public:

	// time : O(n)
	// space: O(1)

	int maxArea(vector<int>& height) {
		int i = 0;
		int j = height.size() - 1;
		int maxSoFar = 0; // to track the answer

		while (i < j) {
			int width = j - i;
			int hgt = min(height[i], height[j]);
			int area = width * hgt;
			maxSoFar = max(maxSoFar, area);
			if (height[i] < height[j]) {
				i++;
			} else {
				j--;
			}
		}

		return maxSoFar;

	}
};