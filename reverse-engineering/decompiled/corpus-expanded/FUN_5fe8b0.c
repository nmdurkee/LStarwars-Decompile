/* Ghidra pseudocode, not original source.
 * ev_89ac6cdcf79c80fd66b36aa582044170c8ea90809525d25928dfed7b186ac36e
 * Entry: 0x5fe8b0; label: FUN_005fe8b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005fe8b0(undefined4 param_1,undefined4 param_2)

{
  if (DAT_02854cd0 != 0) {
    FUN_005f7490();
  }
  DAT_02854cd0 = param_1;
  _DAT_0280d804 = &DAT_0097fc40;
  _DAT_0097fa3c = &DAT_0097fc40;
  _DAT_0097c1a0 = &DAT_028490f0;
  _DAT_0097c1a8 = &DAT_028490f0;
  _DAT_02854cd4 = param_2;
  _DAT_0097c138 = 0;
  _DAT_02854bac = &DAT_0097fa40;
  return 1;
}

