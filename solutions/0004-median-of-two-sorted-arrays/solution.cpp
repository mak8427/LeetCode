class Solution {
public:

double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
    int len1 = nums1.size();
    int len2 = nums2.size();
    int total = len1 + len2;

    // Handle cases where one array is empty.
    if (len1 == 0) {
        if (len2 % 2 == 0) {
            return (nums2[len2/2 - 1] + nums2[len2/2]) / 2.0;
        } else {
            return nums2[len2/2];
        }
    }
    if (len2 == 0) {
        if (len1 % 2 == 0) {
            return (nums1[len1/2 - 1] + nums1[len1/2]) / 2.0;
        } else {
            return nums1[len1/2];
        }
    }

    int left_ptr = 0, right_ptr = 0;
    int median1 = 0, median2 = 0; // We'll keep track of the last two numbers seen.

    for (int i = 0; i <= total / 2; i++) {
        median1 = median2; // store the previous value
        if (left_ptr < len1 && (right_ptr >= len2 || nums1[left_ptr] <= nums2[right_ptr])) {
            median2 = nums1[left_ptr];
            left_ptr++;
        } else {
            median2 = nums2[right_ptr];
            right_ptr++;
        }
    }

    if (total % 2 == 0) {
        return (median1 + median2) / 2.0;
    } else {
        return median2;
    }
}
};
