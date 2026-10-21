class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        
        int ok = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] < s[i-1]) {
                ok = 0;
                break;
            }
        }
        
        if(ok) return 0;
        if(n == 2) return -1;
        
        char small = s[0];
        char big = s[0];
        
        for(int i = 1; i < n; i++) {
            if(s[i] < small) small = s[i];
            if(s[i] > big) big = s[i];
        }
        
        if(s[0] == small || s[n-1] == big)
            return 1;
        
        for(int i = 1; i < n-1; i++) {
            if(s[i] == small || s[i] == big)
                return 2;
        }
        
        return 3;
    }
};