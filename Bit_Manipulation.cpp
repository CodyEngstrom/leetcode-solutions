#include <include.h>

// ^ xor    |   1 ^ 1 = 0, 0 ^ 1 = 1, 0 ^ 0 = 0
// | or     |   1 ^ 1 = 1, 0 ^ 1 = 1, 0 ^ 0 = 0
// & and    |   

// 136. Single Number
class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int result = 0x0;
        for(int i = 0; i < nums.size(); i++) {
            result ^= nums[i];
        }

        return result;
    }
};


// 191. Number of 1 Bits
// 

// Count = 0;



// 0010 1101
// n >>= 1
// 0001 0110
// n & 1

// n & 0x1

// 0000 0001
// if(n & 0x1 == 1)
// count += n & 0x1;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            count += n & 0x1;
            n >>= 1;
        }
        return count;
    }
};

// 190. Reverse Bits


// shift result left by 1
// or last bit in n onto results last bit
// shift n to right by 1



class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) { 
            result <<= 1;
            result |= (n & 0x1);
            n >>= 1;
        }
        return result;
    }
};