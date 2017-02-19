https://leetcode.com/problems/longest-palindromic-substring/?tab=Description
class Solution {
public:
    string longestPalindrome(string s) {

        string rString = "";
        for (int i = 0; i < s.length(); ) {

            int head = i;
            int tail = i;
            while(inBounds(s,tail) && s[head] == s[tail]){
                tail++;
            }
            i = tail;
            tail--;
            // assume start is middle
            while ( inBounds(s, head) &&
                    inBounds(s, tail) &&
                    s[head] == s[tail])
            {
                head--;
                tail++;
            }
            head++;
            string pal = s.substr(head, tail-head);
            if(rString.length() < pal.length())
                rString = pal;
        }
        return rString;
    }
    /*
    string findPal(string s, int start) {
        if( ! inBounds(s,start))
            return "";
            
        int head = start;
        int tail = start;
        while(inBounds(s,tail) && s[head] == s[tail])
            tail++;
        tail--;
        string rString;
        
        // assume start is middle
        while ( inBounds(s, head) &&
                inBounds(s, tail) &&
                s[head] == s[tail]
            )
            {
                head--;
                tail++;
            }
        head++;
        rString = s.substr(head, tail-head);
        
        
        // assume start is pair middle
        
        head = start;
        tail = start+1;
        if( inBounds(s,tail)){
            while ( inBounds(s, head) &&
                    inBounds(s, tail) &&
                    s[head] == s[tail]
                )
                {
                    head--;
                    tail++;
                }
            head++;
            
            if(s.substr(head,tail-head).length() > rString.length())
            rString = s.substr(head, tail-head);
        }
        
        return rString;
    }
    */
    bool inBounds(string s, int i) {
        if (i < 0 || i >= s.length()) {
            return false;
        }
        else
            return true;
    }
};
