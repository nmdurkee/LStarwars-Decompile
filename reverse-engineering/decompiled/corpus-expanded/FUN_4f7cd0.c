/* Ghidra pseudocode, not original source.
 * ev_5a6bf3c2990e6ac877664f285487eca7a15ac2a0f3d7c9cff5c7bd2adfae7eea
 * Entry: 0x4f7cd0; label: FUN_004f7cd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004f7cd0(void)

{
  int iVar1;
  
  iVar1 = FUN_004f7c70();
  if (iVar1 != 0) {
    return (int)*(char *)(iVar1 + 0xd);
  }
  return -1;
}

