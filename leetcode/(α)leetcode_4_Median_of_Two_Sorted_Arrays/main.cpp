#include <iostream>
#include <vector>
#include <climits>
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        std::cout<<m<<std::endl;
        std::cout<<nums1[2]<<std::endl;
        if (m < n) return findMedianSortedArrays(nums2, nums1);
        if (n == 0) {
            // trick: 如果是浮點數, 直接進位成為同樣的數
            std::cout<<m;
            return ((double)nums1[(m - 1) / 2] + (double)nums1[m / 2]) / 2.0;
        }
        int left = 0, right = n * 2;
        while (left <= right) {
            
            int mid2 = (left + right) / 2;
            int mid1 = m + n - mid2;
            std::cout<<mid1;
            double L1 = mid1 == 0 ? INT_MIN : nums1[(mid1 - 1) / 2];
            double L2 = mid2 == 0 ? INT_MIN : nums2[(mid2 - 1) / 2];
            double R1 = mid1 == m * 2 ? INT_MAX : nums1[mid1 / 2];
            double R2 = mid2 == n * 2 ? INT_MAX : nums2[mid2 / 2];
            if (L1 > R2) left = mid2 + 1;
            else if (L2 > R1) right = mid2 - 1;
            else return (std::max(L1, L2) + std::min(R1, R2)) / 2;
        }
        return -1;
    }

int main() {
    std::vector<int> a{1,2,3};
    std::vector<int> b{4,5,6,7};
    double ans = findMedianSortedArrays(a,b);
    std::cout<<ans;
    return 0;
}