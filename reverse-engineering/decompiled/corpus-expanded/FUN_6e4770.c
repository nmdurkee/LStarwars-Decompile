/* Ghidra pseudocode, not original source.
 * ev_dd1ae0888c61f8b3b50bdf9044cbfd28d34bfcecc15a6b18504d89e7aa211813
 * Entry: 0x6e4770; label: FUN_006e4770
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e4770(undefined4 param_1,undefined4 param_2)

{
  _DAT_0297bea0 = (**(code **)(*DAT_029765cc + 0x1a8))(DAT_029765cc,param_1,param_2);
  return;
}

