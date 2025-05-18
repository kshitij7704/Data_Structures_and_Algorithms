// Leetcode - 9

class Solution {
public:
    bool isPalindrome(int x) {
        long int digit = 0;
        long int rev = 0;
        long int temp = x;
        if(x < 0)
            return false;
        while(x != 0){
            digit = x % 10;
            rev = (rev * 10) + digit;
            x /= 10;
        }
        if(temp == rev)
            return true;
        else
            return false;
    }
};
