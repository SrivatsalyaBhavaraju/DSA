class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxarea=1;
        for(int i=0;i<n;i++){
            int area=1;
            for(int j=i;j<n;j++){
                area=min(height[i],height[j])*(j-i);
                
            }

        maxarea=max(maxarea,area);
        }
    return maxarea;
    }
};