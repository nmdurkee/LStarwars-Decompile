/* Ghidra pseudocode, not original source.
 * ev_5bc2cffe930f75cca3d7b3a74e2b00ef78f9b6b1aa332ee39fd35bfa060f9fa0
 * Entry: 0x6b1c10; label: FUN_006b1c10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006b1c10(void)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  
  iVar1 = 0;
  if (in_ECX != 0) {
    for (uVar2 = in_ECX - 1; uVar2 != 0; uVar2 = uVar2 >> 1) {
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1;
}

