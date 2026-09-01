class Solution {
public:
    int maxProfit(vector<int>& p) {
        int min=p[0],maxp=0;
        for(int i=1;i<p.size();i++){
            if(min>p[i]){
                min=p[i];
            }
            else if(maxp<p[i]-min){
                maxp=p[i]-min;
            }
        }
        return maxp;
    }
};