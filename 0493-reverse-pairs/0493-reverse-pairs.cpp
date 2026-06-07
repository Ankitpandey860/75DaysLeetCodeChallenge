class Solution {
public:

    void merge(vector<int>& arr, int l, int mid, int r) {
        vector<int> temp;

        int i = l;
        int j = mid + 1;

        while(i <= mid && j <= r) {
            if(arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
            }
        }

        while(i <= mid) {
            temp.push_back(arr[i++]);
        }

        while(j <= r) {
            temp.push_back(arr[j++]);
        }

        for(int k = l; k <= r; k++) {
            arr[k] = temp[k - l];
        }
    }

    int countPairs(vector<int>& arr, int low, int mid, int high) {

        int right = mid + 1;
        int cnt = 0;

        for(int i = low; i <= mid; i++) {

            while(right <= high &&
                  (long long)arr[i] > 2LL * arr[right]) {
                right++;
            }

            cnt += (right - (mid + 1));
        }

        return cnt;
    }

    int mergeSort(vector<int>& arr, int l, int r) {

        if(l >= r) return 0;

        int mid = (l + r) / 2;

        int cnt = 0;

        cnt += mergeSort(arr, l, mid);
        cnt += mergeSort(arr, mid + 1, r);

        cnt += countPairs(arr, l, mid, r);

        merge(arr, l, mid, r);

        return cnt;
    }

    int reversePairs(vector<int>& nums) {

        return mergeSort(nums, 0, nums.size() - 1);
    }
};