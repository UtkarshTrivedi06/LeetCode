class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(),minn,maxn;
        bool r = false;
        bool s = true;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                if(r==false){
                    minn=nums[i];
                    maxn=nums[0];
                    r=true;
                }
            }
            if(r==true){
                if(nums[i]>=minn && nums[i]<=maxn){
                    minn=nums[i];
                }
                else{
                    s=false;
                }
            }
        }
        return s;
    }
};