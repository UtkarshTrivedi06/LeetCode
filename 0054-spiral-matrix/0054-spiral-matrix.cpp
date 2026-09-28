class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> n;
        int t=0,b=matrix.size()-1,l=0,r=matrix[0].size()-1;
        while(t<=b && l<=r){
            for(int i=l;i<=r;i++){
                n.push_back(matrix[t][i]);
            }
            t++;
            for(int i=t;i<=b;i++){
                n.push_back(matrix[i][r]);
            }
            r--;
            if (t <= b) {
                for (int i = r; i >= l; i--) {
                    n.push_back(matrix[b][i]);
                }
                b--;
            }
            if (l <= r) {
                for (int i = b; i >= t; i--) {
                    n.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        return n;
    }
};