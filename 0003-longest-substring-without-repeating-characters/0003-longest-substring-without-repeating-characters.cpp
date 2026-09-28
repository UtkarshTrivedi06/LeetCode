class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int v[256]={0};
        int c=0,max=0,l=0,r=0;
        for(r=0;r<s.length();r++){
            if(v[s[r]]==0){
                c++;
                v[s[r]]++;
                if(c>max){
                    max=c;
                }
            }
            else{
                while(v[s[r]]>0){
                    v[s[l]]--;
                    c--;
                    l++;
                }
                v[s[r]]++;
                c++;
            }
        }
        return max;
    }   
        
};