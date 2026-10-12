/* Ghidra pseudocode, not original source.
 * ev_c99ba83a21253fbea00a1b2af974464e548d813850fcca855330552d9e62c3cd
 * Entry: 0x40a520; label: FUN_0040a520
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

