class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> n(nums.size());
        int pin=0,nin=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                n[pin]=nums[i];
                pin+=2;
            }
            else{
                n[nin]=nums[i];
                nin+=2;
            }
        }
        return n;
    }
};