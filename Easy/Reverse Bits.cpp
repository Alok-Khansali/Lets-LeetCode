#define R2(n)     n,     n + 2*64,     n + 1*64,     n + 3*64                  //Look Up Table Implementation
#define R4(n) R2(n), R2(n + 2*16), R2(n + 1*16), R2(n + 3*16)   
#define R6(n) R4(n), R4(n + 2*4 ), R4(n + 1*4 ), R4(n + 3*4 )
unsigned int lt[256] = { R6(0), R6(2), R6(1), R6(3) };
class Solution {
public:
    uint32_t reverseBits(uint32_t num) {
       uint32_t a = 0;
        // Mask used   =>  `0xff` is `11111111` in binary
     a = lt[num & 0xff ]<<24 | lt[(num >> 8) & 0xff ]<<16 | lt[(num >> 16 )& 0xff ]<< 8 |lt[(num >> 24 ) & 0xff] ;
    return a;
    }
};
