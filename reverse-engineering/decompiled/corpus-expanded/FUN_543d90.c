/* Ghidra pseudocode, not original source.
 * ev_c5dfc397922749c3a3d752de14fd9803558ba6adea5c02b0f86cafc5797b3dfb
 * Entry: 0x543d90; label: FUN_00543d90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00543d90(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  DAT_00924800 = 7;
  FUN_00543c30(param_1,param_2,param_3);
  DAT_00924828 = 1;
  _DAT_009246f0 = GetTickCount();
  DAT_02989558 = param_1;
  DAT_00802014 = param_1;
  return;
}

