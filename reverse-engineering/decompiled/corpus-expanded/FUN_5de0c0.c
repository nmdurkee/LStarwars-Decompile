/* Ghidra pseudocode, not original source.
 * ev_cede8c042851d77bd106acb1edcf2aeeffc4764a47601c9bcb205898acb43edb
 * Entry: 0x5de0c0; label: FUN_005de0c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005de0c0(void)

{
  int iVar1;
  int iVar2;
  int in_EDX;
  
  iVar2 = DAT_00973ecc;
  if (DAT_00973ecc != in_EDX) {
    do {
      iVar1 = iVar2;
      iVar2 = *(int *)(iVar1 + 8);
    } while (iVar2 != in_EDX);
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar2 + 8);
      DAT_00973ec8 = DAT_00973ec8 + -1;
      return;
    }
  }
  DAT_00973ec8 = DAT_00973ec8 + -1;
  DAT_00973ecc = *(undefined4 *)(iVar2 + 8);
  return;
}

