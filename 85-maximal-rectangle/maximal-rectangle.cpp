class Solution {
public:
    // Function to find Largest Rectangle in Histogram
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();

                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        // Step 1: If matrix is empty
        if (matrix.empty())
            return 0;

        // Step 2: Initialize
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> height(cols, 0);
        int maxArea = 0;

        // Step 3: Traverse each row
        for (int i = 0; i < rows; i++) {

            // Step 4: Update histogram
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    height[j] = height[j] + 1;
                else
                    height[j] = 0;
            }

            // Step 5: Find largest rectangle in current histogram
            int histogramArea = largestRectangleArea(height);

            // Step 6: Update answer
            maxArea = max(maxArea, histogramArea);
        }

        // Step 7: Return maximum area
        return maxArea;
    }
};