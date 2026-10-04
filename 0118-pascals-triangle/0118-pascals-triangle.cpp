class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        for(int i=0;i<numRows;i++){
            vector<int> s(i+1);
            s[0]=1;
            s[i]=1;
            if(i>1){
                for(int j=1;j<i;j++){
                    s[j]=v[i-1][j-1]+v[i-1][j];
                }
            }
            v.push_back(s);

        }
        return v;
    }
};