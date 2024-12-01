#include <utility>
#include <vector>
using namespace std;

/*Merging to arrays in a non-descending order*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        vector<int> vresult;
        vresult.resize(m + n);
        for (size_t i = 0; i < (m + n); i++) { vresult[i] = 0; }
        
        size_t firstc = 0, secondc = 0;

        
        
        for (size_t i = 0; i < (2 * min(m, n)); i++) {

            /*Ensuring that we won't hit en empty space*/
            if (firstc >= m || secondc >= n) {
                break;
            }

            if (nums1[firstc] == 0 || nums2[secondc] == 0) {
                vresult[0] = max(nums1[firstc], nums2[secondc]);
                break;
            }
            else if ((min(nums1[firstc], nums2[secondc])) == 0 && (max(nums1[firstc], nums2[secondc])) == 0) {
                break;
            }
            else if ((min(nums1[firstc], nums2[secondc])) == 0) {
                vresult[i] = (max(nums1[firstc], nums2[secondc]));
                if (nums1[firstc] == (max(nums1[firstc], nums2[secondc]))) {
                    firstc++;
                }
                else {
                    secondc++;
                }
            }
            else if (nums1[firstc] == nums2[secondc]) {
                vresult[i] = nums1[firstc];
                vresult[i + 1] = nums2[secondc];
                firstc++;
                secondc++;
                i += 1;
            }
            else if (nums1[firstc] == (min(nums1[firstc], nums2[secondc]))) {
                vresult[i] = nums1[firstc];
                firstc++;
            }
            else {
                vresult[i] = nums2[secondc];
                secondc++;
            }
        }
        
        for (size_t i = (firstc + secondc); i < ((max(m, n) - min(m, n)) + 1); i++) {
            if (m > n) {
                vresult[i] = nums1[firstc];
                firstc++;
            }
            else if (m < n) {
                vresult[i] = nums2[secondc];
                secondc++;
            }
        }
        
        for (size_t i = 0; i < (m + n); ++i) {
            nums1[i] = vresult[i];
        }
    }
};

int main() {
    vector<int> nums1, nums2;
    nums1.resize(2);
    nums2.resize(1);
    int n = 1, m = 2;
    nums1 = { 2, 0 };
    nums2[0] = 1;
    Solution sol;
    sol.merge(nums1, m, nums2, n);
    return 0;
}