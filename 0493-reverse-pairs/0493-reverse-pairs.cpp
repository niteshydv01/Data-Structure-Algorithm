/*class Solution {
public:
    /*int reversePairs(vector<int>& nums) {
        int m=nums.size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                if((long)nums[i]>2*(long)nums[j]){
                    count++;
                }

        
            }
        }
        return count;
        
    }*/
    
class Solution {
public:
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;

        int mid = (left + right) / 2;
        int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);

        // Count reverse pairs
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long)nums[i] > 2L * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        // Merge step
        vector<int> temp;
        int i = left;
        j = mid + 1;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }
        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= right) temp.push_back(nums[j++]);

        for (int k = left; k <= right; k++) {
            nums[k] = temp[k - left];
        }

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
