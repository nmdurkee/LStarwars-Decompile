/* Ghidra analysis pseudocode, not original source.
 * ev_436cabf158ac3440cfd7f7b18cfc1716350a7e3fc3c1046d0c76060bee472dbc
 * Entry: 0x6e66b0; label: FUN_006e66b0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006e66b0(void)

{
  int *piVar1;
  
  _DAT_0297c17c = (int *)0x0;
  _DAT_0297c178 = 1;
  _DAT_008283e0 = DAT_02976b94;
  _DAT_008283e4 = DAT_02976b98;
  if ((DAT_02976b94 == 0x10de) && (DAT_02976b98 != -1)) {
    if (DAT_008283e8 != -1) {
      piVar1 = &DAT_008283e8;
      do {
        if (_DAT_0297c17c != (int *)0x0) {
          _DAT_0297c178 = 1;
          return 0;
        }
        if (*piVar1 == DAT_02976b98) {
          _DAT_0297c17c = piVar1;
        }
        piVar1 = piVar1 + 4;
      } while (*piVar1 != -1);
      if (_DAT_0297c17c != (int *)0x0) {
        _DAT_0297c178 = 1;
        return 0;
      }
    }
    _DAT_0297c17c = (int *)&DAT_008294a8;
  }
  return 0;
}

