/* Ghidra pseudocode, not original source.
 * ev_80f10280a68e27d1163faa95206013e039612dceeee316e4395f60ba03bc283c
 * Entry: 0x5d15c0; label: FUN_005d15c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d15c0(int param_1,undefined4 param_2)

{
  if (DAT_009738cc < 0x10) {
    *(undefined4 *)(&DAT_0096d870 + DAT_009738cc * 4) = DAT_009738c4;
    DAT_009738cc = DAT_009738cc + 1;
  }
  DAT_009738c4 = 2;
  if ((param_1 != 0) || (param_1 = DAT_009738b8, DAT_009738b8 != 0)) {
    **(undefined4 **)(param_1 + 0x48) = param_2;
  }
  if (0 < DAT_009738cc) {
    DAT_009738c4 = *(undefined4 *)(&DAT_0096d86c + DAT_009738cc * 4);
    DAT_009738cc = DAT_009738cc + -1;
  }
  return;
}

