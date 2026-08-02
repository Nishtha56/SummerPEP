class Solution {
public:
    int countValidPrefixes(string s) {
        int c=0;
        int z=0;
        int o=0;

        for(char ch : s){
            if(ch=='0'){
                z++;
            }
            else{
                o++;
            }
            if(abs(z-o)<=1){
                c++;
            }
        
        
        }
        return c;
        
    }
};