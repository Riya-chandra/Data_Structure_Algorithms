// Input:  [2, 1, 5, 6, 2, 3]
// Output: 10


#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n=heights.size();
    stack<int>st;
    //monotonicagr bara hai toh add krte jaow 
    //boundary condition  
    if(heights[0]>heights[1]){
        //toh start yaha se toh nhi ho skta
    }
    for(int i=0;i<n;i++){
    while(!st.empty() && heights[st.top()]>=heights[i])
        st.pop();
        left[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    while(!st.empty()) st.top();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && heights[st.top()]>=heights[i])
        st.pop();
         right[i] = st.empty() ? n : st.top();
         st.push(i);
    }
    int maxArea=0;
    for(int i=0;i<n;i++){
        int width=right[i]-left[i]-1;
        maxArea=max(maxArea,heights[i]*width);
    }
    return maxArea;
}

int main() {
    vector<int> heights = {2,1,5,6,2,3};
    cout << largestRectangleArea(heights);
    return 0;
}