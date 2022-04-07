class Solution {
public:

int reverse(int x){
    int ans =0,rem;
    while(x != 0){
        rem = x%10;
        if(ans>INT_MAX/10 || ans<INT_MIN/10 )  return false;
        ans =ans*10+rem;
        x=x/10;
    }
    return ans;
}

bool isPalindrome(int x) {
    int n=x,ans;
    if (x < 0 ) return false;
    ans = reverse(x);
    if(ans == n) return true;
    return false;
    }
};