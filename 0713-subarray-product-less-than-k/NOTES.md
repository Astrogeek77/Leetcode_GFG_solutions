/**
*The idea is always keep an max-product-window less than K;
*Every time add a new number on the right(j), reduce numbers on the left(i), until the subarray product fit less than k again, (subarray could be empty);
*Each step introduces x new subarrays, where x is the size of the current window (j + 1 - i);
*example:
*for window (5, 2, 6), when 6 is introduced, it add 3 new subarray:
*      (6)
*   (2, 6)
*(5, 2, 6)
*/