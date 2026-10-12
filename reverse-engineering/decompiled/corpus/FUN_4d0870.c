/* Ghidra analysis pseudocode, not original source.
 * ev_9ea77467f72f0a730098339cc8760ef11d2ea4126d873e77c8bb761228bbcc9d
 * Entry: 0x4d0870; label: FUN_004d0870
 */

void FUN_004d0870(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (((param_1 != 0) && (iVar3 = *(int *)(param_1 + 0x5058), iVar3 != 0)) &&
     (iVar4 = 0, 0 < *(int *)(param_1 + 0x505c))) {
    do {
      FUN_004d0800();
      if ((param_3 != 0) && (iVar4 < 0x20)) {
        uVar2 = 1 << ((byte)iVar4 & 0x1f);
        iVar1 = (int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5;
        *(bool *)(iVar3 + 0x46) = (*(uint *)(param_3 + 4 + iVar1 * 4) & uVar2) != 0;
        *(bool *)(iVar3 + 0x47) = (*(uint *)(param_3 + iVar1 * 4) & uVar2) != 0;
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x48;
    } while (iVar4 < *(int *)(param_1 + 0x505c));
  }
  return;
}

