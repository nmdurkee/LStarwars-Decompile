/* Ghidra pseudocode, not original source.
 * ev_dd1ae0888c61f8b3b50bdf9044cbfd28d34bfcecc15a6b18504d89e7aa211813
 * Entry: 0x6e4980; label: FUN_006e4980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e4980(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  _DAT_02974cd4 = _DAT_02974cd4 + 1;
  _DAT_0297bea0 = (**(code **)(*DAT_029765cc + 0x144))(DAT_029765cc,param_1,param_2,param_3);
  return;
}

