class Solution {
public:
    int reverse(int x) {
        stack<int> stack;
        long int ans = 0;
        while(x){
            stack.push(x % 10);
            x = x / 10;
        }
        long int i = 1;
        while(!stack.empty()){
            ans += stack.top() * i;
            stack.pop();
            i = i * 10;
        }
        
        if(ans > INT_MAX or ans < INT_MIN) return 0;
        return ans;
    }
};