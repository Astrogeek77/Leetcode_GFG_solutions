// class Solution {
// public:
//     int countOdds(int low, int high) {
//         return ceil((double)high / 2) - floor((double)low / 2);
//     }
// };

// class Solution {
// public:
//     int countOdds(int low, int high) {
//        	// make sure the start number is odd
//         if ((low & 1) == 0) {
//             low += 1;
//         }
//        	// make sure the end number is even
//         if ((high & 1) == 1) {
//             high += 1;
//         }

//        	// so that now, the number between start and end is even
//         return (high - low + 1) / 2;
//     }
// };

class Solution
{
    bool isDivisibleBy2(int num)
    {
        return num % 2 == 0;
    }
    public:
        int countOdds(int low, int high)
        {
            int diff = high - low + 1;
            return (isDivisibleBy2(low) == false) ? (diff / 2 + diff % 2) : (diff / 2);
        }
};