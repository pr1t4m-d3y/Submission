class Solution {
    private:
        vector <int> nextSmallerElement(vector<int> &heights, int n){
            stack<int> stack;
            stack.push(-1);
            vector<int> ans(n);
            for (int i=n-1;i!=-1;i--){
                while (stack.top()!=-1 && heights[stack.top()]>=heights[i]) stack.pop();
                ans[i]=stack.top();
                stack.push(i);
            }
            return ans;
        }

        vector<int> prevSmallerElement(vector<int> &heights, int n){
            stack<int>stack;
            stack.push(-1);
            vector<int> ans(n);

            for (int i=0;i<n;i++){
                while (stack.top()!=-1 && heights[stack.top()]>=heights[i]) stack.pop();
                ans[i]=stack.top();
                stack.push(i);
                
            }
            return ans;
        }
public:
    int largestRectangleArea(vector<int>& heights) {
        int  n=heights.size();
        vector <int> next(n);
        next=nextSmallerElement(heights, n);

        vector<int> prev(n);
        prev=prevSmallerElement(heights, n);

        int maxArea=0;


        for (int i=0;i<n;i++){
            int l=heights[i];
            if (next[i]==-1) next[i]=n;
            int b=next[i]-prev[i]-1;
            int area=(l*b);
            

            maxArea=max(area, maxArea);
        }
        return maxArea;
    }
};