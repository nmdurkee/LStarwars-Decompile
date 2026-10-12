/* Ghidra pseudocode, not original source.
 * ev_5bc2cffe930f75cca3d7b3a74e2b00ef78f9b6b1aa332ee39fd35bfa060f9fa0
 * Entry: 0x6b30c0; label: FUN_006b30c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006b30c0(void)

{
  int iVar1;
  uint in_ECX;
  
  iVar1 = 0;
  for (; in_ECX != 0; in_ECX = in_ECX >> 1) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}

