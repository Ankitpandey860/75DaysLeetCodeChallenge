class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
    char ans=letters[0];
    int end=letters.size()-1;
    int s=0;
    while(s<=end){
        int mid = s+(end-s)/2;
        if(target<letters[mid]){
            ans = letters[mid];
            end = mid-1;
        }
        else{
            s=mid+1;
        }
    }
return ans;
    }
};