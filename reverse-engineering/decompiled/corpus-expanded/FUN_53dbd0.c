/* Ghidra pseudocode, not original source.
 * ev_65ca4a665d596d296f41bb3c37f26e684dc272ec4121c3f4d046db6dd8870575
 * Entry: 0x53dbd0; label: FUN_0053dbd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0053dbd0(void)

{
  uint in_EAX;
  int iVar1;
  uint in_ECX;
  
  iVar1 = (in_EAX & 0xffff) - (in_ECX & 0xffff);
  if (0x8000 < iVar1) {
    return iVar1 + -0x10000;
  }
  if (iVar1 < -0x8000) {
    iVar1 = iVar1 + 0x10000;
  }
  return iVar1;
}

