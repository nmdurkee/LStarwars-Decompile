/* Ghidra analysis pseudocode, not original source.
 * ev_436cabf158ac3440cfd7f7b18cfc1716350a7e3fc3c1046d0c76060bee472dbc
 * Entry: 0x6e5820; label: FUN_006e5820
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e5820(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  _DAT_0297bea0 =
       (**(code **)(*DAT_029765cc + 0x88))(DAT_029765cc,param_1,param_2,param_3,param_4,param_5);
  return;
}

