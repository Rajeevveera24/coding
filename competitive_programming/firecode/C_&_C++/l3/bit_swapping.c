// Given a 32 bit integer input x, swap its odd and even bits 
// sequentially and return the resulting integer. 
// (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped and so on).

// stdio.h, string.h have been included for this problem.
// You don't need any other header files.

// Add any helper function(if needed) here and above.
int swap_odd_even_bits(int x){
   int odd_bits = x & 0xAA;
   odd_bits = odd_bits >> 1;
   int even_bits = x & 0x55;
   even_bits = even_bits << 1;
   return odd_bits | even_bits;
}