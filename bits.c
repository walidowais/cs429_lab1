/* 
 * CS:APP Data Lab 
 * 
 * Walid Owais (EID: wo783)
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
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

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

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

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
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
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
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* We do support the IEC 559 math functionality, real and complex.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  /* uses >> arithmetic shift on x by n, then masks out the leading 1's */
  int mask, result;

  mask = ((0x1 << 31) >> n) << 1;
  result = (x >> n) & ~mask;

  return result;
}

/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
  /* uses demorgan's law with bitwise AND and complement */
  return ~(~x & ~y);
}

/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  /* uses mask to get extract signed bit, then checks if x is 0 */
  int result, mask;
  mask = 1 << 31;
  result = x & mask;
  result = result | !x;
  result = !result;

  return result;
}

/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  /* first creates mask of all odd bits, then uses mask to get rid of even bits, 
  then XOR to compare odd bits of x with mask. */
  int result, mask;
  mask = (0xAA << 24) + (0xAA << 16) + (0xAA << 8) + 0xAA;

  result = x & mask;
  result = result ^ mask;
  result = !result;

  return result;
}

/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
  /* XOR x with its signed bit shifted right all the way, then add the signed 
  bit which results in (~x + 1) for negative numbers and (x + 0) for positive 
  numbers */
  int sign = x >> 31;
  sign = sign & 1;

  return (x ^ (x >> 31)) + sign;
}

/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  /* multiply n by 8, then shift x by product, then mask with 0xFF */
  return ((x >> (n << 3)) & 0xFF);
}

/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
  /* use formula x / y == (x + y - 1) / y */

  int bias, temp, result, neg_one;

  neg_one = (~(1)) + 1;
  temp = (1 << n) + neg_one;
  bias = x >> 31;
  bias = bias & temp;

  result = x + bias;
  result = result >> n;

  return result;
}

/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
  /* splits the number into halves and compares and matches 0 with both halves */

  int current, half;
  current = x;
  half = current >> 16;

  current = current ^ half;
  half = current >> 8;

  current = current ^ half;
  half = current >> 4;

  current = current ^ half;
  half = current >> 2;

  current = current ^ half;
  half = current >> 1;

  current = current ^ half;

  return (current & 0x1);
}

/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  /* first the sign, fraction and exponent bits of uf then checks all the 
  corner cases for +/- NAN */
  int sign_mask, exp_mask, frac_mask, sign, exponent, fraction;
  // printf("%d\n", uf);
  
  sign_mask = 0x1 << 31;
  exp_mask = 0xFF << 23;
  frac_mask = (0x7F << 16) + (0xFF << 8) + 0xFF;

  exponent = uf & exp_mask;
  fraction = uf & frac_mask;
  sign = uf & sign_mask;

  if(!(exponent ^ exp_mask) && !fraction){
    // printf("NANANNANANANANA\n");
    return uf;
  }

  if(!exponent && !fraction){
    // printf("ZROROOZORZOOZRO\n");
    return uf;
  }

  if(!exponent){
    // printf("DDDDDDDDDDDDDDD\n");
    return sign + exponent + (fraction + fraction);
  }

  exponent = exponent + (1 << 23);

  return sign + exponent + fraction;
}

/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
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
int float_f2i(unsigned uf) {
  // int result, sign_mask, exp_mask, frac_mask, sign, exponent, fraction;
  // printf("---------   0x%0x\n", uf);
  
  // sign_mask = 0x1 << 31;
  // exp_mask = 0xFF << 23;
  // frac_mask = (0x7F << 16) + (0xFF << 8) + 0xFF;

  // exponent = uf & exp_mask;
  // fraction = uf & frac_mask;
  // sign = uf & sign_mask;

  // if(!(exponent ^ exp_mask) && !fraction){
  //   printf("NANANNANANANANA\n");
  //   return (1 << 31);
  // }
  // if(!exponent && !fraction){
  //   printf("ZROROOZORZOOZRO\n");
  //   return 0x0;
  // }
  // if(!exponent){
  //   printf("DDDDDDDDDDDDDDD\n");
  //   return 0x0;
  // }

  // // exponent = (exponent >> 1);
  // exponent = exponent >> 23;
  // exponent = exponent + ((~127) + 1);
  // printf("%d\n", exponent);

  // fraction = fraction + (1 << 23);
  // result = fraction;
  // printf("%d\n", result);

  // if(exponent & (1 << 31)){
  //   result = result >> exponent;
  // }
  // if(!(exponent & (1 << 31))){
  //   result = result << exponent;
  // }

  // result = result >> 23;

  // if(sign && result){
  //   result = (~result) + 1;
  // }
  // printf("%d\n", result);
  // return result;
  return 2;
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
 *  Max ops: 50
 *  Rating: 4
 */
int howManyBits(int x) {
  return 0;
}

