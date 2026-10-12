/* Ghidra pseudocode, not original source.
 * ev_fc799924ac0d13a88507923ed5f33b35cabc605b080a1e6fd3b30e9e6a6e393b
 * Entry: 0x750310; label: FUN_00750310
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00750310(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_0080bb80;
  iVar3 = DAT_0080bb7c;
  if (-1 < DAT_0080bb7c) {
    piVar1 = (int *)(DAT_0080bb80 + 0x24 + DAT_0080bb7c * 0x28);
    *piVar1 = *piVar1 + -1;
    iVar3 = iVar2 + iVar3 * 0x28;
  }
  return iVar3;
}

