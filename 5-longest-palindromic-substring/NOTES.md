DYNAMIC APPROACH
​
PALINDROME in DP -> If its first and last elements are same and the substring after excluding the first and last character is a palindrome.
​
Hence we can now reduce a bigger problem to smaller problem whose answer may be previously known.
​
Use a matrix where dp[ i ] [ j ] represents substring from ith pos to jth pos.
​
All single characters are palindromes, thus substring with a length 1 are substring by default.
​
substrings of length 2 are palin if both characters are same.
​
And for rest of lengths use the sub problem.
​
Now we need longest so the palindromic substring with longest length is the substring.