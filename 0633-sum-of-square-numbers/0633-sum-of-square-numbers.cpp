class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l=0;
        long long r=sqrt(c);
        
        while(l<=r){
            
            long long sum=(r*r)+(l*l);
            
            if(sum==c){
                return true;
            }
            else if(sum<c){
                l++;
            }
            else{
                r--;
            }
        }
        return false;
    }
};