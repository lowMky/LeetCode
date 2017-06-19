class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int numcnt = nums.size();
        for(int i = 0;i<numcnt;){
            if(nums[i]<=0 || nums[i]>=numcnt+1){
                ++i;continue;
            }
            if(nums[i]!=i+1 && nums[nums[i]-1]!=nums[i])
                    swap(nums[nums[i]-1],nums[i]);
            else
                ++i;
        }
        
        for(int i = 0;i<numcnt;++i)
            if(nums[i]!=i+1)
                return i+1;
        return numcnt+1;
    }
};