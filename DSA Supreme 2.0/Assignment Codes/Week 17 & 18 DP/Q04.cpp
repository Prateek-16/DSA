//https://leetcode.com/problems/longest-palindromic-substring/description/


//Longest Palindromic Substring


/*

Approach - palindrome Find karene ke 2 tarike ho sakte hai, 
1st will be 2 points se pointer leke andar ko ao and 
2nd will be centre se bahar ko jao 
is question mai centre se bahar wali approach beast hogi

2 types of palindromes ban sakte hai:

1. Odd palindrome  : centre single element hai toh waha se bahar ko jana hai 

2. even palindrome : even mai current and curr + 1 wala centre hoga toh woh equal hone chahoye and then waha se bahar ko jana hai

*/


class Solution {
public:
    void checkpalindrome(string s, int i, int j, int& start, int& max_size) {

        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            i--;
            j++;
        }
        if (j - i - 1 > max_size) {
            start = i + 1;
            max_size = j - i - 1;
        }
    }
    string longestPalindrome(string s) {
        int start = 0;
        int max_size = 1;
        for (int i = 0; i < s.length()-1; i++) {
            // odd
            checkpalindrome(s, i, i, start, max_size);
            // even
            checkpalindrome(s, i, i + 1, start, max_size);
        }
        return s.substr(start,max_size);
    }
};