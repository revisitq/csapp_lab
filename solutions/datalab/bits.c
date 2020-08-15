/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  int not_x = ~x;
  int not_y = ~y;
  int part1 = x&not_y;
  int part2 = not_x&y;
  int not_ret = (~part1)&(~part2);
  return ~not_ret;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1<<31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  int cond1 = !((x+1) ^ (~x)); 
  int cond2 = !(x ^ (~0)) ;
  return cond1&(!cond2);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int allOddBits=(0xAA<<24)|(0xAA<<16)|(0xAA<<8)|0xAA; //constrcut mask
  int ret = (allOddBits & x) ^ allOddBits; //detect
  return !ret;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return (~x)+1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x){
  int condA = !((x >> 4) ^ 0x3);//事件A，在0x30~0x3F
  int condB = !(x & 0x08);      //事件B，小于0x38
  int condC = !((x & 0x0E) ^ 0x08);//事件C，是1000
  int notB = !condB;
  int ret = condA &(condB | (notB & condC));
  return ret;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int BOOL = !x;
  int mask = BOOL + (~0);
  int ret1 = mask & y;
  int ret2 = ~mask & z;
  return ret1 + ret2;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int is_equal = !(x^y);
  int Tmin = 1<<31;
  int x_sign = !(x & Tmin); //1正0负
  int y_sign = !(y & Tmin);
  int is_same_sign = !(y_sign ^ x_sign); //1 True, 0 Fasle
  int x_let_y = is_equal | ((!x_sign) & y_sign);
  /*condition 1: X and y are same sign.Using complement number.
    condition 2: X and y are not same sign.Uisng sign number.
   */
  int not_mask = is_same_sign + (~0);
  int x_minus_y = x + ((~y) + 1);
  int x_minus_y_bt_0 = !(((~not_mask) & x_minus_y) & Tmin);
  int ret = x_let_y | (!x_minus_y_bt_0) ;
  return ret;
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  int revert_x = ~x;
  int not_negate = revert_x >> 31; //0代表是负数，1包含两种情况（整数或0）
  int x_minus_1 = x + (~1) + 1; 
  int x_bt_1= x_minus_1 >> 31;//为0时代表x>1，为1代表x<=1
  int is_zero = not_negate & ((x_bt_1) & (x ^ 1));
  return is_zero;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int tmp = 1 | (1 << 8);
  int mask = tmp | (tmp << 16);
  int part0, part1, part2, part3, not_zero_part1, not_zero_part2, not_zero_part3;
  int not_equal_part_32, not_equal_part_21, not_equal_part_10;  
  int bits_counter;
  int mask1,mask2,not_zero_mask;
  int not_zero_last_part;
  int bit7 = (x >> 7) & mask;
  int bit6 = (x >> 6) & mask; 
  int bit5 = (x >> 5) & mask;
  int bit4 = (x >> 4) & mask;
  int bit3 = (x >> 3) & mask;
  int bit2 = (x >> 2) & mask;
  int bit1 = (x >> 1) & mask;
  int bit0 = x & mask;
  int cross_bit = (x << 1) & mask;

  int not_euqal_76 = bit7 ^ bit6;
  int not_euqal_65 = bit6 ^ bit5;
  int not_euqal_54 = bit5 ^ bit4;
  int not_euqal_43 = bit4 ^ bit3;
  int not_euqal_32 = bit3 ^ bit2;
  int not_euqal_21 = bit2 ^ bit1;
  int not_euqal_10 = bit1 ^ bit0;
  int not_equal_cross = cross_bit ^ bit0;
  /*处理4个part*/
  int bit_8_counter = mask + not_euqal_76;

  int not_equal = not_euqal_76 | not_euqal_65;
  bit_8_counter = bit_8_counter + not_equal;

  not_equal = not_equal | not_euqal_54;
  bit_8_counter = bit_8_counter + not_equal;

  not_equal = not_equal | not_euqal_43;
  bit_8_counter = bit_8_counter + not_equal;

  not_equal = not_equal | not_euqal_32;
  bit_8_counter = bit_8_counter + not_equal;

  not_equal = not_equal | not_euqal_21;
  bit_8_counter = bit_8_counter + not_equal;

  not_equal = not_equal | not_euqal_10;
  bit_8_counter = bit_8_counter + not_equal;
  /*逐步计算*/
  not_zero_part3 = (not_equal >> 24);
  not_zero_part2 = (not_equal >> 16);
  not_zero_part1 = (not_equal >> 8);
  not_equal_part_32 = (not_equal_cross >> 24);
  not_equal_part_21 = (not_equal_cross >> 16);
  not_equal_part_10 = (not_equal_cross >> 8);

  part3 = bit_8_counter >> 24;
  part2 = bit_8_counter >> 16;
  part1 = bit_8_counter >> 8;
  part0 = bit_8_counter;

  not_zero_mask = (~not_zero_part3) + 1;
  part3 = (not_zero_mask & part3) | ((~not_zero_mask) & not_equal_part_32);

  not_zero_last_part = not_zero_part3 | not_equal_part_32;
  mask1 = ~not_zero_last_part + 1;
  tmp = not_zero_part2 | not_equal_part_21;
  mask2 = ~tmp + 1;
  part2 = (mask1 & 8) | ((~mask1) & mask2 & part2);

  not_zero_last_part = not_zero_last_part | tmp;
  mask1 = ~not_zero_last_part + 1;
  tmp = not_zero_part1 | not_equal_part_10;
  mask2 = ~tmp + 1;
  part1 = (mask1 & 8) | ((~mask1) & mask2 & part1);

  not_zero_last_part = not_zero_last_part | tmp;
  mask1 = (~not_zero_last_part) + 1;
  part0 = (mask1 & 8) | ((~mask1) & part0);
  /*求和*/
  bits_counter = part3 + part2  + part1 + part0;
  return bits_counter & 0xFF;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  return 2;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  return 2;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    return 2;
}
