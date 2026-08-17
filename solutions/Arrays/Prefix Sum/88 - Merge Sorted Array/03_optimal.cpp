class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = nums1.size() - 1;
        int p2 = nums2.size() - 1;
        int p3 = m - 1;

        while (p2 >= 0) {
            if (p3 < 0) {
                nums1[p1] = nums2[p2];
                p1--;
                p2--;
            }
            else if (nums2[p2] > nums1[p3]) {
                nums1[p1] = nums2[p2];
                p1--;
                p2--;
            }
            else {
                nums1[p1] = nums1[p3];
                p1--;
                p3--;
            }
        }
    }
};