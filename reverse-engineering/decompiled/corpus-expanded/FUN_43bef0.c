/* Ghidra pseudocode, not original source.
 * ev_b0f5904faee5764ce17927395194cf9c706559b4251213f14920f3fe78cd8be0
 * Entry: 0x43bef0; label: FUN_0043bef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0043bef0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *DAT_029130e4) {
    iVar3 = 0;
    do {
      iVar1 = FUN_004f8b10(param_1,*(undefined4 *)(DAT_029130e4[8] + 0xc + iVar3));
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x4c;
    } while (iVar2 < *DAT_029130e4);
  }
  return -1;
}

