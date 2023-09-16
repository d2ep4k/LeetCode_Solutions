class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> prevSmaller(heights.size());
        vector<int> nextSmaller(heights.size());
        stack<int> buffer;

        //next smaller element
        for(int i=0;i<nextSmaller.size();i++){
            while(!buffer.empty()&&heights[buffer.top()]>heights[i]){
                nextSmaller[buffer.top()]=i;
                buffer.pop();
            }
            buffer.push(i);
        }

        while(!buffer.empty()){
            nextSmaller[buffer.top()]=nextSmaller.size();
            buffer.pop();
        }

        //previous smaller element
        for(int i=prevSmaller.size()-1;i>=0;i--){
            while(!buffer.empty()&&heights[buffer.top()]>heights[i]){
                prevSmaller[buffer.top()]=i;
                buffer.pop();
            }
            buffer.push(i);
        }

        while(!buffer.empty()){
            prevSmaller[buffer.top()]=-1;
            buffer.pop();
        }

        int maxArea=0;

        for(int i=0;i<heights.size();i++){
            int height=heights[i];
            int breadth=((nextSmaller[i]-1)-(prevSmaller[i]+1)+1);
            maxArea=max(maxArea,height*breadth);
        }
        return maxArea;
    }
};
