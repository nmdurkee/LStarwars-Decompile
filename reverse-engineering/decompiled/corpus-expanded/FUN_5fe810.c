/* Ghidra pseudocode, not original source.
 * ev_89ac6cdcf79c80fd66b36aa582044170c8ea90809525d25928dfed7b186ac36e
 * Entry: 0x5fe810; label: FUN_005fe810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005fe810(undefined4 param_1,uint param_2)

{
  _DAT_0080e214 = param_1;
  _DAT_0280d3dc =
       (((param_2 >> 0x18) * 0x100 + (param_2 & 0xff)) * 0x100 + (param_2 >> 8 & 0xff)) * 0x100 +
       (param_2 >> 0x10 & 0xff);
  return;
}

