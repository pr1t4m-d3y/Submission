class Solution {
private:
    vector<int> findPrev(vector<int> &arr, int size){
        stack<int> stack;
        stack.push(-1);
        vector<int> ans(size);

        for (int i=0;i<size;i++){
            while (stack.top()!=-1 && arr[i]<=arr[stack.top()]) stack.pop();
            ans[i]=stack.top();
            stack.push(i);
        }
        return ans;
    }

    vector<int> findNext(vector<int>&arr, int size){
        stack<int> stack;
        stack.push(-1);
        vector<int> ans(size);
        for (int i=size-1;i!=-1;i--){
            while (stack.top()!=-1 && arr[i]<=arr[stack.top()]) stack.pop();
            ans[i]=stack.top();
            stack.push(i);
        }
        return ans;
    }

    int findArea(vector<int> &arr, int size){
        vector <int> next(size);
        next=findNext(arr, size);

        vector<int> prev(size);
        prev=findPrev(arr, size);
        int maxA=INT_MIN;

        for (int i=0;i<size;i++){
            int l=arr[i];
            if (next[i]==-1) next[i]=size;
            int b=next[i]-prev[i]-1;

            int area=l*b;
            maxA=max(maxA,area);
        }
        return maxA;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int cols=matrix[0].size();
        int rows=matrix.size();

        vector<int> arr(cols,0);
        int maxA=INT_MIN, area;

        for (int i=0;i<rows;i++){
            for (int j=0;j<cols;j++){
                if (matrix[i][j]=='0') arr[j]=0;
                else arr[j]++;
            }
            area=findArea(arr, arr.size());
            maxA=max(maxA, area);
        }
        return maxA;
    }
};