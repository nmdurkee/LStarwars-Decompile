/* Ghidra pseudocode, not original source.
 * ev_c99ba83a21253fbea00a1b2af974464e548d813850fcca855330552d9e62c3cd
 * Entry: 0x40a4d0; label: FUN_0040a4d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0040a4d0(int param_1)

{
  int in_EAX;
  uint uVar1;
  
  uVar1 = in_EAX - param_1 & 0xffff;
  if (0x7fff < uVar1) {
    uVar1 = uVar1 - 0x10000;
  }
  return uVar1;
}

