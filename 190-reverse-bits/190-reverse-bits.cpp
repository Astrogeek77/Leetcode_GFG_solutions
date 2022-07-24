class Solution
{
    public:
        uint32_t reverseBits(uint32_t n)
        {
            int res = 0;

            for (int i = 0; i < 32; i++)
            {
               	//Left Shift By 1
                res = res << 1;

               	//Check if the last bit of n is set 
               	//if it is then set the last bit of res also.
                if ((n & 1) == 1) res++;

               	//Right Shift n By 1
                n = n >> 1;
            }
            return res;
        }
};