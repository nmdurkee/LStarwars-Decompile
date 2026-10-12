/* Ghidra pseudocode, not original source.
 * ev_1b30ab9bd7d518785b9e88881958deca55ff5b776c2bbdcc158b73c997cdcb1d
 * Entry: 0x5a05b0; label: FUN_005a05b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005a05b0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00552670(param_1,param_2,0x10);
  if ((iVar1 != 0) && (DAT_00956618 != 0)) {
    uVar2 = FUN_00552670(param_1,param_2,DAT_00956618 * 4);
    *(undefined4 *)(iVar1 + 0xc) = uVar2;
  }
  return iVar1;
}

