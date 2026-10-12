/* Ghidra analysis pseudocode, not original source.
 * ev_1492cb0b37f39299053b51444e553a69bb4676d2f076390f93a438e5515ce6e2
 * Entry: 0x6f68e0; label: FUN_006f68e0
 */

unkbyte10 FUN_006f68e0(void)

{
  float10 in_ST0;
  float10 fVar1;
  unkbyte10 Var2;
  
  fVar1 = (float10)f2xm1(-(ROUND(in_ST0) - in_ST0));
  Var2 = fscale((float10)1 + fVar1,ROUND(in_ST0));
  return Var2;
}

