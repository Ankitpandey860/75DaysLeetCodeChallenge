class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=n+m-1;
        n--;
        m--;
        while(i>=0&&m>=0&&n>=0){
            if(nums1[m]>nums2[n]){
                nums1[i]=nums1[m];
                m--;
            }
            else{
                nums1[i]=nums2[n];
                n--;
            }
            i--;
        }
        while(i>=0&&m>=0){
            nums1[i]=nums1[m];
            m--;
            i--;
        }
        while(i>=0&&n>=0){
            nums1[i]=nums2[n];
            n--;
            i--;
        }
    }
};