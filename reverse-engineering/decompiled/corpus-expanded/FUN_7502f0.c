/* Ghidra pseudocode, not original source.
 * ev_fc799924ac0d13a88507923ed5f33b35cabc605b080a1e6fd3b30e9e6a6e393b
 * Entry: 0x7502f0; label: FUN_007502f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_007502f0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_0080bb78;
  iVar3 = DAT_0080bb74;
  if (-1 < DAT_0080bb74) {
    piVar1 = (int *)(DAT_0080bb78 + 0x24 + DAT_0080bb74 * 0x28);
    *piVar1 = *piVar1 + -1;
    iVar3 = iVar2 + iVar3 * 0x28;
  }
  return iVar3;
}

