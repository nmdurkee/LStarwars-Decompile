/* Ghidra pseudocode, not original source.
 * ev_80f10280a68e27d1163faa95206013e039612dceeee316e4395f60ba03bc283c
 * Entry: 0x5d14c0; label: FUN_005d14c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d14c0(int param_1)

{
  if (DAT_009738cc < 0x10) {
    *(undefined4 *)(&DAT_0096d870 + DAT_009738cc * 4) = DAT_009738c4;
    DAT_009738cc = DAT_009738cc + 1;
  }
  DAT_009738c4 = 2;
  if ((param_1 != 0) || (param_1 = DAT_009738b8, DAT_009738b8 != 0)) {
    _DAT_009738b4 = *(undefined4 *)(param_1 + 0x1c);
    *(undefined4 *)(param_1 + 0x20) = 1;
  }
  if (0 < DAT_009738cc) {
    DAT_009738cc = DAT_009738cc + -1;
    DAT_009738c4 = *(undefined4 *)(&DAT_0096d870 + DAT_009738cc * 4);
  }
  return;
}

