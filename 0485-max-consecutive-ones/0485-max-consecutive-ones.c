int findMaxConsecutiveOnes(int* nums, int numsSize) {
    bool con=false;
    int c=0;
    int max=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]==1){
            if(con==false){
                c=1;
                con=true;
                if(c>max){
                    max=c;
                }
            }
            else{
                c++;
                if(c>max){
                    max=c;
                }
            }
        }
        else{
            con=false;
        }
    }
    return max;
}