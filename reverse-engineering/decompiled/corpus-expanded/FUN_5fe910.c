/* Ghidra pseudocode, not original source.
 * ev_89ac6cdcf79c80fd66b36aa582044170c8ea90809525d25928dfed7b186ac36e
 * Entry: 0x5fe910; label: FUN_005fe910
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005fe910(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 extraout_ECX;
  
  uVar1 = 0;
  if (DAT_02854cd0 != 0) {
    FUN_005f7490();
    uVar1 = extraout_ECX;
  }
  DAT_02854cd0 = param_1;
  _DAT_02854cd4 = param_2;
  _DAT_0280d804 = param_3;
  _DAT_0097fa3c = param_3;
  _DAT_0097c138 = uVar1;
  _DAT_0097c1a0 = uVar1;
  _DAT_0097c1a8 = uVar1;
  FUN_005f7490();
  _DAT_02854bac = param_4;
  _DAT_028490e0 = param_4;
  return 1;
}

