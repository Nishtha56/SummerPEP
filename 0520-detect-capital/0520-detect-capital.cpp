class Solution {
public:
    bool detectCapitalUse(string word) {
        int ct=0;
        int n=word.length();
        for(char c : word){
            if(isupper(c)){
                ct++;
            }
        }
        if(ct==0 || ct==n){
            return true;
        }
        if(ct==1 && isupper(word[0])){
            return true;
        }
        return false;
    }
};