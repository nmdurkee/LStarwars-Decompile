/* Ghidra pseudocode, not original source.
 * ev_c99ba83a21253fbea00a1b2af974464e548d813850fcca855330552d9e62c3cd
 * Entry: 0x408800; label: FUN_00408800
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

