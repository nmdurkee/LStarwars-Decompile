/* Ghidra analysis pseudocode, not original source.
 * ev_14516b90afd78e4126f0b3f4a370dbc2a5912f8e0102dea09dbec3c8384d0f78
 * Entry: 0x6e54e0; label: FUN_006e54e0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e54e0(uint param_1,int param_2,int param_3)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = DAT_008282b4 != '\0';
  (&DAT_0097f9b8)[param_1 * 2] = 0xffffffff;
  (&DAT_0097f9bc)[param_1 * 2] = 0xffffffff;
  if ((((bVar2) && (param_1 < 8)) && (param_2 < 0xe)) && (param_2 != 4)) {
    iVar1 = param_2 + param_1 * 0xe;
    if (*(int *)(&DAT_0297bed4 + iVar1 * 4) == param_3) {
      return;
    }
    *(int *)(&DAT_0297bed4 + iVar1 * 4) = param_3;
  }
  _DAT_0297bea0 = (**(code **)(*DAT_029765cc + 0x114))(DAT_029765cc,param_1,param_2,param_3);
  return;
}

