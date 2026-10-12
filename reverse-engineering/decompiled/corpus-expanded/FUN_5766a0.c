/* Ghidra pseudocode, not original source.
 * ev_b8f4d44f892ded82cd7ffb9ce06d4ee71453c0b8ed59e2b020606927ce90ab67
 * Entry: 0x5766a0; label: FUN_005766a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005766a0(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = (int)(param_1 + (param_1 >> 0x1f & 0x1fU)) >> 5;
  if (iVar2 < DAT_009514c4) {
    uVar3 = 1 << ((byte)param_1 & 0x1f);
    if (param_2 == 1) {
      puVar1 = (uint *)(DAT_009514c0 + iVar2 * 4);
      *puVar1 = *puVar1 | uVar3;
      return;
    }
    puVar1 = (uint *)(DAT_009514c0 + iVar2 * 4);
    *puVar1 = *puVar1 & ~uVar3;
  }
  return;
}

