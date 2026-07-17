class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int rb=0;
        for(int val:data){
            if(rb==0){
                if((val>>7)==0){
                    rb=0;
                }
                else if((val>>5)==6){
                    rb=1;
                }
                else if((val>>4)==14){
                    rb=2;
                }
                else if((val>>3)==30){
                    rb=3;
                }
                else{
                    return false;
                }
            }
            else{
                if((val>>6)==2){
                    rb--;
                }
                else{
                    return false;
                }
            }

        }
        return rb==0;
    }
};
