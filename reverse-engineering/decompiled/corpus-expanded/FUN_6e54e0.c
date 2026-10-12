/* Ghidra pseudocode, not original source.
 * ev_159ae24d072b02a6eb3bf9a5c1c2d47f096699e5cf3aac35a19c5291e20383ee
 * Entry: 0x6e54e0; label: FUN_006e54e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

