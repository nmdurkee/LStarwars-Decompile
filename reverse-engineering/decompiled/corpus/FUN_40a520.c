/* Ghidra analysis pseudocode, not original source.
 * ev_8c0b129907146dba16e0c839f08bc31abcfde84bb6f318465034d474a072817c
 * Entry: 0x40a520; label: FUN_0040a520
 */

float10 FUN_0040a520(void)

{
  int in_ECX;
  
  switch(DAT_00826494) {
  default:
    return (float10)1.3333334;
  case 1:
    return (float10)1.7777778;
  case 2:
    return (float10)1.6;
  case 3:
    return (float10)*(float *)(in_ECX + 0x630);
  }
}

