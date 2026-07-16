class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int n=height.size();
        int right=n-1;
        int maximumareaa=1;
        while(left<right){
            int area;
            
            area=(right-left)*min(height[left],height[right]);
            maximumareaa=max(area,maximumareaa);
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
            
            
        }
        return maximumareaa;
    }
};