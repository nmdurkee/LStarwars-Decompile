/* Ghidra analysis pseudocode, not original source.
 * ev_cab7855f9e60a8882d7cbeb236f16741d17a2f72b80db65c907162c694b9a361
 * Entry: 0x54c030; label: FUN_0054c030
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054c030(int param_1,int param_2,int param_3)

{
  if ((param_1 != 0) && (DAT_00921e9c != 0)) {
    DAT_00926c44 = param_1;
    if ((param_2 < 0) || (DAT_00951360 <= param_2)) {
      param_2 = -1;
    }
    *(char *)(param_1 + 0xd) = (char)param_2;
    FUN_005b45f0(&DAT_00926bd8,DAT_00802398);
    FUN_005b4f70(&DAT_00926bd8,DAT_00926c48);
    FUN_005b5160(&DAT_00926bd8,DAT_00926c4c);
    FUN_005b4900(&DAT_00926bd8,&DAT_00802384);
    if (param_3 != 0) {
      _DAT_00921eb8 = 0;
    }
  }
  return;
}

