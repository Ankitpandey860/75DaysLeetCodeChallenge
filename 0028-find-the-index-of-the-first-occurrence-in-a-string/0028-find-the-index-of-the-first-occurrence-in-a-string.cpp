class Solution {
public:
    int strStr(string haystack, string needle) {
        int count=0;
        //int st=0;
        for(int i=0;i<haystack.length();i++){
            
            if(haystack[i]==needle[count]){
                count++;
            }
            else{
                i=i-count;
                count=0;
            }
            if(count==needle.length()){
                return i-count+1;
            }
        }
        return -1;
    }
};