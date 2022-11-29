class Solution
{
    public:
        string fractionToDecimal(int numerator, int denominator)
        {
           	// edge cases
            if (!numerator) return "0";
            string ans;

           	// or to check when only one of them is true
            if (numerator > 0 ^ denominator > 0) ans += '-';

           	// absolute values
            long n = labs(numerator), d = labs(denominator);

           	// decimal part
            long r = n % d;

           	// integral part
            ans += to_string(n / d);

           	// if no decimal part
            if (!r) return ans;

           	// decimal part calaculation
            ans += '.';
            unordered_map<long, int> rs;
            while (r)
            {
                if (rs.find(r) != rs.end())
                {
                    ans.insert(rs[r], "(");
                    ans += ')';
                    break;
                }
                rs[r] = ans.size();
                r *= 10;
                ans += to_string(r / d);
                r %= d;
            }
            return ans;
        }
};