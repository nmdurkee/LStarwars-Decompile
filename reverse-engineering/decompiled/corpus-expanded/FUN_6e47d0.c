/* Ghidra pseudocode, not original source.
 * ev_dd1ae0888c61f8b3b50bdf9044cbfd28d34bfcecc15a6b18504d89e7aa211813
 * Entry: 0x6e47d0; label: FUN_006e47d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e47d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  _DAT_0297bea0 =
       (**(code **)(*DAT_029765cc + 0x5c))
                 (DAT_029765cc,param_1,param_2,param_3,param_4,param_5,param_6,param_7,0);
  return;
}

