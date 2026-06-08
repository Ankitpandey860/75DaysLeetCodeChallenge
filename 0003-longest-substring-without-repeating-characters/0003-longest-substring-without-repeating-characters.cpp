class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi=0;
        
        
        
        for(int i=0;i<s.length();i++){
            int st=i;
            int count=0;
            vector<bool> store(256,0);
            bool empty=false;
            while(st<s.length()){
                 if(s[st]==' '&&!empty){
                    count++;
                    empty=true;
                }
                else if (s[st] != ' ' && !store[(unsigned char)s[st]]) {
                    store[(unsigned char)s[st]] = true;
                    count++;
                }  
                else{
                    
                    break;
                }
                maxi=max(maxi,count);
                st++;
            }
           
        }
        return maxi;
    }
};