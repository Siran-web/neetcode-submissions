class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;

        if(n1 > n2)
            swap(nums1 , nums2);

        n1 = nums1.size();
        n2 = nums2.size();

        int left = (n + 1)/2;
        int s = 0 , e = n1;

        while(s <= e){
            int m1 = (s + e)/2;
            int m2 = left - m1;

            int l1 = INT_MIN , l2 = INT_MIN;
            int r1 = INT_MAX , r2 = INT_MAX;

            if(m1 < n1) r1 = nums1[m1];
            if(m1 > 0) l1 = nums1[m1 - 1];

            if(m2 < n2) r2 = nums2[m2];
            if(m2 > 0) l2 = nums2[m2 - 1];

            if(l1 <= r2 && l2 <= r1){
                if(n % 2 != 0) return max(l1 , l2);
                else
                    return (double) (max(l1 , l2) + min(r1 , r2))/2;
            }

            else if(l1 < r2)
                s = m1 + 1;
            else 
                e = m1 - 1;    
        }
        return -1;
    }
};
