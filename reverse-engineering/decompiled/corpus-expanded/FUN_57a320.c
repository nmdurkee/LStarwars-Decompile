/* Ghidra pseudocode, not original source.
 * ev_ce5edc1561b77c28ba497ac7e0a731ad3290827c35b207bcfcd23dc4a7952c7a
 * Entry: 0x57a320; label: FUN_0057a320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0057a320(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x2ac0);
  iVar2 = 0;
  if (0 < DAT_00951bbc) {
    do {
      if (*(short *)(iVar1 + 0xc) == param_2) {
        return iVar1;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x10;
    } while (iVar2 < DAT_00951bbc);
  }
  return 0;
}

