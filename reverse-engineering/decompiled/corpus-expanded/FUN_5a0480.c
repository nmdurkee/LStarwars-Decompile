/* Ghidra pseudocode, not original source.
 * ev_1b30ab9bd7d518785b9e88881958deca55ff5b776c2bbdcc158b73c997cdcb1d
 * Entry: 0x5a0480; label: FUN_005a0480
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a0480(int param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    DAT_00956614 = param_4;
    DAT_00956618 = param_3;
    DAT_0095661c = FUN_00552670(param_1,param_2,param_4 * 4);
    if ((DAT_0095661c != 0) && (iVar2 = 0, 0 < param_4)) {
      do {
        uVar1 = FUN_00552670(param_1,param_2,param_3);
        *(undefined4 *)(DAT_0095661c + iVar2 * 4) = uVar1;
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_4);
    }
  }
  return;
}

