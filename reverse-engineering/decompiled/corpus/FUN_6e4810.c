/* Ghidra analysis pseudocode, not original source.
 * ev_14516b90afd78e4126f0b3f4a370dbc2a5912f8e0102dea09dbec3c8384d0f78
 * Entry: 0x6e4810; label: FUN_006e4810
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e4810(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  if (DAT_02974d1c == 0) {
    param_2 = param_2 | 0x10;
  }
  _DAT_0297bea0 =
       (**(code **)(*DAT_029765cc + 0x68))(DAT_029765cc,param_1,param_2,param_3,param_4,param_5,0);
  return;
}

