float fpwr2(int x) {
  /* Result exponent and fraction */
  unsigned exp, frac;
  unsigned u;
/* 2^x 是大于0的，正非规格化数的最小值是
0 00000000 00000...001  ==> 2^-23 * 2^(1-bias) = 2^-23 * 2^(1-(2^7 - 1))
= 2^-23 * 2^(2-2^7)) = 2^(2 - 2^7 -23) =2^( 2 - 128 - 23 )= 2^(-149)
*/
  if (x < -149) {
    /* too small. return 0.0 */
    exp = 0;
    frac = 0;
  } else if (x < 126) {
    /* Denormalized result */
    /* 求出最小的规格化数
0 00000001 00000...000
E = 1 - 2^7 + 1 = 2 - 2^7 = -126 */

    exp = 1;
    frac = 0 << ;
  } else if (x < 128) {
    /* Normalized result */
    /* 11111111 2^8 -1 - (2^7 - 1) ==> 2^8 - 2^7 -1 + 1 ==> 2^7
       exp  = E + bias = x + (2^7 - 1)
     */
    exp = 127+x;
    frac = 0;
  } else {
    /* Too big, return +oo */
    exp = 0xFF;
    frac = 0;
  }

  /* pack exp and frac into 32 bits */
  u = exp << 23 | frac;
  /* Result as float */
  return u2f(u);
}
