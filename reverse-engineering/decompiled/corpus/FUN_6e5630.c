/* Ghidra analysis pseudocode, not original source.
 * ev_436cabf158ac3440cfd7f7b18cfc1716350a7e3fc3c1046d0c76060bee472dbc
 * Entry: 0x6e5630; label: FUN_006e5630
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e5630(uint param_1,int param_2)

{
  if ((DAT_008282b4 != '\0') && (param_1 < 5)) {
    if (*(int *)(&DAT_0297bec0 + param_1 * 4) == param_2) {
      return;
    }
    *(int *)(&DAT_0297bec0 + param_1 * 4) = param_2;
  }
  _DAT_0297bea0 = (**(code **)(*DAT_029765cc + 0x104))(DAT_029765cc,param_1,param_2);
  return;
}

