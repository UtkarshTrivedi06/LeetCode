class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0],m=nums[0];
        for(int i =1;i<nums.size();i++){
            if(sum<0){
                sum=nums[i];
            }else{
                sum+=nums[i];

            }
            if(sum>m){
                m=sum;
            }
            
        }
        return m;
    }
};