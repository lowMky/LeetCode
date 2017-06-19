class Solution {
public:
    int rob(vector<int>& nums) {
        int numcnt = nums.size();
        if(numcnt == 0)
            return 0;
        for(int i = 0;i<numcnt;++i){
            if(i == 2)
                nums[i] += nums[0];
            if(i>2)
                nums[i] += max(nums[i-2],nums[i-3]);
            nums[i] = max(nums[i-1],nums[i]);
        }
        return nums[numcnt-1];
    }
};