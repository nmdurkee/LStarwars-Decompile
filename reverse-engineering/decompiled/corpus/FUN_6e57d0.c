/* Ghidra analysis pseudocode, not original source.
 * ev_436cabf158ac3440cfd7f7b18cfc1716350a7e3fc3c1046d0c76060bee472dbc
 * Entry: 0x6e57d0; label: FUN_006e57d0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006e57d0(undefined4 param_1)

{
  if (DAT_029765cc != (int *)0x0) {
    FUN_006df300();
    _DAT_0297bea0 = (**(code **)(*DAT_029765cc + 0x30))(DAT_029765cc,param_1);
    FUN_006df310();
  }
  return 0;
}

