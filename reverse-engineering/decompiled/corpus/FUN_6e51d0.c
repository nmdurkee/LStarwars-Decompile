/* Ghidra analysis pseudocode, not original source.
 * ev_14516b90afd78e4126f0b3f4a370dbc2a5912f8e0102dea09dbec3c8384d0f78
 * Entry: 0x6e51d0; label: FUN_006e51d0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e51d0(int param_1)

{
  if (DAT_008282b4 != '\0') {
    if (DAT_0297beac == param_1) {
      return;
    }
    DAT_0297beac = param_1;
  }
  _DAT_0297bea0 = (**(code **)(*DAT_029765cc + 0x1a0))(DAT_029765cc,param_1);
  return;
}

