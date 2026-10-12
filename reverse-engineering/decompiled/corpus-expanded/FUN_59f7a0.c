/* Ghidra pseudocode, not original source.
 * ev_1b30ab9bd7d518785b9e88881958deca55ff5b776c2bbdcc158b73c997cdcb1d
 * Entry: 0x59f7a0; label: FUN_0059f7a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0059f7a0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 4)) {
      iVar2 = 0;
      do {
        iVar1 = FUN_004f8b10(*(undefined4 *)(*(int *)(param_1 + 8) + 0x1c + iVar2),param_2);
        if (iVar1 == 0) {
          return iVar3 * 0x20 + *(int *)(param_1 + 8);
        }
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 0x20;
      } while (iVar3 < *(int *)(param_1 + 4));
    }
    return 0;
  }
  return 0;
}

