/* Ghidra analysis pseudocode, not original source.
 * ev_14516b90afd78e4126f0b3f4a370dbc2a5912f8e0102dea09dbec3c8384d0f78
 * Entry: 0x6e4980; label: FUN_006e4980
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e4980(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  _DAT_02974cd4 = _DAT_02974cd4 + 1;
  _DAT_0297bea0 = (**(code **)(*DAT_029765cc + 0x144))(DAT_029765cc,param_1,param_2,param_3);
  return;
}

