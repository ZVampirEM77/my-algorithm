class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty()) {
            int size = nums2.size();
            if (size % 2 == 0) {
                return (nums2[size / 2 - 1] + nums2[size / 2]) / 2.0;
            } else {
                return nums2[size / 2];
            }
        } else if (nums2.empty()) {
            int size = nums1.size();
            if (size % 2 == 0) {
                return (nums1[size / 2 - 1] + nums1[size / 2]) / 2.0;
            } else {
                return nums1[size / 2];
            }
        }
        
        vector<int> short_v;
        vector<int> long_v;
        if (nums1.size() <= nums2.size()) {
            short_v = nums1;
            long_v = nums2;
        } else {
            short_v = nums2;
            long_v = nums1;
        }
        
        int m = short_v.size();
        int n = long_v.size();
        int imin = 0;
        int imax = m;
        int i = 0, j = 0;
        
        while (imin <= imax)
        {
            i = (imin + imax) / 2;
            j = (m + n + 1) / 2 - i;
            if (((i == 0) || (j == n) || (short_v[i - 1] <= long_v[j])) &&
                ((j == 0) || (i == m) || (long_v[j - 1] <= short_v[i]))) {
                break;
            } else if (i > imin && short_v[i - 1] > long_v[j]) {
                imax = i - 1;
            } else if (i < imax && long_v[j - 1] > short_v[i]) {
                imin = i + 1;
            }
        }
        // even number
        if ( (m + n) % 2 == 0 ) {
            if (i == 0 && j != n) {
                return ((long_v[j - 1] + std::min(long_v[j], short_v[i])) / 2.0);
            } else if (i == 0 && j == n){
                return ((long_v[j - 1] + short_v[i]) / 2.0);
            } else if (i == m && j != 0) {
                return ((std::max(long_v[j - 1], short_v[i - 1]) + long_v[j]) / 2.0);
            } else if (i == m && j == 0) {
                return ((short_v[i - 1] + long_v[j]) / 2.0);
            } else {
                return ((std::max(short_v[i - 1], long_v[j - 1]) + std::min(short_v[i], long_v[j])) / 2.0); 
            }
        // odd number
        } else {
            if (i == 0) {
                return long_v[j - 1];
            } else {
                return std::max(short_v[i - 1], long_v[j - 1]);
            }
        }
    }
};

// from https://github.com/MaskRay
// nice!!
class Solution {
public:
    double findMedianSortedArrays(vector<int> &a, vector<int> &b) {
      int m = a.size(), n = b.size(), i = 0, j = 0, k = m+n-1 >> 1;
      while (k > 0) {
        int p = k-1 >> 1;
        if (j+p >= n || i+p < m && a[i+p] < b[j+p])
          i += p+1;
        else
          j += p+1;
        k -= p+1;
      }
      int s = j >= n || i < m && a[i] < b[j] ? a[i++] : b[j++];
      return m+n & 1 ? s : (j >= n || i < m && a[i] < b[j] ? s+a[i] : s+b[j]) * 0.5;
    }
};
