/* Ghidra analysis pseudocode, not original source.
 * ev_9e834adbd1be5074ad62417c72633ab4044f13767a5707860f49455a6f85e9eb
 * Entry: 0x408800; label: FUN_00408800
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00408800(int param_1)

{
  _memset(&DAT_00854e38,0,0xf60);
  _DAT_007f1048 = _DAT_007f1038;
  _DAT_007f104c = _DAT_007f103c;
  _DAT_007f1050 = _DAT_007f1040;
  _DAT_007f1054 = _DAT_007f1044;
  if (((DAT_0087af78 != 0) && (param_1 != 0)) && (*(int *)(param_1 + 300) == DAT_0087af78)) {
    _DAT_007f1048 = 0x40800000;
    _DAT_007f1050 = 0x41200000;
    _DAT_007f1054 = 0;
  }
  return;
}

